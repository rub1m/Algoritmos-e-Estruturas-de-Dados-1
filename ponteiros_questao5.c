#include <stdio.h>
#include <locale.h>
int maior(int *a, int *b) {
    if (*a > *b) {
        return *a;
    } else {
        return *b;
    }
}
int main() {
  setlocale(LC_ALL,"Portuguese");
    int x, y, resultado;
    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    printf("Digite o segundo numero: ");
    scanf("%d", &y); 
    resultado = maior(&x, &y);
    printf("\n--- Resultado ---\n");
    printf("O maior valor entre %d e %d e: %d\n", x, y, resultado);
    return 0;
}
