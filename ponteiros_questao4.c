#include <stdio.h>
#include <locale.h>
void troca(int *a, int *b) {
  int aux; 
    aux = *a;  
    *a = *b;  
    *b = aux; 
}
int main() {
  setlocale(LC_ALL, "Portuguese");  
  int x = 10;
    int y = 20;
    printf("Antes da troca: x = %d, y = %d\n", x, y);
    troca(&x, &y);
    printf("Depois da troca: x = %d, y = %d\n", x, y);
    return 0;
}
