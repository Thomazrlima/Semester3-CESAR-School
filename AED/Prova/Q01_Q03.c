#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
  int num;
  struct arv *esq;
  struct arv *dir;
} Arv;

void inserir(Arv **t, int num);
void imprimir(Arv *t);
Arv* buscaPai(Arv *raiz, int chave);

int main() {
  Arv *t = NULL;
  
  inserir(&t, 61);
  inserir(&t, 37);
  inserir(&t, 77);
  inserir(&t, 82);
  inserir(&t, 30);
  inserir(&t, 98);
  inserir(&t, 15);
  
  imprimir(t);
  
  Arv *pai = buscaPai(t, 15);
  imprimir(pai);
  
  return 0;

}

void inserir(Arv **t, int num){
     if(t == NULL){
          (*t)->esq = NULL;
          (*t)->dir = NULL;
          (*t)->num = num;
     }
     else{
          if((*t)->num > num){
                       inserir(&(*t)->esq, num);
          }
          if((*t)->num < num){
                       inserir(&(*t)->dir, num);
          }
     }
}

void imprimir(Arv *t){
     if(t == NULL){
          return;
     }
     imprimir(t->esq);
     print("%d ", t->num);
     imprimir(t->dir);
}

Arv* buscaPai(Arv *raiz, int chave){
     if(raiz == NULL){
             return;
     }
     Arv *aux = raiz;
     while(chave != aux->num){
                 if(chave < aux->num && chave != aux->esq->num){
                    aux = aux->esq;         
                 }
                 if(chave > aux->num && chave != aux->dir->num){
                    aux = aux->esq;
                 }
                 if(aux->esq == NULL && aux->dir == NULL){
                    return;
                 }
     }
     return aux;
}
     
              
               
               
