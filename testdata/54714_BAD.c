#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
 
long m = 0;
 
struct Node{
        int v;
	char * label;
	struct Node * parent;
	struct Node ** arcs;};


struct el{
	struct Node * x;
	int i;};



struct Node * InitCompactTrie(){
	return NULL;}

struct Node * InitNewNode(struct Node * t){
	t = calloc(1, sizeof(struct Node));
	(*t).v = 0;
	(*t).label =  calloc(200, sizeof(char));
	(*t).label[0] = '\0';
	(*t).parent = NULL;
	(*t).arcs =  calloc(100, sizeof(struct Node *));
	for (int i = 0; i < 100; i++)
		(*t).arcs[i] = NULL;
	return t;}

int MapEmpty(struct Node * t){
	return t == NULL;}

struct el * Descend(struct Node * t, char * k, int * i){
	struct el * pos = calloc(1, sizeof(struct el));
	int s = (int)strlen(k);
	struct Node * y;
	char l[200];
	(*pos).x = t;
	(*pos).i = 0;
	(*i) = 0;
	while (1 == 1){
		l[0] = '\0';
		strcpy(l, (*((*pos).x)).label);
		//printf("LLLLL %s %s\n", l, k); 
		while (((*i) < s) && ((*pos).i < (int)strlen(l)) && (k[(*i)] == l[(*pos).i])){
			//printf("%c %C HEH\n",k[(*i)], l[(*pos).i]);			
			(*i)++;
			(*pos).i++;}
		//printf("%c %C HEHEH\n",k[(*i)], l[(*pos).i]);
		if (((*i) == s) || ((*pos).i != (int)strlen((*((*pos).x)).label)))
			break;
		y = (*((*pos).x)).arcs[((int)k[(*i)] - (int)'a')];
		if (y == NULL)
			break; 
		(*pos).x = y;
		(*pos).i = 0;}
	return pos;}

struct Node * DescendToLeaf(struct Node * t, char * k){
	if (t == NULL)
		return NULL;
	int i = 0;
	struct el * pos = Descend(t, k, &i);
	if ((i != (int)strlen(k)) || ((*pos).i != (int)strlen((*((*pos).x)).label)) || ((*((*pos).x)).v != 0)){
		free(pos);
		return NULL;}
	struct Node * r = (*pos).x;
	free(pos);
	return r;}

struct Node * Lookup(struct Node * t, char * k){
	struct Node * x = DescendToLeaf(t, k);
	return x;}

struct Node * Link (struct Node * t, struct Node * parent, struct Node * child){
	(*child).parent = parent;
	if (parent == NULL)
		t = child;
	else
		(*parent).arcs[(int)(*child).label[0] - (int)'a'] =  child;
	return t;}

struct Node * Split(struct Node * t,struct el * pos, int key){
	char l[200];
	int i = 0;
	strcpy(l, (*((*pos).x)).label);
	if ((*pos).i < (int)strlen(l)){
		struct Node * y;
		y = InitNewNode(y);
		(*y).v = key;
		//printf(" v'=%d ", (*y).v );
		strncpy((*y).label, l, (*pos).i);
		for (i = 0; i < (int)strlen(l) - (*pos).i; i++)
			(*((*pos).x)).label[i] = l[(*pos).i + i];
		(*((*pos).x)).label[i] = '\0';
		t = Link(t, (*((*pos).x)).parent, y);
		t = Link(t, y, (*pos).x);
		//free((*((*pos).x)).label);
		//free((*((*pos).x)).arcs);
		//free((*pos).x);
		(*pos).x = y;}
	return t;}

