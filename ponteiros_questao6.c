#include <stdio.h>
#include <locale.h>
int main() {
   setlocale(LC_ALL, "Portuguese");
    int v[5] = {1, 2, 3, 4, 5};
    int *p = v; 
    printf("Elementos do vetor usando aritmetica de ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    return 0;
}
