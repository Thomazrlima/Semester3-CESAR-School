#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int paciente;
    struct Node *prox;
} Node;

typedef struct Node1 {
    int paciente;
    struct Node1 *prox;
    struct Node1 *ant;
} Node1;

void addpilha(Node **head, int valor);
void removepilha(Node **head);
void addfila(Node **head, Node **tail, int valor);
void removefila(Node **head, Node **tail);
void removeend(Node **head);
void printlista(Node *head);
void selection_sort (int lista[], int N);
void printarray(int lista[], int N);
void bubble_sort (int lista[], int N);
void insersion_sort(int lista[], int N);

int main() {

    int lista[5] = {7, 8, 5, 9, 1};
    int N = sizeof(lista)/sizeof(lista[0]);
    int caso, teste, caso1;
    Node *head  = NULL;
    Node *tail = NULL;

    printf("O que vocedeseja testar?\n");
    scanf("%d", &teste);
    switch (teste) {
        case 1:

            printf("1 - Seletion Sort\n2 - Bubble Sort\n3 - Insersion Sort\n");
            printf("Digite o Algoritimo que vai ser usado:");
            scanf("%d", &caso);

            switch (caso) {
                case 1:
                    selection_sort (lista, N);
                break;
                case 2:
                    bubble_sort (lista,N);
                break;
                case 3:
                    insersion_sort(lista, N);
                break;
            }

            printarray(lista, N);
        break;

        case 2:
            printf("1 - Pilha\n2 - Fila\n");
            scanf("%d", &caso1);
            switch (caso1) {
                case 1:
                    printf("Digite o valor do ID do Paciente:");
                    int valor = 1;
                    while(valor != 0) {
                        scanf("%d", &valor);
                        addpilha(&head, valor);
                    }
                    printlista(head);
                    removepilha(&head);
                    printlista(head);
                break;
                case 2:
                    printf("Digite o valor do ID do Paciente:");
                    valor = 1;
                    while(valor != 0) {
                        scanf("%d", &valor);
                        addfila(&head, &tail, valor);
                    }
                    printlista(head);
                    removefila(&head, &tail);
                    printlista(head);
                break;
            }
        break;
    }

    return 0;
}

void addpilha(Node **head, int valor) {
    Node *temp = (Node *)malloc(sizeof(Node));

    if(temp != NULL) {
        temp->paciente = valor;
        temp->prox = *head;
        *head = temp;
    }
}

void removepilha(Node **head) {
    Node *temp;
    if ((*head != NULL)) {
        temp = *head;
        *head = (*head)->prox;
        free(temp);
    }
}

void addfila(Node **head, Node **tail, int valor) {
    Node *temp = (Node *)malloc(sizeof(Node));

    if(temp != NULL) {
        temp->paciente = valor;
        temp->prox = NULL;

        if(*head == NULL) {
            *head = temp;
            *tail = temp;
        }else {
            (*tail)->prox = temp;
            *tail = temp;
        }
    }
}

void removefila(Node **head, Node **tail) {
    Node *temp;

    if((*head) != NULL) {
        temp = *head;
        *head = (*head)->prox;
        free(temp);

        if((*head) == NULL) {
            *tail = NULL;
        }
    }
}

void removeend(Node **head) {
    Node *temp = *head;
    Node *aux;

    if ((*head != NULL)) {
        while(temp->prox != NULL) {
            aux = temp;
            temp = temp->prox;
        }
        aux->prox = NULL;
        free(temp);
    }
}

void printlista(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        if(temp->prox != NULL) {
            printf("%d ->", temp->paciente);
        }else {
            printf("%d", temp->paciente);
        }
        temp = temp->prox;
    }
    printf("\n");
}

void printarray(int lista[], int N) {
    for(int i = 0; i < N; i++) {
        if(i < N-1) {
            printf("%d -> ", lista[i]);
        }else {
            printf("%d", lista[i]);
        }
    }
    printf("\n");
}

void selection_sort(int lista[], int N) {
    int min, temp, trocas = 0;

    for(int i = 0; i < N-1; i++) {
        min = i;
        for(int j = i+1; j < N; j++) {
            if(lista[j] < lista[min]){
                min = j;
            }
        }
        if(min != i) {
            temp = lista[i];
            lista[i] = lista[min];
            lista[min] = temp;
            printf("Troca: %d <-> %d\n", lista[i], lista[min]);
            trocas++;
        }
    }

    printf("Total de trocas: %d\n", trocas);
}

void bubble_sort(int lista[], int N) {
    int temp, trocas = 0;

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-1; j++) {
            if (lista[j] > lista[j+1]) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
                printf("Troca: %d <-> %d\n", lista[j], lista[j+1]);
                trocas++;
            }
        }
    }
    printf("Total de trocas: %d\n", trocas);
}


void insersion_sort(int lista[], int N){
    int temp;
    int trocas = 0;

    for(int i = 1; i < N; i++) {
        int j = i;
        while ((lista[j]) < lista[j-1] && j > 0) {
            temp = lista[j-1];
            lista[j-1] = lista[j];
            lista[j] = temp;
            j--;
            printf("Troca: %d <-> %d\n", lista[j], lista[j-1]);
            trocas++;

            if(j == 0) {
                break;
            }
        }
    }
    printf("Total de trocas: %d\n", trocas);
}