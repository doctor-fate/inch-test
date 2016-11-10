
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fr;
	char str_in[50];			
	char str_out[50];			
	char let_code[26][52];		
	const int str_len = 52;		
	gets(str_in);
	fr = fopen ("osninf-lab5-code.txt", "rt");
	fgets(let_code[0], str_len, fr);
	if(atoi(let_code[0]) > 26)
		printf("\nNumber leters in file <= 26");
	else{
		int i = 1;	
		while(!feof(fr)){ 
			fgets(let_code[i], str_len, fr);
			if(atoi(let_code[0]) != i)
				let_code[i][strlen(let_code[i]) - 2] = '\0';
			else
				let_code[i][strlen(let_code[i]) - 1] = '\0';
			i++;
		}
		i = 1;	
		int j = 1, l = 1, size = strlen(str_in) + 1;
		int f = 1;
		char s[52];		
		strcpy(str_out, "\0");
		for(i = 1; i < size && f == 1; i++){
			strcpy(s, &str_in[0]);
			s[l++] = '\0';
			for(j = 1; j <= atoi(let_code[0]); j++){
				if(strcmp(&let_code[j][2],s) == 0){
					int k, m;
					for(k = 0; k < strlen(s); k++)
						for(m = 0; m < strlen(str_in); m++)
							str_in[m] = str_in[m + 1];	
					char t[2];
					t[0] = let_code[j][0];			
					t[1] = '\0';					
					strcat(str_out, &t[0]);			
					j = atoi(let_code[0]);			
					l = 1;							
				}
			}
		}
		if(strcmp(str_in, "") == 0)
			printf("%s", &str_out);
		else
			printf("BADINPUT");
	}
	fclose(fr);
	gets(str_in);
}