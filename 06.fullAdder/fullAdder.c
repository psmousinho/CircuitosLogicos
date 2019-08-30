#include <stdio.h>
#include <stdlib.h>

void fullAdder(FILE *arq) {
	int a, b, cin;
	int s, soma, cout;
	
	for( a =0; a < 2; a++) {
		for( b =0; b < 2; b++){
			for( cin =0; cin < 2; cin++) {
				soma = a + b +cin;
				s = soma & 1;
				
				if( soma > 1)
					cout = 1;
				else
					cout = 0;
				
				fprintf(arq, "%d%d%d_%d_%d\n", a,b,cin,s,cout);
			}
		}
	}
	
}

int main() {
	FILE *arq;
	arq = fopen("fullAdder.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	fullAdder(arq);
	
	fclose(arq);
	return 0;
}
