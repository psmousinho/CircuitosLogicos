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

void somador(FILE *arq) {
	int a, b, cin;
	int soma, cout;
	char *str1, *str2, *res;
	
	
	for( a = 0; a < 16; a += 4) {
		for( b =0; b < 16;  b+= 5){
			for( cin = 0; cin < 2; cin++) {
				
				soma = a + b + cin;
				cout = soma>>4;
				cout = cout & 1;
				
				str1 = toBinary(4, a);
				str2 = toBinary(4, b);
				res  = toBinary(4, soma);				
				
				fprintf(arq, "%s%s%d_%s_%d\n", str1,str2,cin,res,cout);
			}
		}
	}
	
}

int main() {
	FILE *arq;
	arq = fopen("somador_4bit_VUA.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	somador(arq);
	
	fclose(arq);
	return 0;
}
