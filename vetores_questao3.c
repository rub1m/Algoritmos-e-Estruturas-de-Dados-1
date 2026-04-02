#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main() {
    int n, i, j;
    int **matriz;
    printf("Digite o tamanho da matriz (n): ");
    scanf("%d", &n);
    matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 100) + 1;
        }
    }
    printf("\nMatriz Gerada:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        free(matriz[i]); 
    }
    free(matriz);
    return 0;
}
