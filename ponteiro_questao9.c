#include <stdio.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL, "Portuguese");
    int x = 10;
    int *p;
    int **pp;
    p = &x;  
    pp = &p;
    printf("Valor de x (direto): %d\n", x);
    printf("Valor de x (usando *p): %d\n", *p);
    printf("Valor de x (usando **pp): %d\n", **pp);
    printf("Endereço de x: %p\n", (void*)&x);
    printf("Conteúdo de p (endereço de x): %p\n", (void*)p);
    printf("Conteúdo de pp (endereço de p): %p\n", (void*)pp);
    return 0;
}
