/*
 * main.c
 *
 *  Created on: 26 нояб. 2015 г.
 *      Author: root
 */

#include <pcap.h>
#include <string.h>
#include <ctype.h>
#include <netinet/tcp.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

void print_char(int c) {
	if (isprint(c) || c == '\n' || c == '\r')
		printf("%c", c);
	else
		printf("*");
}
void print_char_err(int c) {
	if (isprint(c) || c == '\n' || c == '\r')
		fprintf(stderr, "%c", c);
	else
		fprintf(stderr, "*");
}

void process_packet(u_char *arg, const struct pcap_pkthdr *pkthdr,
		const u_char *packet) {
//	struct ether_header *eh;
	struct iphdr *ih;
	struct tcphdr *th;
	char *payload;
	int ehlen = ETH_HLEN, ihlen, thlen, payloadlen;
//	eh = (struct ether_header *) packet;
	ih = (struct iphdr *) (packet + ehlen);
	ihlen = ih->ihl * 4;
	if (ihlen < 20)
		return;
	th = (struct tcphdr *) (packet + ehlen + ihlen);
	thlen = th->th_off * 4;
	if (thlen < 20)
		return;
	payload = (char *) (packet + ehlen + ihlen + thlen - 10);
	payloadlen = pkthdr->len - (ehlen + ihlen + thlen - 10);
	if (payloadlen < 0)
		return;
	if (strncmp(payload, "POST", 4) != 0)
		return;
//	printf("%d %d %d %d %d %u\n", ehlen, ihlen, thlen, payloadlen, pkthdr->len,
//			ntohs(eh->ether_type));
//	for (int i = 0; i < payloadlen; i++)
//		print_char(payload[i]);
	for(int i = 0; i < pkthdr->len; i++)
		print_char_err(packet[i]);
	print_char_err('\n');
	char *s = strtok(payload, "\n");
	char *host, *content_type, *content;
	do {
		if(strncmp(s, "Host", 4) == 0)
			host = s;
		else if(strncmp(s, "Content-Type", 12) == 0)
			content_type = s;
		else if(strncmp(s, "Content-Length", 14) == 0) {
			s = strtok(NULL, "\n");
			if(s == NULL)
				return;
			s = strtok(NULL, "\n");
			if(s == NULL)
				return;
			content = s;
		}
	} while ((s = strtok(NULL, "\n")) != NULL);
	if(strncmp(content_type + 14, "application/x-www-form-urlencoded", 33) != 0)
		return;
	printf("%s\n%s\n", host, content_type);
	int cntlen = (((void*)packet + pkthdr->len) - (void*)content);
	if(cntlen == 0)
		return;
	char cnt[cntlen + 1];
	memcpy(cnt, content, cntlen);
	cnt[cntlen] = '\0';
	s = strtok(cnt, "&");
	do {
		printf("%s\n", s);
	} while((s = strtok(NULL, "&")) != 0);
	printf("-----\n");
	fflush(stdout);
}

int main() {
	pcap_t *descr;
	char errbuf[PCAP_ERRBUF_SIZE];
	char *device = 0;
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);
	struct bpf_program filter;
	unsigned int mask;
	unsigned int addr;

//	device = pcap_lookupdev(errbuf);
	device = "any";
	printf("Opened device %s\n", device);
	descr = pcap_open_live(device, BUFSIZ, 1, 512, errbuf);
	if (descr == NULL)
		return 1;
	pcap_lookupnet(device, &addr, &mask, errbuf);
	pcap_activate(descr);
	pcap_compile(descr, &filter, "tcp port 80", 1, mask);
	pcap_setfilter(descr, &filter);
	pcap_loop(descr, -1, process_packet, NULL);
	pcap_freecode(&filter);
	pcap_close(descr);
	return 0;
}