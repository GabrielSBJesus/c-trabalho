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
void inserir_turma(int numero) {
    Turma *nova_turma = (Turma *)malloc(sizeof(Turma));
    nova_turma->numero = numero;
    nova_turma->lista_disciplinas = NULL;
    nova_turma->proximo = lista_turmas;
    lista_turmas = nova_turma;
}

// Função para inserir uma nova disciplina em uma turma
void inserir_disciplina(int numero_turma, int codigo, char *nome) {
    Turma *turma = lista_turmas;
    while (turma != NULL && turma->numero != numero_turma) {
        turma = turma->proximo;
    }
    if (turma != NULL) {
        Disciplina *nova_disciplina = (Disciplina *)malloc(sizeof(Disciplina));
        nova_disciplina->codigo = codigo;
        nova_disciplina->nome = strdup(nome);
        nova_disciplina->lista_alunos = NULL;
        nova_disciplina->proximo = turma->lista_disciplinas;
        turma->lista_disciplinas = nova_disciplina;
    }
}

// Função para inserir um novo aluno em uma disciplina
void inserir_aluno(int codigo_disciplina, int matricula, char *nome, long telefone) {
    Turma *turma = lista_turmas;
    while (turma != NULL) {
        Disciplina *disciplina = turma->lista_disciplinas;
        while (disciplina != NULL && disciplina->codigo != codigo_disciplina) {
            disciplina = disciplina->proximo;
        }
        if (disciplina != NULL) {
            Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
            novo_aluno->matricula = matricula;
            novo_aluno->nome = strdup(nome);
            novo_aluno->telefone = telefone;
            novo_aluno->proximo = disciplina->lista_alunos;
            disciplina->lista_alunos = novo_aluno;
            return;
        }
        turma = turma->proximo;
    }
}

// Função para remover uma turma
void remover_turma(int numero) {
    Turma *turma_anterior = NULL;
    Turma *turma_atual = lista_turmas;

    // Procurar a turma a ser removida
    while (turma_atual != NULL && turma_atual->numero != numero) {
        turma_anterior = turma_atual;
        turma_atual = turma_atual->proximo;
    }

    // Se a turma foi encontrada
    if (turma_atual != NULL) {
        // Remover todas as disciplinas da turma
        Disciplina *disciplina_atual = turma_atual->lista_disciplinas;
        while (disciplina_atual != NULL) {
            Disciplina *disciplina_remover = disciplina_atual;
            disciplina_atual = disciplina_atual->proximo;
            free(disciplina_remover->nome);
            free(disciplina_remover);
        }

        // Remover a turma
        if (turma_anterior != NULL) {
            turma_anterior->proximo = turma_atual->proximo;
        } else {
            lista_turmas = turma_atual->proximo;
        }
        free(turma_atual);
    }
}

// Função para remover uma disciplina de uma turma
void remover_disciplina(int numero_turma, int codigo) {
    Turma *turma = lista_turmas;

    // Procurar a turma
    while (turma != NULL && turma->numero != numero_turma) {
        turma = turma->proximo;
    }

    // Se a turma foi encontrada
    if (turma != NULL) {
        Disciplina *disciplina_anterior = NULL;
        Disciplina *disciplina_atual = turma->lista_disciplinas;

        // Procurar a disciplina a ser removida
        while (disciplina_atual != NULL && disciplina_atual->codigo != codigo) {
            disciplina_anterior = disciplina_atual;
            disciplina_atual = disciplina_atual->proximo;
        }

        // Se a disciplina foi encontrada
        if (disciplina_atual != NULL) {
            // Remover todos os alunos da disciplina
            Aluno *aluno_atual = disciplina_atual->lista_alunos;
            while (aluno_atual != NULL) {
                Aluno *aluno_remover = aluno_atual;
                aluno_atual = aluno_atual->proximo;
                free(aluno_remover->nome);
                free(aluno_remover);
            }

            // Remover a disciplina
            if (disciplina_anterior != NULL) {
                disciplina_anterior->proximo = disciplina_atual->proximo;
            } else {
                turma->lista_disciplinas = disciplina_atual->proximo;
            }
            free(disciplina_atual->nome);
            free(disciplina_atual);
        }
    }
}

