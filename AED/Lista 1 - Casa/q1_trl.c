#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int diamante;
    struct Node *prox;
} Node;

void inserir(Node **head, int n);
int contpilha(Node *head);
void liberarpilha(Node *head);

int main(void) {
    int N;
    Node *head = NULL;
    scanf("%d", &N);

    while (N--) {
        char gnd[10000];
        scanf("%s", gnd);
        int size = strlen(gnd);
        int abre = 0;

        for (int i = 0; i < size; i++) {
            if (gnd[i] == '<') {
                abre++;
            } else if (gnd[i] == '>' && abre > 0) {
                inserir(&head, i);
                abre--;
            }
        }

        int diamantes = contpilha(head);
        printf("%d\n", diamantes);
        liberarpilha(head);
        head = NULL;
    }

    return 0;
}

void inserir(Node **head, int diamante){
  Node *novo = (Node *)malloc(sizeof(Node));
  if(novo!= NULL){
    novo->diamante = diamante;
    novo->prox = *head;
    *head =novo;
  }
}

int contpilha(Node *head) {
    int cont = 0;
    Node *aux = head;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void liberarpilha(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->prox;
        free(temp);
    }
}