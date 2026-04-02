#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    int *v = malloc(n * sizeof(int));
    if (v == NULL){
      return 1; 
    }
    printf("Digite os %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    printf("Ordem Inversa: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", v[i]);
    }
    free(v);
    return 0;
}
