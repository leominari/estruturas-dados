#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int j, int k){
	int i,x; //contadores
	int** m = NULL;
	while(m == NULL) //Se não consegue alocar fica tentando até alocar
		m =  malloc(k * sizeof(int*)); //Precisa do Cast pra nao dar erro
	for(i=0;i<k;i++){
		while(m[i] == NULL) //Se não consegue alocas fica tentanto até alocar
			m[i] =  malloc(j * sizeof(int)); //Precisa do Cast pra nao dar erro
		for(x=0; x<j; x++)
			m[i][x] = 0; //Coloca 0 porq era lixo
	}
	return m; //retorna um ponteiro de ponteiro
}




void main(){
	int** matriz = NULL;
	int i,x,j,k;
	printf("Tamanho do vetor?(Linhas)\n");
	scanf("%d",&k);
	printf("Quantos Subvetores(Colunas)?\n");
	scanf("%d",&j);
	matriz = aloca_matriz(j, k);
  for(i=0; i<k; i++)
    for(x=0; x<j; x++){
      matriz[i][x] = i+x;
    }
  for(i=0; i<k; i++)
    for(x=0; x<j; x++){
      printf("m[%d][%d] = %d\n", i, x, matriz[i][x]);
    }

}
