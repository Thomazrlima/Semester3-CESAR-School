#include <stdio.h>
#include <stdlib.h>

#ifdef EDF
#define ESCOLHA 'E'
#elif RATE
#define ESCOLHA 'R'
#else
#define ESCOLHA 'N'
#endif

struct Tarefa {
    char nome[50];
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

char alg = ESCOLHA;

// Escalonamento
void rate(struct Tarefa tarefas[], int qtd, int total);
void edf(struct Tarefa tarefas[], int qtd, int total);

// Funções Gerais
int qtdprocessos(FILE *dados);
void iniciarTarefas(struct Tarefa tarefas[], int qtd);
void novoprocesso(struct Tarefa tarefas[], int qtd, int atual, int total, FILE *fp);
int fim(struct Tarefa tarefas[], int exe, FILE *fp);
void morte(struct Tarefa tarefas[], int qtd, int exe, int total, int atual, FILE *fp);

// Funções Rate
int rate_prioridade(struct Tarefa tarefas[], int qtd, int total);

// Funções EDF
int edf_prioridade(struct Tarefa tarefas[], int qtd, int tempo);

// Main
int main(int argc, char *argv[]) {
    FILE *dados;
    dados = fopen(argv[1], "r");
    //dados = fopen("/Users/evaldocunhafilho/CLionProjects/untitled/test_rate/01.txt", "r");

    int qtd = qtdprocessos(dados);
    struct Tarefa *tarefas = (struct Tarefa *)malloc(qtd * sizeof(struct Tarefa));
    int total, primeiraLinha = 1, periodo, i=0;
    fseek(dados, 0, 0);
    while (!feof(dados)){
        if(primeiraLinha){
            fscanf(dados, "%d", &total);
            primeiraLinha = 0;
        }else{
            fscanf(dados, "%s %d %d", tarefas[i].nome, &tarefas[i].periodo, &tarefas[i].cpub);
            i++;
        }
    }

    fclose(dados);

    iniciarTarefas(tarefas, qtd);

    if(alg == 'R') {
        rate(tarefas, qtd, total);
    }else if(alg == 'E') {
        edf(tarefas, qtd, total);
    }else {
        printf("Vish, digitou errado");
    }

    return 0;
}

// Escalonamento
void rate(struct Tarefa tarefas[], int qtd, int total) {
    FILE *fp;
    fp = fopen("rate.out", "w");

    int atual, idle = 0;
    int exe = total, exetemp = total;
    int i, j;

    fprintf(fp, "EXECUTION BY RATE\n");

    for (atual = 1, i = 0; atual <= total; atual++) {
        int flag = 1;

        exetemp = exe;
        exe = rate_prioridade(tarefas, qtd, total);

        if (exe != exetemp && atual > 1 && exetemp >= 0 && exetemp < qtd && tarefas[exetemp].resto != 0) {
            fprintf(fp, "[%s] for %d units - H\n", tarefas[exetemp].nome, tarefas[exetemp].units);
            tarefas[exetemp].units = 0;
        }

        if (exe != total) {
            // printf("tarefa %s %d\n", tarefas[exe].nome, atual);
            tarefas[exe].resto--;
            tarefas[exe].units++;
            tarefas[exe].completo += fim(tarefas, exe, fp);
        } else {
            idle++;
        }

        if (exetemp == total && exe != total && atual > 1 || exetemp == atual) {
            fprintf(fp, "idle for %d units\n", idle);
            idle = 0;
        }

        novoprocesso(tarefas, qtd, atual, total, fp);

        if (atual == total) {
            morte(tarefas, qtd, exe, total, atual, fp);
        }
    }

    fprintf(fp, "\nLOST DEADLINES\n");
    for (i = 0; i < qtd; i++) {
        fprintf(fp, "[%s] %d\n", tarefas[i].nome, tarefas[i].perdido);
    }

    fprintf(fp, "\nCOMPLETE EXECUTION\n");
    for (i = 0; i < qtd; i++) {
        fprintf(fp, "[%s] %d\n", tarefas[i].nome, tarefas[i].completo);
    }

    fprintf(fp, "\nKILLED\n");
    for (i = 0; i < qtd; i++) {
        fprintf(fp, "[%s] %d", tarefas[i].nome, tarefas[i].morto);
        if (i < qtd - 1) {
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
}

void edf(struct Tarefa tarefas[], int qtd, int total) {
    FILE *fp;
    fp = fopen("edf.out", "w");

    int atual, i, j, idle = 0;
    int exe = total, exetemp = total;

    fprintf(fp, "EXECUTION BY EDF\n");

    for (atual = 1, i = 0; atual <= total; atual++) {

        exetemp = exe;
        exe = edf_prioridade(tarefas, qtd, total);

        if (exe != exetemp && atual > 1 && exetemp >= 0 && exetemp < qtd && tarefas[exetemp].resto != 0) {
            fprintf(fp,"[%s] for %d units - H\n", tarefas[exetemp].nome, tarefas[exetemp].units);
            tarefas[exetemp].units = 0;
        }

        if (exe != total) {
            tarefas[exe].resto--;
            tarefas[exe].units++;
            tarefas[exe].completo += fim(tarefas, exe, fp);
        } else {
            idle++;
        }

        for (j = 0; j < qtd; j++) {
            tarefas[j].dtd--;
        }

        if (exetemp == total && exe != total && atual > 1 || exetemp == atual) {
            fprintf(fp, "idle for %d units\n", idle);
            idle = 0;
        }

        novoprocesso(tarefas, qtd, atual, total, fp);
        if (atual == total) {
            morte(tarefas, qtd, exe, total, atual, fp);
        }
    }

    fprintf(fp, "\nLOST DEADLINES\n");
    for (i = 0; i < qtd; i++) {
        fprintf(fp, "[%s] %d\n", tarefas[i].nome, tarefas[i].perdido);
    }

    fprintf(fp, "\nCOMPLETE EXECUTION\n");
    for (i = 0; i < qtd; i++) {
        fprintf(fp, "[%s] %d\n", tarefas[i].nome, tarefas[i].completo);
    }

    fprintf(fp, "\nKILLED\n");
    for (i = 0; i < qtd; i++) {
        fprintf(fp, "[%s] %d", tarefas[i].nome, tarefas[i].morto);
        if (i < qtd - 1) {
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
}

int qtdprocessos(FILE *dados) {
    int linhas = 0;
    char ch;

    while ((ch = fgetc(dados)) != EOF) {
        if (ch == '\n') {
            linhas++;
        }
    }

    return linhas;
}

// Funções Gerais
void iniciarTarefas(struct Tarefa tarefas[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        tarefas[i].prioridade = tarefas[i].periodo;
        tarefas[i].dtd = tarefas[i].periodo;
        tarefas[i].resto = tarefas[i].cpub;
        tarefas[i].completo = 0;
        tarefas[i].morto = 0;
        tarefas[i].units = 0;
        tarefas[i].perdido = 0;
    }
}

void novoprocesso(struct Tarefa tarefas[], int qtd, int atual, int total, FILE *fp) {
    int i;

    for (i = 0; i < qtd; i++) {
        if (atual % tarefas[i].periodo == 0) {

            if (tarefas[i].resto != 0) {

                if(tarefas[i].units != 0){
                    fprintf(fp, "[%s] for %d units - L\n", tarefas[i].nome, tarefas[i].units);
                }
                tarefas[i].resto = tarefas[i].cpub;
                if(atual != total){
                    tarefas[i].perdido += 1;
                }
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

void morte(struct Tarefa tarefas[], int qtd, int exe, int total, int atual, FILE *fp) {
    int i = 0;

    if (exe != total) {
        for (i = 0; i < qtd; i++) {
            if (tarefas[i].resto - 1 > 0) {
                tarefas[i].morto++;
            }
        }
        if(tarefas[exe].units != 0){
            fprintf(fp, "[%s] for %d units - K\n", tarefas[exe].nome, tarefas[exe].units);
        }
    } else if(atual == total) {
        for (i = 0; i < qtd; i++) {
            if (tarefas[i].resto > 0) {
                tarefas[i].morto++;
            }
        }
    }
}

int fim(struct Tarefa tarefas[], int exe, FILE *fp) {
    if (tarefas[exe].resto == 0) {
        fprintf(fp, "[%s] for %d units - F\n", tarefas[exe].nome, tarefas[exe].units);
        tarefas[exe].units = 0;
        return 1;
    }
    return 0;
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