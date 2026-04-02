#include <stdio.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL, "Portuguese");  
  int n = 5;
    int *ptr = &n;
    printf("Valor inicial de n: %d\n", n);
    *ptr = 20;
    printf("Novo valor de n (alterado via ponteiro): %d\n", n);
    return 0;
}
