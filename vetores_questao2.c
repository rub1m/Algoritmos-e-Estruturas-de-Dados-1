#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL,"Portuguese");
      int l, c, i, j;
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &l, &c);
    int **matriz = malloc(l * sizeof(int *));
    for (i = 0; i < l; i++) {
        matriz[i] = malloc(c * sizeof(int));
    }
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\nOriginal:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nTransposta:\n");
    for (j = 0; j < c; j++) {
        for (i = 0; i < l; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < l; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
