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
  int atual = 0;
  int i, j;
  struct Tarefa temp;

  while (atual < total) {

    for (i = 0; i < qtd - 1; i++) {
      if (tarefas[i].prioridade < tarefas[i + 1].prioridade &&
          tarefas[i].resto != 0) {

        if (tarefas[i].resto > 0) {
          printf("Executando tarefa %s\n", tarefas[i].nome);
          tarefas[i].resto--;
          if (tarefas[i].resto == 0) {
            tarefas[i].completo = 1;
          }
        }
      }

      if (atual % tarefas[i].periodo == 0) {
        if (tarefas[i].resto != 0) {
          tarefas[i].resto = tarefas[i].cpub;
          tarefas[i].morto += 1;
          tarefas[i].prioridade = 0;
        } else {
          tarefas[i].resto = tarefas[i].cpub;
          tarefas[i].prioridade = tarefas[i].periodo;
        }
      }
    }
    atual++;
  }

  printf("EXECUTION BY RATE\n");

  printf("LOST DEADLINES\n");
  for (i = 0; i < qtd; i++) {
    if (tarefas[i].completo != 2) {
      printf("[%s] %d\n", tarefas[i].nome, tarefas[i].morto);
    }
  }

  printf("COMPLETE EXECUTION\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].completo);
  }

  printf("KILLED\n");
  for (i = 0; i < qtd; i++) {
    if (tarefas[i].completo == 0) {
      printf("[%s] 1\n", tarefas[i].nome);
    }
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
  }
}
