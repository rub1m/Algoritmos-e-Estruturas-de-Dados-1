#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main() {
    int numPessoas;
    char **nomes;
    int *idades;
    printf("Quantas pessoas deseja armazenar? ");
    scanf("%d", &numPessoas);
    getchar(); 
    nomes = (char **)malloc(numPessoas * sizeof(char *));
    idades = (int *)malloc(numPessoas * sizeof(int));
    if (nomes == NULL || idades == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    for (int i = 0; i < numPessoas; i++) {
        nomes[i] = (char *)malloc(100 * sizeof(char));
        printf("\nDigite o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], 100, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
        printf("Digite a idade de %s: ", nomes[i]);
        scanf("%d", &idades[i]);
        getchar();
    }
    printf("\n--- Nomes Armazenados ---\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("Pessoa %d: %s (Idade: %d)\n", i + 1, nomes[i], idades[i]);
    }
    for (int i = 0; i < numPessoas; i++) {
        free(nomes[i]);
    }
    free(nomes); 
    free(idades);
    printf("\nMemória liberada com sucesso!\n");
    return 0;
}
