#include <stdio.h>
#include <stdlib.h>

char *toBinary(int bitSize, int num) {
	int shift, aux, pos;
	char *str = (char*) malloc(bitSize+1);
	
	for(shift = bitSize - 1, pos = 0; shift >= 0; shift--, pos++) {
		aux = num >> shift;

		if(aux & 1) 
			*(str+pos) = '1';		
		else
			*(str+pos) = '0';  
				
	}
	
	*(str+pos) = '\0';
	
	return str;
}

void muxTwoOne(int bitSize, FILE *arq) {
	char *str1, *str2;
	int a , b, enable;
	
	for(a = 0; a < 16; a += 15) {
		b = ~ a;
		
		for(enable = 0; enable < 2; enable++) {
			str1 = toBinary(bitSize, a);
			fprintf(arq, "%s", str1);
			
			str2 = toBinary(bitSize, b);
			fprintf(arq, "%s", str2);
				
			fprintf(arq,"%d", enable);
				
			enable ? fprintf(arq,"_%s\n", str2) : fprintf(arq,"_%s\n", str1);
		}
	}
}

int main() {
	FILE *arq;
	arq = fopen("muxTwoOne.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	muxTwoOne(4, arq);
	
	fclose(arq);
	return 0;
}
