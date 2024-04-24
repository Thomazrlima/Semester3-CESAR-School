#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
    struct Node *ant;
} Node;

void inserir(Node **head, Node **tail, int valor);
void printLista(Node *head, Node *tail);
void remover(Node **head, Node **tail, Node **removido, int flag);
Node *k(Node **head, int k);
Node *m(Node **tail, int m);

int main(void) {
    int N, k_value, m_value, i;
    Node *head = NULL;
    Node *tail = NULL;
    Node *pontk = NULL;
    Node *pontm = NULL;

    while (1) {
        scanf("%d %d %d", &N, &k_value, &m_value);

        if (N == 0 && k_value == 0 && m_value == 0) {
            break;
        }

        head = tail = NULL;

        for (i = 0; i < N; i++) {
            inserir(&head, &tail, i + 1);
        }

        while (head != NULL) {
            pontk = k(&head, k_value);
            pontm = m(&tail, m_value);

            if(pontk->valor == pontm->valor) {
                remover(&head, &tail, &pontk, 1);
            }else {
                remover(&head, &tail, &pontk, 1);
                remover(&head, &tail, &pontm, 0);
            }
        }

        printLista(head, tail);
    }

    return 0;
}

void inserir(Node **head, Node **tail, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = valor;

    if (*head == NULL && *tail == NULL) {
        *head = *tail = novo;
        novo->ant = novo->prox = novo;
    } else {
        novo->prox = NULL;
        novo->ant = *tail;
        (*tail)->prox = novo;
        *tail = novo;
        (*head)->ant = novo;
    }
    (*tail)->prox = *head;
}

void printLista(Node *head, Node *tail) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node *atual = head;
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != tail->prox);
    printf("\n");
}

Node *k(Node **head, int k) {
    Node *pontk = (*head);

    for (int i = 1; i < k; i++) {
        pontk = pontk->prox;
    }

    return pontk;
}

Node *m(Node **tail, int m) {
    Node *pontm = (*tail);

    for (int i = 1; i < m; i++) {
        pontm = pontm->ant;
    }

    return pontm;
}

void remover(Node **head, Node **tail, Node **removido, int flag) {
    Node *remover;
    Node *pont = (*removido);
    if(flag){
        (*removido) = (*removido)->prox;
    }else{
        (*removido) = (*removido)->ant;
    }


    if (*head == *tail) {
        *head = *tail = NULL;
    } else if ((*tail)->valor == pont->valor) {
        remover = *tail;
        *tail = remover->ant;
        remover->prox->ant = remover->ant;
        remover->ant->prox = remover->prox;
        free(remover);

    } else if ((*head)->valor == pont->valor) {
        remover = *head;
        *head = (*head)->prox;
        (*head)->ant = *tail;
        (*tail)->prox = *head;
        free(remover);
    } else {
        remover = *head;
        while (remover != pont) {
            remover = remover->prox;
        }
        remover->prox->ant = remover->ant;
        remover->ant->prox = remover->prox;
        free(remover);
    }
}
