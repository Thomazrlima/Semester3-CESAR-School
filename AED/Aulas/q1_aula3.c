#include <stdio.h>

struct Node{
  int valor;
  struct Node *prox;
  struct Node *ant;
} Node;

void inserir(struct Node **head, struct Node **tail, int valor);
void remover (struct Node **head, struct Node **tail);

int main(void) {
  struct Node *head = (struct Node *) malloc(sizeof(struct Node));
  printf(":)");
  return 0;
}

void inserir(struct Node **head, struct Node **tail, int valor){
  struct Node *novo = (struct Node *) malloc(sizeof(struct Node));
  novo->valor = valor;
  
  if(novo == NULL){
   novo->prox = novo-> ant = *head = *tail = NULL;
  }else{
    (*tail)->prox = (*head)->ant = novo;;
    novo->prox = (*head);
    novo->ant = (*tail);
    *tail = novo;
  }
}

void remover (struct Node **head, struct Node **tail){
  if(*head != NULL){
    struct Node *velho = *head;
    if(*head == *tail){
      *head = *tail = NULL;
    }else{
      *tail = velho->ant;
      (*tail)->prox = *head;
      (*head)->ant = *tail;
    }
    free(velho);
  }
}