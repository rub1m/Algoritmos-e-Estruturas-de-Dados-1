#include <stdio.h>
#include <locale.h>
int maiorElemento(int *v, int n) {
    int maior = *v; 
    for (int i = 1; i < n; i++) {
        if (*(v + i) > maior) {
            maior = *(v + i);
        }
    }
    return maior;
}
int main() {
  setlocale(LC_ALL, "Portuguese");
    int meuVetor[] = {10, 45, 2, 89, 33};
    int tamanho = 5;
    int resultado = maiorElemento(meuVetor, tamanho);
    printf("O maior elemento do vetor é: %d\n", resultado);
    return 0;
}
