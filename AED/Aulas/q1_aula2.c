#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char nome[52];
  struct Node *prox;
} Node;

void adicionar(Node **head, Node **tail, char *n);
void deletar(Node **head, Node **tail);
void consultar(Node **head);
void Caminho(int escolha, Node **head, Node **tail);
int Menu(void);

int main(void) {
  Node *head = NULL;
  Node *tail = NULL;
  int escolha;

  do {
    escolha = Menu();
    Caminho(escolha, &head, &tail);
  } while (1);

  return 0;
}

void adicionar(Node **head, Node **tail, char *n) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL) {
        strcpy(novo->nome, n);
        novo->prox = NULL;
        if (*head == NULL) {
            *head = novo;
            *tail = novo;
        } else {
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void deletar(Node **head, Node **tail) {
  Node *aux;
  if ((*head) != NULL) {
    aux = *head;
    *head = (*head)->prox;
    free(aux);
    if ((*head) == NULL){
      *tail = NULL;
    }
  }
}

void consultar(Node **head) {
    Node *aux = *head;
    int count = 1;

    if(aux == NULL) {
        printf("Lista vazia\n");
        return;
    }

    printf("Lista de pacientes:\n");
    while (aux != NULL) {
        printf("%d. %s\n", count, aux->nome);
        aux = aux->prox;
        count++;
    }
}

int Menu(void) {
    int escolha;
    printf("O que você deseja fazer?\n");
    printf("1 - Incluir paciente\n");
    printf("2 - Realizar atendimento do paciente\n");
    printf("3 - Consultar a posição atual do paciente pelo nome\n");
    printf("4 - Exibir a quantidade de pacientes já atendidos\n");
    printf("5 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

void Caminho(int escolha, Node **head, Node **tail) {
    Node paciente;
    switch (escolha) {
        case 1:
          
            printf("\nDigite o nome do paciente: ");
            scanf("%s", paciente.nome);
            adicionar(head, tail, paciente.nome);
            break;
      
        case 2:
            
            printf("\nDigite o nome do paciente: ");
            scanf("%s", paciente.nome);
            deletar(head, tail);
            break;
      
        case 3:
            printf("\nSeus pacientes:\n: ");
            consultar(head);
            break;
        case 4:
            
            break;
        case 5:
            printf("Tchau!");
            exit(0);;
        default:
            printf("Opção inválida.\n");
    }
}