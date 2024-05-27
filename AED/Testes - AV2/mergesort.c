#include <stdio.h>
#include <limits.h>
#define TAMANHO 8

void intercala (int inicio, int meio, int fim, int v[]);
void mergesort (int inicio, int fim, int v[]);

int main () {
  
  int vetor[TAMANHO] = {7,5,9,12,0,10,15,-12};

  for (int i = 0; i < TAMANHO; i++) {
    printf ("%2d ", vetor[i]);
  }
  printf ("\n\n");
  
  mergesort (0, TAMANHO - 1, vetor);
  
  for (int i = 0; i < TAMANHO; i++) {
    printf ("%2d ", vetor[i]);
  } 
  
  return 0;
}


void mergesort (int inicio, int fim, int v[]) {
  if (inicio < fim) {
    int meio = (inicio + fim)/2;
    mergesort (inicio, meio, v);
    mergesort (meio+1, fim, v);
    intercala (inicio, meio, fim, v);
  }
}

void intercala (int inicio, int meio, int fim, int v[]) {
  int inicio_v01 = inicio, inicio_v02 = meio+1, poslivre=0, aux[TAMANHO];
  while (inicio_v01 <= meio && inicio_v02 <= fim) {
    if (v[inicio_v01] <= v[inicio_v02])  
      aux[poslivre++] = v[inicio_v01++];
    else  
      aux[poslivre++] = v[inicio_v02++];
  }
  //se existirem núm. em v[inicio_v01] que não foram intercalados 
  while (inicio_v01 <= meio)  
    aux[poslivre++] = v[inicio_v01++];
  //se existirem núm. em v[inicio_v02] que não foram intercalados
  while (inicio_v02 <= fim)  
    aux[poslivre++] = v[inicio_v02++];
  //retorna os valores do vetor aux para o vetor v   
  for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)  
    v[inicio_v01] = aux[inicio_v01-inicio];
}
