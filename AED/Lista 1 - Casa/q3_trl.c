#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char nome[20];
    struct Node *prox;
    struct Node *ant;
} Node;

void add(Node **head, char *nome);
void imprimir(Node *head);
Node* separar(Node **head);

int main(void) {
    int N;
    Node *padrao = NULL;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char nome[20];
        scanf("%s", nome);
        add(&padrao, nome);
    }

    imprimir(padrao);
    Node *linha2 = separar(&padrao);
    imprimir(linha2);
    

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

void imprimir(Node *head) {
    while (head != NULL) {
        printf("%s", head->nome);
        if (head->prox != NULL) {
            printf(", ");
        }
        head = head->prox;
    }
}

Node* separar(Node **head) {
    Node *novalista = NULL;
    Node *curr = *head;

    while (curr != NULL && curr->prox != NULL) {
        if (strlen(curr->nome) == strlen(curr->prox->nome)) {
            Node *temp = curr->prox;
            curr->prox = temp->prox;
            if (temp->prox != NULL) {
                temp->prox->ant = curr;
            }
            temp->prox = NULL;
            temp->ant = NULL;

            if (novalista == NULL) {
                novalista = temp;
            } else {
                Node *last = novalista;
                while (last->prox != NULL) {
                    last = last->prox;
                }
                last->prox = temp;
                temp->ant = last;
            }
        } else {
            curr = curr->prox;
        }
    }

    return novalista;
}
