#include <stdio.h>
#include <stdlib.h>

typedef struct dupla{
  int chave;
  struct dupla* ant;
  struct dupla* prox;
}dupla;


dupla* novo(int chave){
  dupla *n = NULL;
  while(n == NULL)
    n = malloc(sizeof(dupla));
  n->chave = chave;
  n->prox = NULL;
  n->ant = NULL;
  return n;
}

void insere_fim(dupla** prim, int chave){
  if((*prim) == NULL){
    *prim = novo(chave);
    return;
  }
  else
    insere_fim(&((*prim)->prox), chave);
}

void insere_comeco(dupla** prim, int chave){
  dupla* aux = (*prim);
  (*prim) = novo(chave);
  (*prim)->prox = aux;
}

 dupla** busca_pai(dupla** prim, int chave){
   if((*prim) != NULL)
    if((*prim)->chave == chave)
      return &(*prim);
    else
      return busca_pai(&((*prim)->prox), chave);
}

void remove_busca(dupla** prim, int chave){
  dupla** pai = busca_pai(prim, chave);
  dupla* aux = *pai;
  *pai = (*pai)->prox;
  free(aux);
}

void remove_comeco(dupla** prim){
  dupla* aux = *prim;
  *prim = (*prim)->prox;
  free(aux);
}

void leitura(dupla* prim){
  if(prim == NULL)
    return;

  else{
    printf("%d\n", prim->chave);
    leitura(prim->prox);
  }
}

void main(){
  dupla* cu = NULL;
  dupla* x;
  insere_comeco(&cu, 1);
  insere_comeco(&cu, 2);
  insere_comeco(&cu, 3);
  insere_comeco(&cu, 4);
  insere_comeco(&cu, 5);
  printf("Inseriu\n");
  leitura(cu);
  remove_comeco(&cu);
  printf("Removeu Começo\n");
  leitura(cu);
  remove_busca(&cu, 4);
  printf("Buscou e removeu\n");
  leitura(cu);
}
