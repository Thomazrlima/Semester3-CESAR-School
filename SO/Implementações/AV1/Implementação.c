#include <stdio.h>

struct Tarefa {
  char nome[3];
  int periodo;
  int cpub;
  int resto;
  int perdido;
  int completo;
  int morto;
  int prioridade;
  int units;
};

void rate(struct Tarefa tarefas[], int qtd, int total);
void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[],
                    int qtd);

int main(void) {
  struct Tarefa tarefas[2];
  int periodos[2] = {50, 80};
  int execucoes[2] = {25, 35};
  int qtd = 2;

  iniciarTarefas(tarefas, periodos, execucoes, qtd);

  rate(tarefas, qtd, 165);

  return 0;
}

void rate(struct Tarefa tarefas[], int qtd, int total) {
  int atual = 1, bou = 1, idle = 0;
  int i, j;

  while (atual <= total) {

    for (i = 0; i < qtd; i++) {
      for (j = 0; j < qtd; j++) {

        if (tarefas[i].prioridade < tarefas[j].prioridade &&
            tarefas[i].resto != 0) {
          printf("Executando tarefa %s %d\n", tarefas[i].nome, atual); // Debug
          tarefas[i].resto--;
          tarefas[i].units++;

          if (tarefas[i].resto == 0) {
            tarefas[i].completo += 1;
            tarefas[i].prioridade = 999;
            printf("[%s] for %d units - K\n", tarefas[i].nome,
                   tarefas[i].units);
            tarefas[i].units = 0;
          }
        }
      }
    }

    for (i = 0; i < qtd; i++) {
      if (atual % tarefas[i].periodo == 0) {

        if (tarefas[i].resto != 0) {

          tarefas[i].resto = tarefas[i].cpub;
          tarefas[i].perdido += 1;
          tarefas[i].prioridade = tarefas[i].periodo;
          printf("%d\n", tarefas[i].prioridade); // Debug
          for (j = i; j < qtd; j++) {
            if (tarefas[i].prioridade < tarefas[j].prioridade) {
              printf("%d\n", tarefas[j].prioridade);
              atual--;
            }
          }

        } else {

          tarefas[i].resto = tarefas[i].cpub;
          tarefas[i].prioridade = tarefas[i].periodo;
          printf("%d\n", tarefas[i].prioridade); // Debug
        }
      }
    }

    if (atual + 1 == total) {
      for (i = 0; i < qtd; i++) {
        if (tarefas[i].resto - 1 > 0) {
          tarefas[i].morto++;
        }
      }
    }

    atual++;
  }

  printf("EXECUTION BY RATE\n");

  printf("LOST DEADLINES\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].perdido);
  }

  printf("COMPLETE EXECUTION\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].completo);
  }

  printf("KILLED\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].morto);
  }
}

void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[],
                    int qtd) {
  for (int i = 0; i < qtd; i++) {
    sprintf(tarefas[i].nome, "T%d", i + 1);
    tarefas[i].periodo = periodos[i];
    tarefas[i].prioridade = periodos[i];
    tarefas[i].cpub = execucoes[i];
    tarefas[i].resto = execucoes[i];
    tarefas[i].completo = 0;
    tarefas[i].morto = 0;
    tarefas[i].units = 0;
    tarefas[i].perdido = 0;
  }
}