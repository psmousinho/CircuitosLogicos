
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

void regDesl(int bitSize, FILE *arq) {
	
	int sin, sout, d, q;
	int rst, clk, clka, load;
	char *str1, *str2;
	int i;
	
	d = 180;
	sin = 0;
	clk = clka = 0;
	
	//entrada paralela
	load = 1;
	for(rst = 1; rst >= 0; rst--) {
		for(clk = 0; clk < 2; clk++) {
			
			
			q = rst ?  0 : (clk && !clka ?  (load ? d : (q << bitSize-1) +sin) : q );
			sout = (q>>bitSize-1) & 1;
			
			str1 = toBinary(8,d);
			str2 = toBinary(8,q);
			fprintf(arq,"%d%d%d%d_%s_%s_%d\n",rst,clk,load,sin,str1,str2, sout);
			
			clka = clk;
		}
	}
	
	// shift a esquerda
	clk = clka = load = rst = 0;
	for(i = 0; i < 8; i++) {
		for(clk = 0; clk < 2; clk++) {
			
			
			q = rst ?  0 : (clk && !clka ?  (load ? d : (q << 1) +sin) : q );
			sout = (q>>bitSize-1) & 1;
			
			str1 = toBinary(8,d);
			str2 = toBinary(8,q);
			fprintf(arq,"%d%d%d%d_%s_%s_%d\n",rst,clk,load,sin,str1,str2, sout);
			
			clka = clk;
		}
	}
	
	// entrada sequencial
	clk = clka = load = rst = 0;
	for(i = 1; i < 9; i++) {
		for(clk = 0; clk < 2; clk++) {
			
			sin = 180 >> bitSize - i ;
			sin = sin & 1;
			
			q = rst ?  0 : (clk && !clka ?  (load ? d : (q << 1) +sin) : q );
			sout = (q>>bitSize-1) & 1;
			
			str1 = toBinary(8,d);
			str2 = toBinary(8,q);
			fprintf(arq,"%d%d%d%d_%s_%s_%d\n",rst,clk,load,sin,str1,str2, sout);
			
			clka = clk;
		}
	}
	
	
}

int main() {
	FILE *arq;
	arq = fopen("regDesloc.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	regDesl(8 ,arq);
	
	fclose(arq);
	return 0;
}
