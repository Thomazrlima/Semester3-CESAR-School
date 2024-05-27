#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
  char nome[20];
  struct Node *prox;
  struct Node *ant;
} Node;

void add(Node **head, char *nome);
void imprimir(Node **head);
Node* separar(Node **head);
int contador(Node *head);
void printLista(Node *head);

int main(void) {
  int N;
  Node *padrao = NULL;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char nome[20];
    scanf("%s", nome);
    add(&padrao, nome);
  }

  Node *corte = separar(&padrao);
  imprimir(&padrao);

  int num = contador(padrao);
  Node **linha = (Node **)malloc(num * sizeof(Node *));
  linha[0] = corte;

  for (int i = 1; i < num; i++) {
    linha[i] = separar(&linha[i - 1]);
  }

  for (int i = 0; i < num; i++) {

    if (linha[i] != NULL) {
      printf("\n");
      imprimir(&linha[i]);

      Node *temp = linha[i];

      while (temp != NULL) {
        Node *next = temp->prox;
        free(temp);
        temp = next;
      }
    }
  }
  
  free(linha);

  return 0;
}

void add(Node **head, char *nome) {
  Node *novo = (Node *)malloc(sizeof(Node));
  strcpy(novo->nome, nome);
  novo->prox = NULL;
  novo->ant = NULL;

  if (*head == NULL) {
    *head = novo;
  } else {
    Node *aux = *head;
    Node *ant = NULL;

    while (aux != NULL && strlen(aux->nome) <= strlen(novo->nome)) {
      ant = aux;
      aux = aux->prox;
     }

    if (ant == NULL) {
      novo->prox = *head;
      (*head)->ant = novo;
      *head = novo;
    } else {
      ant->prox = novo;
      novo->ant = ant;
      novo->prox = aux;
      if (aux != NULL) {
        aux->ant = novo;
      }
    }
  }
}

void imprimir(Node **head) {
  Node *current = *head;
  while (current != NULL) {
    printf("%s", current->nome);
    if (current->prox != NULL) {
      printf(", ");
    }
    current = current->prox;
  }
}

Node* separar(Node **head) {
  if (!*head || !(*head)->prox) return NULL;

  Node *current = *head;
  Node *startNewList = NULL; 
  Node *lastNewList = NULL; 

  while (current && current->prox) {
    if (strlen(current->nome) == strlen(current->prox->nome)) {
      if (!startNewList) {
        startNewList = current->prox; 
        lastNewList = startNewList;
      } else {
        lastNewList->prox = current->prox; 
        lastNewList = lastNewList->prox;
      }

      current->prox = current->prox->prox;
      if (current->prox) current->prox->ant = current;
      lastNewList->prox = NULL; 
    } else {
      current = current->prox;
    }
  }

  return startNewList; 

}

int contador(Node *head){
  int cont = 0;
  while(head != NULL){
    cont++;
    head = head->prox;
  }
  return cont;
}

void printLista(Node *head){
  Node *current = head;
  while (current != NULL) {
    printf("%s", current->nome);
    if(current -> prox != NULL){
      printf(", ");
    }
    current = current->prox;
  }
  printf("\n");
}