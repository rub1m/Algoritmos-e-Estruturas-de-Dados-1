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
    printf("Digite o primeiro número: ");
    scanf("%d", &x);
    printf("Digite o segundo número: ");
    scanf("%d", &y); 
    resultado = maior(&x, &y);
    printf("\n--- Resultado ---\n");
    printf("O maior valor entre %d e %d é: %d\n", x, y, resultado);
    return 0;
}
