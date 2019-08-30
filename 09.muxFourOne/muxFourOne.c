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

void muxFourOne(int bitSize, FILE *arq) {
	char *str1, *str2, *str3, *str4;
	int i ,s0, s1, entrada[4] = {0,0,0,0};
	
	for(i = 0; i < 4; i++) {
		for(entrada[i] = 0; entrada[i] < 16; entrada[i] += 15) {
			entrada[(i + 1) % 4] = ~ entrada[i];
			entrada[(i + 2) % 4] = ~ entrada[i];
			entrada[(i + 3) % 4] = ~ entrada[i];
			
			s1 = i/2;
			s0 = i%2;
						
			str1 = toBinary(bitSize, entrada[0]);
			fprintf(arq, "%s", str1);
								
			str2 = toBinary(bitSize, entrada[1]);
			fprintf(arq, "%s", str2);
								
			str3 = toBinary(bitSize, entrada[2]);
			fprintf(arq, "%s", str3);
								
			str4 = toBinary(bitSize, entrada[3]);
			fprintf(arq, "%s", str4);
							
			fprintf(arq,"%d", s1);
			fprintf(arq,"%d", s0);
			s1 ? s0 ? fprintf(arq,"_%s\n", str4) : fprintf(arq,"_%s\n", str3) : s0 ? fprintf(arq,"_%s\n", str2) : fprintf(arq,"_%s\n", str1) ;	
									
		}	
	}
	
}

int main() {
	FILE *arq;
	arq = fopen("muxFourOne.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	muxFourOne(4, arq);
	
	fclose(arq);
	return 0;
}
