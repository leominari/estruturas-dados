#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
  int chave;
  struct fila* prox;
}fila;

fila* novo(int chave){
  fila *n = NULL;
  while(n == NULL)
    n = malloc(sizeof(fila));
  n->chave = chave;
  n->prox = NULL;
  return n;
}

void insere_fim(fila** prim, int chave){
  if((*prim) == NULL){
    *prim = novo(chave);
    return;
  }
  else
    insere_fim(&((*prim)->prox), chave);
}

 fila** busca_pai(fila** prim, int chave){
   if((*prim) != NULL)
    if((*prim)->chave == chave)
      return &(*prim);
    else
      return busca_pai(&((*prim)->prox), chave);
}

void remove_busca(fila** prim, int chave){
  fila** pai = busca_pai(prim, chave);
  fila* aux = *pai;
  *pai = (*pai)->prox;
  free(aux);
}

void remove_comeco(fila** prim){
  fila* aux = *prim;
  *prim = (*prim)->prox;
  free(aux);
}

void leitura(fila* prim){
  if(prim == NULL)
    return;

  else{
    printf("%d\n", prim->chave);
    leitura(prim->prox);
  }
}

void main(){
  fila* cu = NULL;
  fila* x;
  insere_fim(&cu, 1);
  insere_fim(&cu, 2);
  insere_fim(&cu, 3);
  insere_fim(&cu, 4);
  insere_fim(&cu, 5);
  printf("Inseriu\n");
  leitura(cu);
  remove_comeco(&cu);
  printf("Removeu Começo\n");
  leitura(cu);
  remove_busca(&cu, 4);
  printf("Buscou e removeu\n");
  leitura(cu);
}
