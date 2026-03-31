#include <stdio.h>
#include <locale.h>
typedef struct Funcionario {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
};
void preencherFuncionario(struct Funcionario* f) {
    printf("Digite o nome: ");
    scanf("%s", &f->nome);
    printf("Digite o salario: ");
    scanf("%f", &f->salario);
    printf("Digite o identificador: ");
    scanf("%d", &f->identificador);
    printf("Digite o cargo: ");
    scanf("%s", &f->cargo);
}
void imprimirFuncionario(struct Funcionario* f) {
    printf("Funcionario:\n");
    printf("Nome: %s\n", f->nome);
    printf("Salário: %f\n", f->salario);
    printf("Identificador: %d\n", f->identificador);
    printf("Cargo: %s\n", f->cargo);
}
void alterarSalario(struct Funcionario *f) {
    printf("Digite o novo salário: ");
    scanf("%f", &f->salario);
    printf("Atualizado!\n");
}
void analisarSalarios(struct Funcionario vetor[], int tamanho) {
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
    printf("Maior salário:\n");
    printf("Cargo: %s | Salario: R$ %.2f\n", vetor[maior].cargo, vetor[maior].salario);
    printf("\nMenor salário:\n");
    printf("Cargo: %s | Salário: R$ %.2f\n", vetor[menor].cargo, vetor[menor].salario);
}
int main() {
    setlocale(LC_ALL, "portuguese");
    struct Funcionario FuncionarioLista[2]
    for (int i = 0; i < 2; i++) {
        preencherFuncionario(&FuncionarioLista[i]);
    }
    return 0;
}
