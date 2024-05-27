#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
  int num;
  struct arv *esq;
  struct arv *dir;
} Arv;

void inserir(Arv **t, int num);
void inordem(Arv *t);
void posordem(Arv *t);
void preordem(Arv *t);
int busca(Arv *aux, int n);
void remover(Arv **pRaiz, int numero);
Arv *MaiorDireita(Arv **no);

int main() {
  Arv *t = NULL;

  inserir(&t, 48);
  inserir(&t, 30);
  inserir(&t, 82);
  inserir(&t, 15);
  inserir(&t, 37);
  inserir(&t, 61);
  inserir(&t, 98);

  printf("\nPRE-ordem:");
  preordem(t);

  printf("\nIN-ordem:");
  inordem(t);

  printf("\nPOS-ordem:");
  posordem(t);
  printf("\n\n");

  if (busca(t, 30)) {
    printf("\nO numero está na arvore!\n");
  } else {
    printf("O numero NAO está na arvore!\n");
  }

  printf("\nPre-ordem:");
  preordem(t);
  printf("\n");

  remover(&t, 30);

  printf("\nPrint após remoção (Pre-ordem):");
  preordem(t);
  printf("\n");

  return 0;
}

void preordem(Arv *t) {
  if (t != NULL) {
    printf("%d ", t->num);
    preordem(t->esq);
    preordem(t->dir);
  }
}

void inordem(Arv *t) {
  if (t != NULL) {
    inordem(t->esq);
    printf("%d ", t->num);
    inordem(t->dir);
  }
}

void posordem(Arv *t) {
  if (t != NULL) {
    posordem(t->esq);
    posordem(t->dir);
    printf("%d ", t->num);
  }
}

void inserir(Arv **t, int n) {
  if (*t == NULL) {
    *t = (Arv *)malloc(sizeof(Arv));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->num = n;
  } else {
    if (n < (*t)->num) {
      inserir(&(*t)->esq, n);
    }
    if (n > (*t)->num) {
      inserir(&(*t)->dir, n);
    }
  }
}

int busca(Arv *aux, int n) {
  if (aux == NULL)
    return 0;
  if (aux->num == n)
    return 1;
  if (n < aux->num)
    busca(aux->esq, n);
  else
    busca(aux->dir, n);
}


Arv *MaiorDireita(Arv **no) {
  if ((*no)->dir != NULL)
    return MaiorDireita(&(*no)->dir);
  else {
    Arv *aux = *no;
    if ((*no)->esq != NULL) {
      *no = (*no)->esq;
    } else {
      *no = NULL;
    }
    return aux;
  }
}

void remover(Arv **pRaiz, int numero) {
  if (*pRaiz == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  if (numero < (*pRaiz)->num)
    remover(&(*pRaiz)->esq, numero);
  else if (numero > (*pRaiz)->num)
    remover(&(*pRaiz)->dir, numero);
  else {
    Arv *pAux = *pRaiz;
    // 01 - no sem filhos
    if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)) {
      free(pAux);
      (*pRaiz) = NULL;
    } else {
      // 02 - no com filho direito
      if ((*pRaiz)->esq == NULL) {
        (*pRaiz) = (*pRaiz)->dir;
        pAux->dir = NULL;
        free(pAux);
      } else {
        // 02 - no com filho esquerdo
        if ((*pRaiz)->dir == NULL) {
          (*pRaiz) = (*pRaiz)->esq;
          pAux->esq = NULL;
          free(pAux);
        } else {
          // 03 - no com dois filhos
          pAux = MaiorDireita(&(*pRaiz)->esq);
          pAux->esq = (*pRaiz)->esq;
          pAux->dir = (*pRaiz)->dir;
          (*pRaiz)->esq = (*pRaiz)->dir = NULL;
          free((*pRaiz));
          *pRaiz = pAux;
        }
      }
    }
  }
}
