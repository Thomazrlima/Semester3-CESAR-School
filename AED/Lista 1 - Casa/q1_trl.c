#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int diamante;
    struct Node *prox;
} Node;

void inserir(Node **head, Node **tail, int n);
int contfila(Node *head);
void liberarfila(Node *head);

int main(void) {
    int N;
    Node *head = NULL;
    Node *tail = NULL;
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
                inserir(&head, &tail, i);
                abre--;
            }
        }

        int diamantes = contfila(head);
        printf("%d\n", diamantes);
        liberarLista(head);
        head = NULL;
    }

    return 0;
}

void inserir(Node **head, Node **tail, int n) {
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL) {
        novo->diamante = n;
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

int contfila(Node *head) {
    int cont = 0;
    Node *aux = head;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void liberarfila(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->prox;
        free(temp);
    }
}