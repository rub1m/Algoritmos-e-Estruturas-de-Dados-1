#include <stdio.h>
#include <locale.h>
void soma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}
int main() {
  setlocale(LC_ALL, "Portuguese");
  int num1 = 15;
    int num2 = 25;
    int res; 
    soma(&num1, &num2, &res);
    printf("A soma de %d e %d é: %d\n", num1, num2, res);
    return 0;
}
