#include <stdio.h>
#include <locale.h>
int somaVetor(int *v, int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma = soma + *(v + i);
    }
    return soma;
}
int main() {
  setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Quantos elementos você quer somar no vetor? ");
    scanf("%d", &n);
    int meusNumeros[n];
    printf("Digite os %d numeros abaixo:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Posição %d: ", i + 1);
        scanf("%d", (meusNumeros + i));
    }
    int resultado = somaVetor(meusNumeros, n);
    printf("A soma total do vetor é: %d\n", resultado);
    return 0;
}
