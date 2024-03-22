#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
int valor; 
struct Node *prox; 
struct Node *ant; 
} Node;

void inserir(Node **head, int valor);
void print(Node* head);

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

  print(head);
  
  return 0;
}

void inserir(Node** head, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*head == NULL || (*head)->valor > valor) {
        novo->prox = *head;
        if (*head != NULL)
            (*head)->ant = novo;
        *head = novo;
        return;
    }
    Node* atual = *head;
  
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    novo->ant = atual;
  
    if (atual->prox != NULL){
        atual->prox->ant = novo;
    }
  
    atual->prox = novo;
    novo->ant = atual;
}

void print(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}