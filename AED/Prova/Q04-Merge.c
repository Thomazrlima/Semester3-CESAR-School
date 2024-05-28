#include <stdio.h>
#include <limits.h>
#define TAMANHO 8

//Complexidade = O(n log n), isso se deve por esse algoritimo usar apenas um laço while por vez, nunca usando 2 laços de 
//repetição um dentro do outro, então a complexidade dos while é apenas somada, e não multiplicada

void intercala (int inicio, int meio, int fim, int v[]);
void mergesort (int inicio, int fim, int v[]);

int main () {

  int vetor[TAMANHO] = {7,5,9,12,0,10,15,-12};

  int i = 0;
  
  for (i = 0; i < TAMANHO; i++) {
    printf ("%2d ", vetor[i]);
  }
  printf ("\n\n");

  mergesort (0, TAMANHO - 1, vetor);

  for (i = 0; i < TAMANHO; i++) {
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
    if (v[inicio_v01] < v[inicio_v02]){
      aux[poslivre++] = v[inicio_v01++]; 
    }
    else{
      aux[poslivre++] = v[inicio_v02++];
    }
  }
  //se existirem nÃºm. em v[inicio_v01] que nÃ£o foram intercalados 
  while (inicio_v01 <= meio)  
    aux[poslivre++] = v[inicio_v01++];
  //se existirem nÃºm. em v[inicio_v02] que nÃ£o foram intercalados
  while (inicio_v02 <= fim)  
    aux[poslivre++] = v[inicio_v02++];
  //retorna os valores do vetor aux para o vetor v   
  for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)  
    v[inicio_v01] = aux[inicio_v01-inicio];
}
