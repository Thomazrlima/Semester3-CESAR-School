#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
      char aviao[10];
      struct Node *prox;
} Node;

Node *add(Node *head, char aviao[]);
void imprimir(Node *head);
Node* intercalar(Node *head1, Node *head2, Node *head3, Node *head4);

int main(void) {
  Node *head1 = NULL;
  Node *head2 = NULL;
  Node *head3 = NULL;
  Node *head4 = NULL;
  char var[10];
  char aviao[10];
  int pontoCardeal = 0;
  
  do {
    scanf("%s", var);
    if (var[0] == '-') {
       pontoCardeal = atoi(var);
    } else if (var[0] == 'A') {
    if (pontoCardeal != 0) {
      if (pontoCardeal == -1){
        head1 = add(head1, var);
      }
      else if(pontoCardeal == -2){
        head2 = add(head2, var);
      }
      else if(pontoCardeal == -3){
        head3 = add(head3, var);
      }
      else if(pontoCardeal == -4){
        head4 = add(head4, var);
       }
     }
    }
  } while (var[0] != '0');

  Node * intercalado = intercalar(head1, head2, head3, head4);
  imprimir(intercalado);
  
  return 0;
}

Node *add(Node *head, char aviao[]) {
    Node *novo = (Node *)malloc(sizeof(Node));
    strcpy(novo->aviao, aviao);
    novo->prox = NULL;

    if (head == NULL) {
        head = novo;
    } else {
        Node *temp = head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }

    return head;
}

void imprimir(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%s", temp->aviao);
    if (temp->prox != NULL) {
      printf(" ");
    }
    temp = temp->prox;
  }
  printf("\n");
}

Node* intercalar(Node *head1, Node *head2, Node *head3, Node *head4) {
  Node *aux1 = head1;
  Node *aux2 = head2;
  Node *aux3 = head3;
  Node *aux4 = head4;
  Node *resultado = NULL;

  while (aux1 != NULL || aux2 != NULL || aux3 != NULL || aux4 != NULL) {
    if (aux1 != NULL) {
      resultado = add(resultado, aux1->aviao);
      aux1 = aux1->prox;
    }
    if (aux3 != NULL) {
      resultado = add(resultado, aux3->aviao);
      aux3 = aux3->prox;
    }
    if (aux2 != NULL) {
      resultado = add(resultado, aux2->aviao);
      aux2 = aux2->prox;
    }
    if (aux4 != NULL) {
      resultado = add(resultado, aux4->aviao);
      aux4 = aux4->prox;
    }
  }

  return resultado;
}
