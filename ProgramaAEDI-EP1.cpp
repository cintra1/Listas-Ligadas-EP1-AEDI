#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("14597677");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Mateus Freitas Cintra");
}

// elemento da lista
typedef struct estr {
        int chave;
        struct estr* prox;
} NO;


// funcao principal
void removerCompartilhados(NO* *p1, NO* *p2);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
void removerCompartilhados(NO* *p1, NO* *p2) {
	// seu codigo AQUI
  NO* atual1 = (*p1);
  NO* atual2 = (*p2);
  NO* ult1 = NULL;
  NO* ult2 = NULL;
  NO* comp = NULL;

  while (atual1 && atual1 != atual2){
    atual2 = (*p2);
    while(atual2 && atual2 != atual1){
      ult2 = atual2;
      atual2 = atual2->prox;
    }
    if(atual1 != atual2){
      ult1 = atual1;
      atual1 = atual1->prox;
    }
  }

  ult1->prox = (*p1);
  ult2->prox = (*p2);

  comp = atual1;

  while(comp != NULL){
    comp = comp->prox;
    free(atual1);
    atual1 = comp;
  }

  return;
}