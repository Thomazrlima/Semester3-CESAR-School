#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int valor;
  struct Node *prox;
  struct Node *ant;
} Node;
void inserir(Node **head, Node **tail, int valor);
void printLista(Node *head, Node *tail);
void correk(Node **head, Node **tail, int k, int cont);
void correm(Node **head, Node **tail, int m, int cont);

int main(void) {
  int N, k, m, i;
  int contk = 1, contm = 1;
  Node *head = NULL;
  Node *tail = NULL;

  while (1) {
    scanf("%d %d %d", &N, &k, &m);

    if (N == 0 && k == 0 && m == 0) {
      break;
    }

    for (i = 0; i < N; i++) {
      inserir(&head, &tail, i + 1);
    }

    while (N != 0) {
      correk(&head, &tail, m, contk);
      contk++;
      printLista(head, tail);
      correm(&head, &tail, m, contm);
      contm++;
      N--;
      printLista(head, tail);
    }
  }

  return 0;
}

void inserir(Node **head, Node **tail, int valor) {
  Node *novo = (Node *)malloc(sizeof(Node));
  novo->valor = valor;

  if (*head == NULL) {
    *head = *tail = novo;
    novo->ant = novo->prox = novo;
  } else {
    novo->prox = NULL;
    novo->ant = *tail;
    (*tail)->prox = novo;
    *tail = novo;
  }
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

void correk(Node **head, Node **tail, int k, int cont) {
  Node *atual = *head;

  if (cont%k != 0) {
    atual = atual->prox;
    return;
  }

  Node *remover = atual;
  atual->ant->prox = atual->prox;
  atual->prox->ant = atual->ant;

  if (remover == *head) {
    *head = remover->prox;
  }
  if (remover == *tail) {
    *tail = remover->ant;
  }

  printf("%d\n", remover->valor);
  free(remover);
}

void correm(Node **head, Node **tail, int m, int cont) {
  Node *atual = *tail;

  if (cont%m != 0) {
    atual = atual->prox;
    return;
  }

  Node *remover = atual;
  atual->ant->prox = atual->prox;
  atual->prox->ant = atual->ant;

  if (remover == *head) {
    *head = remover->prox;
  }
  if (remover == *tail) {
    *tail = remover->ant;
  }

  printf("%d\n", remover->valor);
  free(remover);
}