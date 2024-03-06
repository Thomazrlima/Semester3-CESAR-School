#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
  char nome[52];
  struct Node *prox;
} Node;

void adicionar(Node **head, Node **tail, char *n);
void deletar(Node **head, Node **tail);
void consultar(Node **head, char *comparado);
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

void consultar(Node **head, char *comparado) {
    Node *aux = *head;
    int count = 0;

    if (aux == NULL) {
        printf("\nLista vazia\n");
        return;
    }

    while (aux != NULL) {
        count += 1;
        if (strcmp(aux->nome, comparado) == 0) {
            printf("\nEncontrado na posição %d\n", count);
            return;
        }
        aux = aux->prox;
    }

    printf("\nPaciente não encontrado :(\n");
}


int Menu(void) {
    int escolha;
    printf("\nO que você deseja fazer?\n");
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
    static int atendidos = 0;
    char comparado[52];
  
    switch (escolha) {
      
        case 1:

            system("clear");
            printf("\nDigite o nome do paciente: ");
            scanf("%s", paciente.nome);
            adicionar(head, tail, paciente.nome);
            break;
      
        case 2:

            system("clear");
            printf("\nO Paciente a ser atendido é: %s\n", (*head)->nome);
            deletar(head, tail);
            atendidos += 1;
            break;
      
        case 3:

            system("clear");
            printf("\nDigite o nome do paciente: ");
            scanf("%s", comparado);
            consultar(head, comparado);
            break;

      
        case 4:

            system("clear");
            printf("\nPacientes atendidos: %d\n", atendidos);
            break;
      
        case 5:

            system("clear");
            printf("Finalizando o programa \n");
            for(int i = 0; i < 5; i++){
              sleep(1);
              printf(".\n");
            }
            printf("Tchau!\n");
            exit(0);
      
        default:
          
            system("clear");
            printf("Opção inválida.\n");
      
    }
}