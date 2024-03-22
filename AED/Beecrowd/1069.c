#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    while (N--) {
        char gnd[10000];
        scanf("%s", gnd);
        int size = strlen(gnd);
        int diamantes = 0, abre = 0;

        for (int i = 0; i < size; i++) {
            if (gnd[i] == '<') {
                abre++;
            } else if (gnd[i] == '>' && abre > 0) {
                diamantes++;
                abre--;
            }
        }
        printf("%d\n", diamantes);
    }

    return 0;
}
