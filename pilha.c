#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
  int chave;
  struct pilha* prox;
}pilha;

pilha* novo(int chave){
  pilha *n = NULL;
  while(n == NULL)
    n = malloc(sizeof(pilha));
  n->chave = chave;
  n->prox = NULL;
  return n;
}

void insere_comeco(pilha** prim, int chave){
  pilha* aux = (*prim);
  (*prim) = novo(chave);
  (*prim)->prox = aux;
}

 pilha** busca_pai(pilha** prim, int chave){
   if((*prim) != NULL)
    if((*prim)->chave == chave)
      return &(*prim);
    else
      return busca_pai(&((*prim)->prox), chave);
}

void remove_busca(pilha** prim, int chave){
  pilha** pai = busca_pai(prim, chave);
  pilha* aux = *pai;
  *pai = (*pai)->prox;
  free(aux);
}

void remove_comeco(pilha** prim){
  pilha* aux = *prim;
  *prim = (*prim)->prox;
  free(aux);
}

void leitura(pilha* prim){
  if(prim == NULL)
    return;

  else{
    printf("%d\n", prim->chave);
    leitura(prim->prox);
  }
}

void main(){
  pilha* cu = NULL;
  pilha* x;
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
