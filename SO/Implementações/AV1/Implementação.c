#include <stdio.h>

struct Tarefa {
    char nome[3];
    int periodo;
    int cpub;
    int resto;
    int completadas;
    int perdido;
};

void rate(struct Tarefa tarefas[], int qtd, int total);
void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[], int qtd); // Provisório

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
  int i = 0;

  printf("EXECUTION BY RATE\n");

  while (atual < total) {
    if (tarefas[i].resto > 0) {
      if (tarefas[i].completadas == 0) {
        
        printf("[%s] for %d units - F\n", tarefas[i].nome, tarefas[i].cpub);
        
        tarefas[i].resto -= tarefas[i].cpub;
        atual += tarefas[i].cpub;
        tarefas[i].completadas++;
        
        if (tarefas[i].resto <= 0) {
          tarefas[i].completadas = 1;
        }
        
      } else if (tarefas[i].completadas == 1) {
        
        printf("[%s] for %d units - H\n", tarefas[i].nome, tarefas[i].cpub);
        
        tarefas[i].resto -= tarefas[i].cpub;
        atual += tarefas[i].cpub;
        tarefas[i].completadas++;
        
        if (tarefas[i].resto <= 0) {
          tarefas[i].completadas = 2;
        }
        
      } else if (tarefas[i].completadas == 2) {
        
        printf("[%s] for %d units - L\n", tarefas[i].nome, tarefas[i].resto);
        
        atual += tarefas[i].resto;
        tarefas[i].completadas++;
        tarefas[i].resto = 0;
        
      }
    } else {
      
      i++;
      atual++;
      if (i == qtd) {
        i = 0;
      }
      
      if (i >= qtd) {
        
        printf("idle for %d units\n", total - atual);
        atual = total;
        
      }
    }
  }

  printf("LOST DEADLINES\n");
  for (i = 0; i < qtd; i++) {
    if (tarefas[i].completadas != 2) {
      printf("[%s] %d\n", tarefas[i].nome, tarefas[i].completadas);
    }
  }

  printf("COMPLETE EXECUTION\n");
  for (i = 0; i < qtd; i++) {
    printf("[%s] %d\n", tarefas[i].nome, tarefas[i].completadas);
  }

  printf("KILLED\n");
  for (i = 0; i < qtd; i++) {
    if (tarefas[i].completadas == 0) {
      printf("[%s] 1\n", tarefas[i].nome);
    }
  }
}

void iniciarTarefas(struct Tarefa tarefas[], int periodos[], int execucoes[], int qtd) {
  for (int i = 0; i < qtd; i++) {
    sprintf(tarefas[i].nome, "T%d", i + 1); // Provisório, vão entrar os nomes reais
    tarefas[i].periodo = periodos[i];
    tarefas[i].cpub = execucoes[i];
    tarefas[i].resto = execucoes[i];
    tarefas[i].completadas = 0;
    tarefas[i].completadas = 0;
    tarefas[i].perdido = 0;
  }
}