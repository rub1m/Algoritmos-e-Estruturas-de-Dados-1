#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_TURMAS 3
#define MAX_VAGAS 20
struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;
struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;
Turma* cria_turma(char id) {
    Turma* nova_turma = (Turma*) malloc(sizeof(Turma));
    nova_turma->id = id;
    nova_turma->vagas = MAX_VAGAS; 
    for (int i = 0; i < MAX_VAGAS; i++) {
        nova_turma->alunos[i] = NULL;
    }
    return nova_turma;
}
void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas == 0) {
        printf("Aviso: A turma %c está cheia!\n", turma->id);
        return;
    }
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
            novo_aluno->mat = mat;
            strcpy(novo_aluno->nome, nome);
            for (int j = 0; j < 3; j++) {
                novo_aluno->notas[j] = 0.0;
            }
            novo_aluno->media = 0.0;
            turma->alunos[i] = novo_aluno;
            turma->vagas--; 
            printf("Aluno matriculado com sucesso na turma %c!\n", turma->id);
            return; 
        }
    }
}
void lanca_notas(Turma* turma) {
    printf("\n--- Lancando notas da turma %c ---\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Aluno: %s (Mat: %d)\n", turma->alunos[i]->nome, turma->alunos[i]->mat);
            float soma = 0;
            for (int j = 0; j < 3; j++) {
                printf("  Digite a nota %d: ", j + 1);
                scanf("%f", &turma->alunos[i]->notas[j]);
                soma += turma->alunos[i]->notas[j];
            }
            turma->alunos[i]->media = soma / 3.0;
            printf("  Média calculada: %.2f\n", turma->alunos[i]->media);
        }
    }
}
void imprime_alunos(Turma* turma) {
    printf("Alunos da turma %c:\n", turma->id);
    int tem_aluno = 0;
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("  Matricula: %d | Nome: %s | Media: %.2f\n", 
             turma->alunos[i]->mat, 
             turma->alunos[i]->nome, 
             turma->alunos[i]->media);
            tem_aluno = 1;
        }
    } 
    if (tem_aluno == 0) {
        printf("  Nenhum aluno matriculado nesta turma.\n");
    }
}
void imprime_turmas(Turma** turmas, int n) {
    printf("\n--- Relatorio de Todas as Turmas ---\n");
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            printf("\nTURMA %c - Vagas disponiveis: %d\n", turmas[i]->id, turmas[i]->vagas);
            imprime_alunos(turmas[i]);
        }
    }
}
Turma* procura_turma(Turma** turmas, int n, char id) {
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL && turmas[i]->id == id) {
            return turmas[i]; 
        }
    }
    return NULL; 
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    Turma* turmas[MAX_TURMAS];
    int qtd_turmas = 0;
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lançamento de notas e listagem de alunos.\nAutor: Rubens Guilherme Lopes \nVersao: 1.0");
    for (int i = 0; i < MAX_TURMAS; i++) {
        turmas[i] = NULL;
    }
    int opcao;
    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Criar turma\n");
        printf("2 - Matricular aluno\n");
        printf("3 - Lançar notas\n");
        printf("4 - Listar alunos\n");
        printf("5 - Listar turmas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                if (qtd_turmas >= MAX_TURMAS) {
                    printf("Limite máximo de turmas atingido!\n");
                } else {
                    char id;
                    printf("Digite o ID da turma (ex: A, B): ");
                    scanf(" %c", &id); 
                    printf("Criando nova turma...\n");
                    if (procura_turma(turmas, qtd_turmas, id) != NULL) {
                        printf("Erro: Já existe uma turma com esse ID!\n");
                    } else {
                        turmas[qtd_turmas] = cria_turma(id);
                        qtd_turmas++;
                        printf("Turma %C criada com sucesso!\n", id);
                    }
                }
                break;
            }
            case 2: {
                char id;
                printf("Digite o ID da turma para matricular o aluno: ");
                scanf(" %c", &id);
                Turma* t = procura_turma(turmas, qtd_turmas, id);
                if (t == NULL) {
                    printf("Erro: Turma não encontrada!\n");
                } else {
                    int mat;
                    char nome[81];
                    printf("Digite a matricula do aluno: ");
                    scanf("%d", &mat);
                    printf("Digite o nome do aluno: ");
                    scanf(" %[^\n]", nome);
                    matricula_aluno(t, mat, nome);
                }
                break;
            }
            case 3: {
                char id;
                printf("Digite o ID da turma para lançar notas: ");
                scanf(" %c", &id);
                Turma* t = procura_turma(turmas, qtd_turmas, id);
                if (t == NULL) {
                    printf("Erro: Turma não encontrada!\n");
                } else {
                    lanca_notas(t);
                }
                break;
            }
            case 4: {
                char id;
                printf("Digite o ID da turma para listar os alunos: ");
                scanf(" %c", &id);
                Turma* t = procura_turma(turmas, qtd_turmas, id);
                if (t == NULL) {
                    printf("Erro: Turma não encontrada!\n");
                } else {
                    imprime_alunos(t);
                }
                break;
            }
            case 5: {
                imprime_turmas(turmas, qtd_turmas);
                break;
            }
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    return 0;
}
