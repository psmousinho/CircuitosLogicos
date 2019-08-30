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

void tristate(int bitSize, FILE *arq) {
	int a, en, y;
	char *str;

	for( a = 0; a < 16; a+= 15) {
		for( en = 0; en < 2; en++){
				str = toBinary(bitSize, a);
				
				fprintf(arq, "%d%s_", en, str);
				en ? fprintf(arq, "%s\n", str) : fprintf(arq, "zzzz\n");
			}
		}
	}

int main() {
	FILE *arq;
	arq = fopen("tristate.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	tristate(4, arq);
	
	fclose(arq);
	return 0;
}
