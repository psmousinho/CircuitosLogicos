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

void flipflopD(int bitSize, FILE *arq) {
	int clk;
	int clka = -15;
	int d, q;
	char *str1, *str2;
	
	
	for(d = 0; d < 31; d+=15) {
		for(clk = 0; clk < 2; clk++) {
			if(clk == 1 && clka == 0) {
				q = d;
			}
			
			str1 = toBinary(bitSize, d%30);
			fprintf(arq, str1);
			
			fprintf(arq, "%d_", clk);
			
			str2 = toBinary(bitSize, q%30);
			(clk == 0 && clka == -15) ? fprintf(arq,"xxxx") : fprintf(arq, str2);
			fprintf(arq, "\n");
			clka = clk;
			
		}
	}
	
}

int main() {
	FILE *arq;
	arq = fopen("flipflopD.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	flipflopD(4, arq);
	
	fclose(arq);
	return 0;
}



