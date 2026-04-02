#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
int main() {
  setlocale(LC_ALL, "Portuguese");
    int n;
    float soma = 0, media;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return 1; 
    }
    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", (v + i)); 
    }
    for (int i = 0; i < n; i++) {
        soma += *(v + i); 
    }
    media = soma / n;
    printf("\nA média dos valores é: %.2f\n", media);
    free(v);
    return 0;
}
