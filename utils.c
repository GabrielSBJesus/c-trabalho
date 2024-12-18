#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_academico.h"

void obter_texto(char** texto) {
    char buffer[100];
    scanf("%s", buffer);
    *texto = (char*) malloc(strlen(buffer) * sizeof(char));
    strcpy(*texto, buffer);
};