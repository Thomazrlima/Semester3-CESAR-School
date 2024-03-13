#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
int valor; 
struct Node *prox; 
struct Node *ant; 
} Node;

void print(Node* head);
void inserir(Node **head, int valor);
int busca(Node *head, int valor);

int main(void) {
  Node *head = NULL;
  int x, n;

  printf("Digite o tamanho da lista: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    printf("Digite o valor a ser inserido na lista: ");
    scanf("%d", &x);
    inserir(&head, x);
  }

  printf("Digite o valor a ser buscado na lista: ");
  scanf("%d", &x);
  int result = busca(head, x);

  if (result == -1){
    printf("O valor %d não está na lista.\n", x);
  }else{
    printf("%d números encontrados depois do %d\n", result, x);
  }
  
  return 0;
}

void print(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void inserir(Node **head, int valor){
  Node *novo = (Node*)malloc(sizeof(Node));
  novo->valor = valor;
  novo->prox = NULL;
  novo->ant = NULL;

  if(*head == NULL){
    *head = novo;

  }else{
    Node *atual = *head;
    while(atual->prox != NULL){
      atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;
  }
}

int busca(Node *head, int valor){
  int cont = 0;

  Node *atual = head;
  while(atual != NULL){
    if(atual->valor == valor){
      printf("Valor encontrado: %d\n", atual->valor);
      while(atual->prox != NULL){
        cont++;
        atual = atual->prox;
      }
      return cont;
    }
    atual = atual->prox;
  }
  return -1;
}