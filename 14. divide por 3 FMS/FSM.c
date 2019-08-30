
#include <stdio.h>
#include <stdlib.h>


void dividido3_FMS(int bitSize, FILE *arq) {
	
	int state, nextState, clk, r, y, i;
	clk = 1;
	state = 0;
	r = 1;
	char *str1, *str2;
	
	fprintf(arq,"10_1\n");
	fprintf(arq,"11_1\n");
	
	for(r = 0; r < 2; r++) {
		for(i = 0 ; i < 6; i++) {
			clk = !clk;
			
			nextState = r ? 0 : (clk ? (state+1)%3 : state);
			y = (nextState == 0) ?  1 : 0;
			
			fprintf(arq,"%d%d_%d\n", r,clk, y);
			
			state = nextState;
		}
	}
	
}

int main() {
	FILE *arq;
	arq = fopen("dividido3_FSM.tv", "w");
	
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -1;
	}
	
	dividido3_FMS(4, arq);
	
	fclose(arq);
	return 0;
}
