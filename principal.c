#include <stdio.h>
#include <stdlib.h>
#include "sistema_academico.h"

void processar_opcao_menu(int opcao, t_curso* curso) {
	t_turma* turma;
	t_disciplina* disciplina;
	t_aluno* aluno;

	if (opcao == 1) {
		inserir_turma(curso);
	} else if (opcao == 2) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			inserir_disciplina(turma, curso);
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 3) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			disciplina = obter_disciplina(turma);
			if (disciplina != NULL) {
				inserir_aluno(disciplina, curso);
			} else {
				printf("Disciplina não encontrada.\n");
			}
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 4) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			remover_turma(curso, turma);
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 5) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			disciplina = obter_disciplina(turma);
			if (disciplina != NULL) {
				remover_disciplina(turma, disciplina);
			} else {
				printf("Disciplina não encontrada.\n");
			}
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 6) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			disciplina = obter_disciplina(turma);
			if (disciplina != NULL) {
				aluno = obter_aluno(disciplina);
				if (aluno != NULL) {
					remover_aluno(disciplina, aluno);
				} else {
					printf("Aluno não encontrado.\n");
				}
			} else {
				printf("Disciplina não encontrada.\n");
			}
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 7) {
		listar_turmas(curso);
	} else if (opcao == 8) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			listar_disciplinas(turma);
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 9) {
		turma = obter_turma(curso);
		if (turma != NULL) {
			disciplina = obter_disciplina(turma);
			if (disciplina != NULL) {
				listar_alunos(disciplina);
			} else {
				printf("Disciplina não encontrada.\n");
			}
		} else {
			printf("Turma não encontrada.\n");
		}
	} else if (opcao == 0) {
		printf("Saindo...\n");
	} else {
		printf("Opção inválida.\n");
	}
} 

int obter_opcao_menu() {
	int opcao;
	printf("Informe a opção desejada: ");
	scanf("%d", &opcao);
	return opcao;
}

void exibir_menu(void) {
    printf("### SISTEMA ACADEMICO 1.0 ###\n");
    printf("1. Inserir turma\n");
    printf("2. Inserir disciplina\n");
    printf("3. Inserir aluno\n");
    printf("4. Remover turma\n");
    printf("5. Remover disciplina\n");
    printf("6. Remover aluno\n");
    printf("7. Listar turmas\n");
    printf("8. Listar disciplinas\n");
    printf("9. Listar alunos\n");
    printf("0. Sair\n");

    t_curso curso;
    curso.quantidade_turmas = 0;
    curso.turmas = NULL;
    int opcao = obter_opcao_menu();
    processar_opcao_menu(opcao, &curso);

}

