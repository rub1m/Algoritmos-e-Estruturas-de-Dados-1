#include <stdio.h>
#include <locale.h>
int main() {
    int x = 10;
    int *p;
    p = &x;
    printf("O valor de x: %d\n", x);
    printf("O endereço de memória de x: %p\n", (void*)&x);
    printf("O valor armazenado em p: %p\n", (void*)p);
    printf("O valor apontado por p: %d\n", *p);
    return 0;
}
