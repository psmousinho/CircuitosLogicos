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


void flipflopD_ERA(int bitSize, FILE *arq) {
	int clk;
	int clka = -15;
	int  en, d, q, r = 0;
	char *str1, *str2;
	
	for(en=1; en>=0;en--){
		for( r = 0; r < 2; r++ ) {
			for( d = 0; d < 16 ; d+= 15) {
				if(r == 1) {
					d = 15;
				}
				for(clk = 0; clk < 2; clk++) {
					
					if(r == 1) {
						q = 0;
					}
					else if(clk && clka == 0 && en) {
							q = d;
					}
					
					fprintf(arq, "%d", en);
					
					fprintf(arq, "%d", r);
					
					fprintf(arq, "%d_", clk);
					
					str1 = toBinary(bitSize, d);
					fprintf(arq,"%s_", str1);
					
				
					str2 = toBinary(bitSize, q);
					(clk == 0 && clka == -15) ? fprintf(arq,"xxxx") : fprintf(arq, str2);
					fprintf(arq, "\n");
					clka = clk;
				}
			}
		}
	}	
}

int main() {
	FILE *arq;
	arq = fopen("flipflopD_ERA.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	flipflopD_ERA(4, arq);
	
	fclose(arq);
	return 0;
}

