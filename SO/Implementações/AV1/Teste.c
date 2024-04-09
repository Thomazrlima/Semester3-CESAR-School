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
  int dtd;
};

// Escalonamento
void rate(struct Tarefa tarefas[], int qtd, int total);
void edf(struct Tarefa tarefas[], int qtd, int total);

// Funções Gerais
void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[],
                    int qtd);
void novoprocesso(struct Tarefa tarefas[], int qtd, int atual);
int fim(struct Tarefa tarefas[], int exe);
void morte(struct Tarefa tarefas[], int qtd, int exe, int total);

// Funções Rate
int rate_prioridade(struct Tarefa tarefas[], int qtd, int total);

// Funções EDF
int edf_prioridade(struct Tarefa tarefas[], int qtd, int tempo);

// Main
int main(void) {
  struct Tarefa tarefas[2];
  int periodos[2] = {50, 80};
  int execucoes[2] = {25, 35};
  int qtd = 2;

  iniciarTarefas(tarefas, periodos, execucoes, qtd);
  // rate(tarefas, qtd, 165);
  edf(tarefas, qtd, 165);

  return 0;
}

// Escalonamento
void rate(struct Tarefa tarefas[], int qtd, int total) {
  int atual, idle = 0;
  int exe = total, exetemp = total;
  int i, j;

  printf("EXECUTION BY RATE\n");

  for (atual = 1, i = 0; atual <= total; atual++) {
    int flag = 1;

    exetemp = exe;
    exe = rate_prioridade(tarefas, qtd, total);

    if (exe != exetemp && atual > 1 && exetemp >= 0 && exetemp < qtd &&
        tarefas[exetemp].resto != 0) {
      printf("[%s] for %d units - H\n", tarefas[exetemp].nome,
             tarefas[exetemp].units);
      tarefas[exetemp].units = 0;
    }

    if (exe != total) {
      // printf("tarefa %s %d\n", tarefas[exe].nome, atual);
      tarefas[exe].resto--;
      tarefas[exe].units++;
      tarefas[exe].completo += fim(tarefas, exe);
    } else {
      idle++;
    }

    if (exetemp == total && exe != total && atual > 1) {
      printf("idle for %d units\n", idle);
      idle = 0;
    }

    novoprocesso(tarefas, qtd, atual);
    if (atual == total) {
      morte(tarefas, qtd, exe, total);
    }
  }

  printf("\nLOST DEADLINES\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].perdido);
  }

  printf("\nCOMPLETE EXECUTION\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].completo);
  }

  printf("\nKILLED\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].morto);
  }
}

void edf(struct Tarefa tarefas[], int qtd, int total) {
  int atual, i, j, idle = 0;
  int exe = total, exetemp = total;

  printf("EXECUTION BY EDF\n");

  for (atual = 1, i = 0; atual <= total; atual++) {

    exetemp = exe;
    exe = edf_prioridade(tarefas, qtd, total);

    if (exe != exetemp && atual > 1 && exetemp >= 0 && exetemp < qtd &&
        tarefas[exetemp].resto != 0) {
      printf("[%s] for %d units - H\n", tarefas[exetemp].nome,
             tarefas[exetemp].units);
      tarefas[exetemp].units = 0;
    }

    if (exe != total) {
      tarefas[exe].resto--;
      tarefas[exe].units++;
      tarefas[exe].completo += fim(tarefas, exe);
    } else {
      idle++;
    }

    for (j = 0; j < qtd; j++) {
      tarefas[j].dtd--;
    }

    if (exetemp == total && exe != total && atual > 1) {
      printf("idle for %d units\n", idle);
      idle = 0;
    }

    novoprocesso(tarefas, qtd, atual);
    if (atual == total) {
      morte(tarefas, qtd, exe, total);
    }
  }

  printf("\nLOST DEADLINES\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].perdido);
  }

  printf("\nCOMPLETE EXECUTION\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].completo);
  }

  printf("\nKILLED\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].morto);
  }
}

// Funções Gerais
void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[],
                    int qtd) {
  for (int i = 0; i < qtd; i++) {
    sprintf(tarefas[i].nome, "T%d", i + 1);
    tarefas[i].periodo = periodos[i];
    tarefas[i].prioridade = periodos[i];
    tarefas[i].dtd = periodos[i];
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
        tarefas[i].dtd = tarefas[i].periodo;

      } else {

        tarefas[i].resto = tarefas[i].cpub;
        tarefas[i].prioridade = tarefas[i].periodo;
        tarefas[i].dtd = tarefas[i].periodo;
      }
    }
  }
}

int fim(struct Tarefa tarefas[], int exe) {
  if (tarefas[exe].resto == 0) {
    printf("[%s] for %d units - F\n", tarefas[exe].nome, tarefas[exe].units);
    tarefas[exe].units = 0;
    return 1;
  }
  return 0;
}

void morte(struct Tarefa tarefas[], int qtd, int exe, int total) {

  int i = 0;

  if (exe != total) {
    for (i = 0; i < qtd; i++) {
      if (tarefas[i].resto - 1 > 0) {
        tarefas[i].morto++;
      }
    }
    printf("[%s] for %d units - K\n", tarefas[exe].nome, tarefas[exe].units);
  }
}

// Funções Rate
int rate_prioridade(struct Tarefa tarefas[], int qtd, int total) {
  int i;
  int menor = total;

  for (i = 0; i < qtd; i++) {
    if (menor > tarefas[i].prioridade && tarefas[i].resto != 0) {
      menor = tarefas[i].prioridade;
    }
  }

  for (i = 0; i < qtd; i++) {
    if (tarefas[i].prioridade == menor && tarefas[i].resto != 0) {
      return i;
    }
  }
  return menor;
}

// Funções EDF
int edf_prioridade(struct Tarefa tarefas[], int qtd, int tempo) {
  int i;
  int dtd = tempo;
  struct Tarefa debug;

  for (i = 0; i < qtd; i++) {
    debug = tarefas[i];
    if (tarefas[i].dtd < dtd && tarefas[i].resto != 0) {
      dtd = tarefas[i].dtd;
    }
  }

  for (i = 0; i < qtd; i++) {
    if (tarefas[i].dtd == dtd && tarefas[i].resto != 0) {
      return i;
    }
  }

  return dtd;
}