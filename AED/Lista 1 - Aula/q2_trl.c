#include <stdio.h>

typedef struct Node{ 
int valor; 
struct Node *prox; 
struct Node *ant; 
} Node;

Node* intercalar(Node *head1, Node *head2);
void print(Node* head);
void inserir(Node **head, int valor);

int main(void) {
  Node *head1 = NULL;
  Node *head2 = NULL;
  int t1, t2;
  int valor;

  printf("Digite o tamanho da lista 1: ");
  scanf("%d", &t1);
  
  for(int i = 0; i < t1; i++){
    printf("Digite os valores da lista 1: ");
    scanf("%d", &valor);
    inserir(&head1, valor);
  }

  printf("\nDigite o tamanho da lista 2: ");
  scanf("%d", &t2);
  
  for(int i = 0; i < t2; i++){
    printf("Digite os valores da lista 2: ");
    scanf("%d", &valor);
    inserir(&head2, valor);
  }

  Node* result = intercalar(head1, head2);
  print(result);
  
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

Node* intercalar(Node *head1, Node *head2){
    int alternador = 0, valor;
    Node *aux1 = head1, *aux2 = head2;
    Node *resultado = NULL;

    while((aux1 != NULL) || (aux2 != NULL)){
        if(!alternador){
            valor = aux1->valor;
            inserir(&resultado, valor);
            aux1 = aux1->prox;
            alternador = 1;
        }else{
            valor = aux2->valor;
            inserir(&resultado, valor);
            aux2 = aux2->prox;
            alternador = 0;
        }
    }

    return resultado;
}