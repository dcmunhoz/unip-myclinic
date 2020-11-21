#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdlib.h>
#include <stdio.h>

struct paciente {
    int id;
    char nome[50];
    char cpf[12];
    char telefone[12];
    char email[255];

};

typedef struct paciente Paciente;

int gravarPaciente(Paciente paciente){

    FILE *arquivo;
    arquivo = fopen("dados/pacientes.txt", "a+");

    if (arquivo == NULL) {
        return 0;
    }

    fprintf(arquivo, "%d;%s;%s;%s;%s", paciente.id, paciente.nome, paciente.cpf, paciente.email, paciente.telefone);
    fclose(arquivo);


    return 1;
}


#endif