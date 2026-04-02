#include <stdio.h>
#include <locale.h>
void inverter(int *v, int n) {
    int *inicio = v;
    int *fim = v + (n - 1);
    int aux; 
    while (inicio < fim) {
        aux = *inicio;
        *inicio = *fim;
        *fim = aux;
        inicio++;
        fim--;
    }
}
int main() {
  setlocale(LC_ALL, "Portuguese");
    int meuVetor[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Entrada: ");
    for(int i = 0; i < n; i++){
      printf("%d ", meuVetor[i]);
    } 
    inverter(meuVetor, n);
    printf("\nSaida: ");
    for(int i = 0; i < n; i++){ 
      printf("%d ", meuVetor[i]);
    }
    printf("\n");
    return 0;
}
