#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_academico.h"

void inserir_turma(t_curso* curso) {
    int numeroDaTurma;
    t_turma nova_turma;

    printf("Informe o número da turma: ");
    scanf("%d", &numeroDaTurma);

    if (existe_turma(curso, numeroDaTurma)) {
        printf("Turma já existe.\n");
        return;
    }

    nova_turma.numero = numeroDaTurma;
    nova_turma.quantidade_disciplinas = 0;
    nova_turma.disciplinas = NULL;

    curso->quantidade_turmas++;
    curso->turmas = (t_turma*) realloc(curso->turmas, curso->quantidade_turmas * sizeof(t_turma));
    curso->turmas[curso->quantidade_turmas - 1] = nova_turma;

    listar_turmas(curso);

    printf("Turma inserida com sucesso.\n");
}

void inserir_disciplina(t_turma* turma, t_curso* curso) {
    int codigo;
    int codigoTurma;
    char* nome;

    listar_turmas(curso);

    printf("Escolha uma turma: ");
    scanf("%d", &codigoTurma);

    if (existe_disciplina(turma, codigo)) {
        printf("Disciplina já existe.\n");

        exibir_menu();
        return;
    }

    obter_texto(&nome);

    t_disciplina disciplina;
    disciplina.codigo = codigo;
    disciplina.nome = nome;
    disciplina.quantidade_alunos = 0;
    disciplina.alunos = NULL;

    turma->quantidade_disciplinas++;
    turma->disciplinas = (t_disciplina*) realloc(turma->disciplinas, turma->quantidade_disciplinas * sizeof(t_disciplina));
    turma->disciplinas[turma->quantidade_disciplinas - 1] = disciplina;
};

void inserir_aluno(t_disciplina* disciplina, t_curso* curso) {
    int matricula;
    char* nome;
    long int telefone;

    listar_turmas(curso);

    printf("Informe a matricula do aluno: ");
    scanf("%d", &matricula);

    if (existe_aluno(disciplina, matricula)) {
        printf("Aluno já existe.\n");
        return;
    }

    obter_texto(&nome);

    printf("Informe o telefone do aluno: ");
    scanf("%ld", &telefone);

    t_aluno aluno;
    aluno.matricula = matricula;
    aluno.nome = nome;
    aluno.telefone = telefone;

    disciplina->quantidade_alunos++;
    disciplina->alunos = (t_aluno*) realloc(disciplina->alunos, disciplina->quantidade_alunos * sizeof(t_aluno));
    disciplina->alunos[disciplina->quantidade_alunos - 1] = aluno;
};

void remover_turma(t_curso* curso, t_turma* turma) {
    for (int i = 0; i < curso->quantidade_turmas; i++) {
        if (&curso->turmas[i] == turma) {
            for (int j = i; j < curso->quantidade_turmas - 1; j++) {
                curso->turmas[j] = curso->turmas[j + 1];
            }
            curso->quantidade_turmas--;
            curso->turmas = (t_turma*) realloc(curso->turmas, curso->quantidade_turmas * sizeof(t_turma));
            break;
        }
    }
};

void remover_disciplina(t_turma* turma, t_disciplina* disciplina) {
    for (int i = 0; i < turma->quantidade_disciplinas; i++) {
        if (&turma->disciplinas[i] == disciplina) {
            for (int j = i; j < turma->quantidade_disciplinas - 1; j++) {
                turma->disciplinas[j] = turma->disciplinas[j + 1];
            }
            turma->quantidade_disciplinas--;
            turma->disciplinas = (t_disciplina*) realloc(turma->disciplinas, turma->quantidade_disciplinas * sizeof(t_disciplina));
            break;
        }
    }
};

void remover_aluno(t_disciplina* disciplina, t_aluno* aluno) {
    for (int i = 0; i < disciplina->quantidade_alunos; i++) {
        if (&disciplina->alunos[i] == aluno) {
            for (int j = i; j < disciplina->quantidade_alunos - 1; j++) {
                disciplina->alunos[j] = disciplina->alunos[j + 1];
            }
            disciplina->quantidade_alunos--;
            disciplina->alunos = (t_aluno*) realloc(disciplina->alunos, disciplina->quantidade_alunos * sizeof(t_aluno));
            break;
        }
    }
};

void listar_turmas(t_curso* curso) {
    for (int i = 0; i < curso->quantidade_turmas; i++) {
        printf("Turma: %d\n", curso->turmas[i].numero);
    }
};
void listar_disciplinas(t_turma* turma) {
    for (int i = 0; i < turma->quantidade_disciplinas; i++) {
        printf("Disciplina: %d\n", turma->disciplinas[i].codigo);
    }
};
void listar_alunos(t_disciplina* disciplina) {
    for (int i = 0; i < disciplina->quantidade_alunos; i++) {
        printf("Aluno: %d\n", disciplina->alunos[i].matricula);
    }
};

t_turma* obter_turma(t_curso* curso) {
    int numero;
    printf("Informe o número da turma: ");
    scanf("%d", &numero);

    for (int i = 0; i < curso->quantidade_turmas; i++) {
        if (curso->turmas[i].numero == numero) {
            return &curso->turmas[i];
        }
    }
    return NULL;
};

t_disciplina* obter_disciplina(t_turma *turma) {
    int codigo;
    printf("Informe o código da disciplina: ");
    scanf("%d", &codigo);

    for (int i = 0; i < turma->quantidade_disciplinas; i++) {
        if (turma->disciplinas[i].codigo == codigo) {
            return &turma->disciplinas[i];
        }
    }
    return NULL;
};

t_aluno* obter_aluno(t_disciplina* disciplina) {
    int matricula;
    printf("Informe a matricula do aluno: ");
    scanf("%d", &matricula);

    for (int i = 0; i < disciplina->quantidade_alunos; i++) {
        if (disciplina->alunos[i].matricula == matricula) {
            return &disciplina->alunos[i];
        }
    }
    return NULL;
};

void liberar_memoria_curso(t_curso* curso) {
    free(curso->turmas);
};

void liberar_memoria_turma(t_turma turma) {
    free(turma.disciplinas);
};

void liberar_memoria_disciplina(t_disciplina disciplina) {
    free(disciplina.nome);
    free(disciplina.alunos);
};

void liberar_memoria_aluno(t_aluno aluno) {
    free(aluno.nome);
};

int existe_turma(t_curso* curso, int numero) {
    for (int i = 0; i < curso->quantidade_turmas; i++) {
        if (curso->turmas[i].numero == numero) {
            return 1;
        }
    }
    return 0;

};

int existe_disciplina(t_turma* turma, int codigo) {
    for (int i = 0; i < turma->quantidade_disciplinas; i++) {
        if (turma->disciplinas[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
};

int existe_aluno(t_disciplina* disciplina, int matricula) {
    for (int i = 0; i < disciplina->quantidade_alunos; i++) {
        if (disciplina->alunos[i].matricula == matricula) {
            return 1;
        }
    }
    return 0;
};