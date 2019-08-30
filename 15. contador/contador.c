
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void contador(int bitSize, int precisao, FILE *arq) {
	
	int i;
	int clk, clka, q, r;
	char *str;
	
	for(i = 0; i < pow(2, bitSize); i+= precisao) {
		for(clk = 0; clk < 2; clk++) {
			
			r = (i%128 == 0) ? 1 : 0;
				
			q = r ? 0 : (clk == 1 && clka == 0) ? q+1 : q;
			
			str = toBinary(bitSize, q);
			fprintf(arq, "%d%d_%s\n", r,clk,str);
			
			clka = clk;
		}
	} 
	
}

int main() {
	FILE *arq;
	arq = fopen("contador.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	contador(8, 16 ,arq);
	
	fclose(arq);
	return 0;
}
