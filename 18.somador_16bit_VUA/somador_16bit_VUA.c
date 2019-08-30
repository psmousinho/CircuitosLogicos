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

void somador16(int bitSize,FILE *arq) {
	int a = 0xFFFF , b = 0xFFFF, cin;
	int soma, cout;
	char *str1, *str2, *res;
	int i,j;
	
	for(i = 0; i <2; i++) {
		if(i%2 == 1) a = 0xFFFF;
		else a = 0x0000;
		for(j = 0; j < 2; j++) {
			if(j%2 == 1) b = 0xFFFF;
			else b = 0x0000;
			
			for(cin = 0; cin < 2; cin++) {
				soma = a + b + cin;
				
				cout = soma>>bitSize;
				cout = cout & 1;
				
				str1 = toBinary(bitSize, a);
				str2 = toBinary(bitSize, b);
				res  = toBinary(bitSize, soma);				
					
				fprintf(arq, "%s_%s_%d_%s_%d\n", str1,str2,cin,res,cout);
			
			}  
		}
	}
		
	
}

int main() {
	FILE *arq;
	arq = fopen("somador_16bit_VUA.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	somador16(16,arq);
	
	fclose(arq);
	return 0;
}
