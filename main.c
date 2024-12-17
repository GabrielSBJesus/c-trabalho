#include <stdio.h>
#include "sistema_academico.h"

int main() {
    printf("### SISTEMA ACADÊMICO 1.0 ###\n");
    
    int opcao;
    do {
        printf("1- Inserir turma\n");
        printf("2- Inserir disciplina\n");
        printf("3- Inserir aluno\n");
        printf("4- Remover turma\n");
        printf("5- Remover disciplina\n");
        printf("6- Remover aluno\n");
        printf("7- Listar turmas\n");
        printf("8- Listar disciplinas\n");
        printf("9- Listar alunos\n");
        printf("0- Sair\n");
        printf("Informe a opção desejada:");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                inserirTurma();
                break;
            case 2:
                inserirDisciplina();
                break;
            case 3:
                inserirAluno();
                break;
            case 4:
                removerTurma();
                break;
            case 5:
                removerDisciplina();
                break;
            case 6:
                removerAluno();
                break;
            case 7:
                listarTurmas();
                break;
            case 8:
                listarDisciplinas();
                break;
            case 9:
                listarAlunos();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}