#include <stdio.h>
#include <string.h>
#include <locale.h>
typedef struct Funcionario {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;
void adicionarFuncionario(Funcionario *f) {
    printf("Digite o nome: ");
    scanf("%s", &f->nome);
    printf("Digite o salario: ");
    scanf("%f", &f->salario);
    printf("Digite o identificador: ");
    scanf("%d", &f->identificador);
    printf("Digite o cargo: ");
    scanf("%s", &f->cargo);
}
void mostrarFuncionario(Funcionario *f) {
    printf("\nFuncionario:\n");
    printf("Nome: %s\n", f->nome);
    printf("Salario: %.2f\n", f->salario);
    printf("Identificador: %d\n", f->identificador);
    printf("Cargo: %s\n", f->cargo);
}
void alterarSalario(Funcionario *f) {
    float novo;
    printf("Salario atual: R$ %.2f\n", f->salario);
    printf("Digite o novo salario: ");
    scanf("%f", &novo);
    f->salario = novo;
    printf("Salario atualizado\n");
}
void compararSalarios(Funcionario vetor[], int tamanho) {
    int maior = 0;
    int menor = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].salario > vetor[maior].salario) {
            maior = i;
        }
        if (vetor[i].salario < vetor[menor].salario) {
            menor = i;
        }
    }
    printf("\nMaior salario:\n");
    printf("Cargo: %s | Salario: R$ %.2f\n", vetor[maior].cargo, vetor[maior].salario);
    printf("\nMenor salario:\n");
    printf("Cargo: %s | Salario: R$ %.2f\n", vetor[menor].cargo, vetor[menor].salario);
}
int main() {
    setlocale(LC_ALL, "portuguese");
    printf("testar de novo, corrigindo pela  235235 vez");
    Funcionario lista[2]; 
    for (int i = 0; i < 2; i++) {
        adicionarFuncionario(&lista[i]);
    }
    for (int i = 0; i < 2; i++) {
        mostrarFuncionario(&lista[i]);
    }
    compararSalarios(lista, 2);
    return 0;
}
