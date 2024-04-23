#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char pais[50];
  int O;
  int P;
  int B;
  struct Node *prox;
} Node;

void inserir(Node **head, char pais[], int O, int P, int B);
void imprimir(Node *head);
void ouro(Node **head);
void prata(Node **head);
void bronze(Node **head);
void pais(Node **head);
void trocar(Node **a, Node **b);

int main(void) {
  Node *head = NULL;
  char nacao[50];
  int O, P, B, N;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%s %d %d %d", nacao, &O, &P, &B);
    inserir(&head, nacao, O, P, B);
  }

  // pais(&head);
  // bronze(&head);
  prata(&head);
  ouro(&head);

  imprimir(head);

  return 0;
}

void inserir(Node **head, char pais[], int O, int P, int B) {
  Node *novo = (Node *)malloc(sizeof(Node));
  if (novo == NULL) {
    return;
  }

  strcpy(novo->pais, pais);
  novo->O = O;
  novo->P = P;
  novo->B = B;
  novo->prox = NULL;

  if (*head == NULL) {
    *head = novo;
  } else {
    Node *atual = *head;
    while (atual->prox != NULL) {
      atual = atual->prox;
    }
    atual->prox = novo;
  }
}

void ouro(Node **head) {
  Node *atual = *head;
  Node *max = NULL;
  Node *velho = NULL;

  while (atual != NULL) {
    max = atual;
    velho = NULL;
    Node *temp = atual->prox;

    while (temp != NULL) {
      if (temp->O > max->O) {
        max = temp;
        velho = atual;
      }
      temp = temp->prox;
    }

    if (max != atual) {
      trocar(&atual, &max);
      if (velho != NULL) {
        trocar(&velho->prox, &max->prox);
      }
    }

    atual = atual->prox;
  }
}

void prata(Node **head) {
  Node *atual = *head;
  Node *max = NULL;
  Node *velho = NULL;

  while (atual != NULL) {
    max = atual;
    velho = NULL;
    Node *temp = atual->prox;

    while (temp != NULL) {
      if (temp->P > max->P) {
        max = temp;
        velho = atual;
      }
      temp = temp->prox;
    }

    if (max != atual) {
      trocar(&atual, &max);
      if (velho != NULL) {
        trocar(&velho->prox, &max->prox);
      }
    }

    atual = atual->prox;
  }
}

void bronze(Node **head) {
  Node *atual = *head;
  Node *max = NULL;
  Node *velho = NULL;

  while (atual != NULL) {
    max = atual;
    velho = NULL;
    Node *temp = atual->prox;

    while (temp != NULL) {
      if (temp->B > max->B) {
        max = temp;
        velho = atual;
      }
      temp = temp->prox;
    }

    if (max != atual) {
      trocar(&atual, &max);
      if (velho != NULL) {
        trocar(&velho->prox, &max->prox);
      }
    }

    atual = atual->prox;
  }
}

void pais(Node **head) {
  Node *atual = *head;
  Node *max = NULL;
  Node *velho = NULL;

  while (atual != NULL) {
    max = atual;
    velho = NULL;
    Node *temp = atual->prox;

    while (temp != NULL) {
      if (strcmp(temp->pais, max->pais) > 0) {
        max = temp;
        velho = atual;
      }
      temp = temp->prox;
    }

    if (max != atual) {
      trocar(&atual, &max);
      if (velho != NULL) {
        trocar(&velho->prox, &max->prox);
      }
    }

    atual = atual->prox;
  }
}

void trocar(Node **a, Node **b) {
  Node temp;

  temp = **a;
  **a = **b;
  **b = temp;

  temp.prox = (*a)->prox;
  (*a)->prox = (*b)->prox;
  (*b)->prox = temp.prox;
}

void imprimir(Node *head) {
  while (head != NULL) {
    printf("%s %d %d %d\n", head->pais, head->O, head->P, head->B);
    head = head->prox;
  }
}
