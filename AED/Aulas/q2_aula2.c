#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
  int valor;
  struct Node *prox;
} Node;

void adicionar(Node **head, int a);
void impar(Node *head);
void ultimo(Node *head);

void adicionar(Node **head, int a){
  Node *novo = (Node *)malloc(sizeof(Node));
  if(novo!= NULL){
    novo->valor = a;
    novo->prox = *head;
    *head =novo;
  }
}

void impar(Node *head){
  while(head !=NULL){
    if(head->valor %2 !=0){
      printf("%d\n", head->valor);
    }
    head= head->prox;
  }
}

void ultimo(Node *head){
  while(head->prox !=NULL){
    head= head->prox;
  }
  printf("%d\n", head->valor);
}

int Menu(void);
void Caminho(int escolha, Node **head);

int main(void) {
    Node *head = NULL;
    int escolha;

    do {
        escolha = Menu();
        Caminho(escolha, &head);
    } while (1);

    return 0;
}

int Menu(void) {
    int escolha;
    printf("O que você deseja fazer?\n");
    printf("1 - Cadastrar elemento\n");
    printf("2 - Imprimir a base\n");
    printf("3 - Imprimir os impares\n");
    printf("Opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

void Caminho(int escolha, Node **head) {
    Node num;

    switch (escolha) {
        case 1:

            printf("\nDigite o elemento (int): ");
            scanf("%d", &num.valor);
            adicionar(head, num.valor);
            break;

        case 2:

            ultimo(*head);
            break;

        case 3:

            impar(*head);
            break;

        default:
            printf("Opção inválida.\n");
    }
}