#ifndef SISTEMA_ACADEMICO_H
#define SISTEMA_ACADEMICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    char *nome;
    long telefone;
    struct Aluno *proximo;
} Aluno;

typedef struct Disciplina {
    int codigo;
    char *nome;
    Aluno *lista_alunos;
    struct Disciplina *proximo;
} Disciplina;

typedef struct Turma {
    int numero;
    Disciplina *lista_disciplinas;
    struct Turma *proximo;
} Turma;

Turma *lista_turmas = NULL;

// Função para inserir uma nova turma
void inserir_turma(int numero);

// Função para inserir uma nova disciplina em uma turma
void inserir_disciplina(int numero_turma, int codigo, char *nome);

// Função para inserir um novo aluno em uma disciplina
void inserir_aluno(int codigo_disciplina, int matricula, char *nome, long telefone);

// Função para remover uma turma
void remover_turma(int numero);

// Função para remover uma disciplina de uma turma
void remover_disciplina(int numero_turma, int codigo);

// Função para remover um aluno de uma disciplina
void remover_aluno(int codigo_disciplina, int matricula);

// Função para listar todas as turmas
void listar_turmas();

// Função para listar todas as disciplinas de uma turma
void listar_disciplinas(int numero_turma);

// Função para listar todos os alunos de uma disciplina
void listar_alunos(int codigo_disciplina);

#endif // SISTEMA_ACADEMICO_H
