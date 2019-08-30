#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
void Inv(int btsize, FILE *arq) {
	int i;
	char *str1, *resultado;
	
	for(i = 0; i < pow(2, btsize); i++) {
		int j = ~i;
		str1 = toBinary(btsize, i);
		resultado =toBinary(btsize, j);
		fprintf(arq, "%s_%s\n", str1, resultado); 
	}
}

void And(int btSize, FILE *arq) {
	int i, j, aux;
	char *str1, *str2, *resultado;
	
	for(i = 0; i < pow(2, btSize); i++) {
		for(j = 0; j < pow(2, btSize); j++) {
			aux = i & j;
			str1 = toBinary(btSize, i);
			str2 = toBinary(btSize, j);
			resultado = toBinary(btSize, aux);
			fprintf(arq, "%s%s_%s\n", str1, str2, resultado);
		}
	}
}

void Or(int btSize, FILE *arq) {
	int i, j, aux;
	char *str1, *str2, *resultado;
	
	for(i = 0; i < pow(2, btSize); i++) {
		for(j = 0; j < pow(2, btSize); j++) {
			aux = i | j;
			str1 = toBinary(btSize, i);
			str2 = toBinary(btSize, j);
			resultado = toBinary(btSize, aux);
			fprintf(arq, "%s%s_%s\n", str1, str2, resultado);
		}
	}
}

void Nand(int btSize, FILE *arq) {
	int i, j, aux;
	char *str1, *str2, *resultado;
	
	for(i = 0; i < pow(2, btSize); i++) {
		for(j = 0; j < pow(2, btSize); j++) {
			aux = ~(i & j);
			str1 = toBinary(btSize, i);
			str2 = toBinary(btSize, j);
			resultado = toBinary(btSize, aux);
			fprintf(arq, "%s%s_%s\n", str1, str2, resultado);
		}
	}
}

void Nor(int btSize, FILE *arq) {
	int i, j, aux;
	char *str1, *str2, *resultado;
	
	for(i = 0; i < pow(2, btSize); i++) {
		for(j = 0; j < pow(2, btSize); j++) {
			aux = ~(i | j);
			str1 = toBinary(btSize, i);
			str2 = toBinary(btSize, j);
			resultado = toBinary(btSize, aux);
			fprintf(arq, "%s%s_%s\n", str1, str2, resultado);
		}
	}
}

void Xor(int btSize, FILE *arq) {
	int i, j, aux;
	char *str1, *str2, *resultado;
	
	for(i = 0; i < pow(2, btSize); i++) {
		for(j = 0; j < pow(2, btSize); j++) {
			aux = i ^ j;
			str1 = toBinary(btSize, i);
			str2 = toBinary(btSize, j);
			resultado = toBinary(btSize, aux);
			fprintf(arq, "%s%s_%s\n", str1, str2, resultado);
		}
	}
}*/

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

void Gates(int bitSize, FILE *arq) {
	char *str;
	int i , j,aux;
	
	for(i = 0; i <= 15; i += 15) {
		for (j = 0 ; j <= 15; j+= 15) {
			str = toBinary(bitSize, i);
			fprintf(arq, "%s", str);
			
			str = toBinary(bitSize, j);
			fprintf(arq, "%s", str);
			
			aux = i & j;
			str = toBinary(bitSize, aux);
			fprintf(arq, "_%s", str);
			
			aux = i | j;
			str = toBinary(bitSize, aux);
			fprintf(arq, "_%s", str);
			
			aux = i ^ j;
			str = toBinary(bitSize, aux);
			fprintf(arq, "_%s", str);
			
			aux = ~(i & j);
			str = toBinary(bitSize, aux);
			fprintf(arq, "_%s", str);
			
			aux = ~(i | j);
			str = toBinary(bitSize, aux);
			fprintf(arq, "_%s\n", str);
		}
	}
	
}

int main() {
	FILE *arq;
	arq = fopen("gates.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	Gates(4, arq);
	
	fclose(arq);
	return 0;
}
