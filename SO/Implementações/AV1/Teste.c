#include <stdio.h>

struct Tarefa {
  char nome[4];
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
void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[], int qtd);
void novoprocesso(struct Tarefa tarefas[], int qtd, int atual);
int prioridade(struct Tarefa tarefas[], int qtd);
int fim(struct Tarefa tarefas[], int exe);

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
  int atual, idle = 0;
  int i, j;
  char tempnome[4];

  for (atual = 1, i = 0; atual <= total; atual++) {
    int flag = 1;

    int exe = prioridade(tarefas, qtd);
    novoprocesso(tarefas, qtd, atual);

    if (exe != 999){
      printf("tarefa %s %d\n", tarefas[exe].nome, atual);
      tarefas[exe].resto--;
      tarefas[exe].units++;
      tarefas[exe].completo += fim(tarefas, exe);
    }else{
      idle++;
    }

    if (atual == total) {
      for (i = 0; i < qtd; i++) {
        if (tarefas[i].resto - 1 > 0) {
          tarefas[i].morto++;
        }
      }
      printf("[%s] for %d units - K\n", tarefas[exe].nome, tarefas[exe].units);
    }
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

void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[], int qtd) {
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

void novoprocesso(struct Tarefa tarefas[], int qtd, int atual) {
  int i;

  for (i = 0; i < qtd; i++) {
    if (atual % tarefas[i].periodo == 0) {

      if (tarefas[i].resto != 0) {

        printf("[%s] for %d units - L\n", tarefas[i].nome, tarefas[i].units);
        tarefas[i].resto = tarefas[i].cpub;
        tarefas[i].perdido += 1;
        tarefas[i].prioridade = tarefas[i].periodo;
        tarefas[i].units = 0;

      } else {

        tarefas[i].resto = tarefas[i].cpub;
        tarefas[i].prioridade = tarefas[i].periodo;
      }
    }
  }
}

int prioridade(struct Tarefa tarefas[], int qtd) {
  int i, j;
  int menor = 999;

  for (i = 0; i < qtd; i++) {
    if (menor > tarefas[i].prioridade && tarefas[i].resto != 0) {
      menor = i;
    }
  }
  return menor;
}

int fim(struct Tarefa tarefas[], int exe) {
  if (tarefas[exe].resto == 0) {
    printf("[%s] for %d units - F\n", tarefas[exe].nome, tarefas[exe].units);
    tarefas[exe].units = 0;
    return 1;
  }
  return 0;
}