// Função para remover um aluno de uma disciplina
void remover_aluno(int codigo_disciplina, int matricula) {
    Turma *turma = lista_turmas;

    // Procurar a turma
    while (turma != NULL) {
        Disciplina *disciplina = turma->lista_disciplinas;

        // Procurar a disciplina
        while (disciplina != NULL && disciplina->codigo != codigo_disciplina) {
            disciplina = disciplina->proximo;
        }

        // Se a disciplina foi encontrada
        if (disciplina != NULL) {
            Aluno *aluno_anterior = NULL;
            Aluno *aluno_atual = disciplina->lista_alunos;

            // Procurar o aluno a ser removido
            while (aluno_atual != NULL && aluno_atual->matricula != matricula) {
                aluno_anterior = aluno_atual;
                aluno_atual = aluno_atual->proximo;
            }

            // Se o aluno foi encontrado
            if (aluno_atual != NULL) {
                // Remover o aluno
                if (aluno_anterior != NULL) {
                    aluno_anterior->proximo = aluno_atual->proximo;
                } else {
                    disciplina->lista_alunos = aluno_atual->proximo;
                }
                free(aluno_atual->nome);
                free(aluno_atual);
            }
            return;
        }
        turma = turma->proximo;
    }
}

// Função para listar todas as turmas
void listar_turmas() {
    Turma *turma = lista_turmas;

    // Percorrer todas as turmas
    while (turma != NULL) {
        printf("Turma: %d\n", turma->numero);

        Disciplina *disciplina = turma->lista_disciplinas;

        // Percorrer todas as disciplinas da turma
        while (disciplina != NULL) {
            printf("Disciplina: %d\n", disciplina->codigo);

            Aluno *aluno = disciplina->lista_alunos;

            // Percorrer todos os alunos da disciplina
            while (aluno != NULL) {
                printf("Aluno: %d\n", aluno->matricula);
                aluno = aluno->proximo;
            }

            disciplina = disciplina->proximo;
        }

        turma = turma->proximo;
    }
}

// Função para listar todas as disciplinas de uma turma
void listar_disciplinas(int numero_turma) {
    Turma *turma = lista_turmas;

    // Procurar a turma
    while (turma != NULL && turma->numero != numero_turma) {
        turma = turma->proximo;
    }

    // Se a turma foi encontrada
    if (turma != NULL) {
        Disciplina *disciplina = turma->lista_disciplinas;

        // Percorrer todas as disciplinas da turma
        while (disciplina != NULL) {
            printf("Disciplina: %d\n", disciplina->codigo);

            Aluno *aluno = disciplina->lista_alunos;

            // Percorrer todos os alunos da disciplina
            while (aluno != NULL) {
                printf("Aluno: %d\n", aluno->matricula);
                aluno = aluno->proximo;
            }

            disciplina = disciplina->proximo;
        }
    }
}

// Função para listar todos os alunos de uma disciplina
void listar_alunos(int codigo_disciplina) {
    Turma *turma = lista_turmas;

    // Procurar a turma
    while (turma != NULL) {
        Disciplina *disciplina = turma->lista_disciplinas;

        // Procurar a disciplina
        while (disciplina != NULL && disciplina->codigo != codigo_disciplina) {
            disciplina = disciplina->proximo;
        }

        // Se a disciplina foi encontrada
        if (disciplina != NULL) {
            Aluno *aluno = disciplina->lista_alunos;

            // Percorrer todos os alunos da disciplina
            while (aluno != NULL) {
                printf("Aluno: %d\n", aluno->matricula);
                aluno = aluno->proximo;
            }
            return;
        }
        turma = turma->proximo;
    }
}
