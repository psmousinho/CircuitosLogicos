#include<stdio.h>
#include <stdlib.h>

void bitSum(int* bits, int pos) {
	if(bits[pos] == 0) {
		bits[pos] = 1;
	} else {
		bits[pos] = 0;
		bitSum( bits, pos-1);
	}
}

int main(int argc, char** argv){
	FILE *arq;
	arq = fopen("sillyfunction.tv","w");
	
	int *ptr;
	ptr = (int *) calloc(3, sizeof(int));
	
	
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
	
		int i;
		for(i = 0 ; i < 8; i++) {
			fprintf(arq,"%d%d%d_%d\n",ptr[0],ptr[1],ptr[2],
									(!ptr[0]&&!ptr[1]&&!ptr[2]) || (ptr[0]&&!ptr[1]&&!ptr[2]) || (ptr[0]&&!ptr[1]&&ptr[2]));
			
			bitSum(ptr, 2);
		}

		fclose(arq);
	}
	return 0;
}




	
	
	
	
	
	