struct Node * Insert(struct Node * t, char * k, int v){
	//printf("HELL\n");
	//struct Node * p = Lookup(t, k);
	//printf("HELL!\n");
	//if (p != NULL)
	//	printf("NOT LOL");
	//else
	//	printf("LOL\n");
	int i = 0, j = 0, key = 0;
	struct el * pos = NULL;
	struct Node * x;
	x = InitNewNode(x);
	(*x).v = 1;
	//if (p != NULL)
	//	(*p).v = 1;
	//else{
		if (t == NULL){
			strcpy((*x).label, k);
			t = x;}
		else{
			pos = Descend(t, k, &i);
			//printf("lal %d %s \n",(*pos).i,  (*((*pos).x)).label);
			//printf("%d !!! \n", i);
			if (i == (int)strlen(k)) key = 1; 
			t = Split(t, pos, key);
			if (key != 1){
			for (j = 0; i < (int)strlen(k) - j; j++)
				(*x).label[j] = k[i + j];
			(*x).label[j] = '\0';
			t = Link(t, (*pos).x, x);}
			else{
				free((*x).label);
				free((*x).arcs);
				free(x);}
			free(pos);}
	return t;}

int Count(struct Node * t){
	int sum = 0;
	sum += (*t).v;
	for (int j = 0; j < 100; j++)
		if ((*t).arcs[j] != NULL)
			sum +=Count((*t).arcs[j]);
	return sum;}

int Prefix(struct Node * t, char * k){
	int i = 0, sum = 1;
	struct el * pos = NULL;
	pos = Descend(t, k, &i);
	//printf("lal %d %s \n",(*pos).i,  (*((*pos).x)).label);
	if (i == strlen(k)){
		if ((*pos).i != strlen((*((*pos).x)).label))
			sum = 1;
		else
			sum = Count((*pos).x);
		free(pos);
		return sum;}
	else{
		free(pos);
		return 0;}}


struct Node * Delete(struct Node * t, char * k){
	struct Node * x = DescendToLeaf(t, k);
	struct el * pos;
	if (x == NULL){
		int q = 0;
		pos = Descend(t, k, &q);
		(*((*pos).x)).v = 0;
		free(pos);}
	else{	
	char l[200], h[200];
	strcpy(l, (*x).label);
	struct Node * y = (*x).parent;
	free((*x).label);
	free((*x).arcs);
	free(x);
	if (y == NULL)
		t = NULL;
	else{
		(*y).arcs[(int)l[0] - (int)'a'] = NULL;
		struct Node * z = NULL;
		int i = 0;
		while (i < 100){
			if ((*y).arcs[i] != NULL){
				if (z != NULL) return t;
				z =  (*y).arcs[i];}
			i++;}
		strcpy(h, (*y).label);
		strcat(h, (*z).label);
		strcpy((*z).label, h);
		t = Link(t, (*y).parent, z);
		free((*y).label);
		free((*y).arcs);
		free(y);}}
	return t;}


void Printtrie(struct Node * t, int i){
	if (t != NULL){
	printf("%d v=%d %s TRIE\n", i, (*t).v, (*t).label);
	for (int j = 0; j < 100; j++)
		if ((*t).arcs[j] != NULL)
			Printtrie((*t).arcs[j], i+1);}}
void Destroy(struct Node * t){
	for (int j = 0; j < 100; j++)
		if ((*t).arcs[j] != NULL)
			Destroy((*t).arcs[j]);
	//printf("s = %s\n",(*t).label);
	free((*t).label);
	free((*t).arcs);
	free(t);}

int main()
{
long n;
char str[20], str2[200];
struct Node * t = InitCompactTrie();
scanf("%ld", &n);
for(long i = 0; i<n; i++){
        scanf("%s", str);
	scanf("%s", str2);
         if ((str[0] == 'I') && (str[1] == 'N')) {
                t= Insert(t, str2, 1);}
		//Printtrie(t, 0);
		//printf("\n");}
        else if ((str[0] == 'D') && (str[1] == 'E')){
                t= Delete(t, str2);}
		//Printtrie(t, 0);
		//printf("\n");}
		//printf("%s !!! \n", (*t).label);}
	else if ((str[0] == 'P') && (str[1] == 'R')){
                printf("%d\n", Prefix(t, str2));}}
Destroy(t);
}