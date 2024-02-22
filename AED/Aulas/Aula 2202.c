#include <stdio.h>

void calcular_media (int *A, int *B);

int main() {
  int A, B;
  printf("Digite o valor de A: ");
  scanf("%d", &A);
  printf("Digite o valor de B: ");
  scanf("%d", &B);
  
  calcular_media(&A, &B);
  printf("%d %d", A, B);
  
  
  return(0);
}

void calcular_media (int *A, int *B){
  int temp;
  
  if (*A > *B || *A == *B){
    temp = (*A + *B) / 2;
    *A = (*A + *B) % 2;
    *B = temp;
  }
  else{
    temp = (*A + *B) / 2;
    *B = (*A + *B) % 2;
    *A = temp;
  }
}
