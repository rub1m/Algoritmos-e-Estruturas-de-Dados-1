#include <stdio.h>
#include <string.h>
#include <locale.h>
typedef struct Pessoa{
    char nome[50];
    int documento;
    int idade;
} Pessoa;
void adicionarPessoa(Pessoa *p) {
    printf("Digite o nome: ");
    scanf("%s", p->nome); 
    printf("\nDigite o numero do documento: ");
    scanf("%d", &p->documento);
    printf("\nDigite a idade: ");
    scanf("%d", &p->idade);
}
void mostrarPessoa(Pessoa *p) {
    printf("\nDados Pessoais:");
    printf("\nNome: %s", p->nome);
    printf("\nDocumento: %d", p->documento);
    printf("\nIdade: %d anos\n", p->idade);
}
void atualizarIdade(Pessoa *p) {
      int outraIdade;
    printf("Digite a nova idade: ");
    scanf("%d", &outraIdade);
    p->idade = outraIdade;
    printf("Idade Atualizada!\n");
}
void diferencaIdades(Pessoa lista[], int tamanho) {
    int maior = 0; 
    int menor = 0; 
    for (int i = 1; i < tamanho; i++) {
        if (lista[i].idade > lista[maior].idade) {
            maior = i;
        }
        if (lista[i].idade < lista[menor].idade) {
            menor = i;
        }
    }
    printf("\nPessoa mais velha: %s", lista[maior].nome);
    printf("\nPessoa mais nova: %s\n", lista[menor].nome);
}
int main() {
setlocale(LC_ALL, "Portuguese");
  printf("testando o código, pra não dizer que não rodou heinn ");  
  Pessoa Lista[2];
    printf("\nCadastro:\n");
    for (int i = 0; i < 2; i++) {
        printf("\nPessoa %d:\n", i + 1);
        adicionarPessoa(&Lista[i]);
    }
    diferencaIdades(Lista, 2);
    printf("Código grande da mizera!");
    return 0;
}
