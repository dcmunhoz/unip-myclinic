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

    int ultimoId = ultimoPaciente();

    if (arquivo == NULL) {
        return 0;
    }

    fprintf(arquivo, "%d;%s;%s;%s;%s\n", ultimoId, paciente.nome, paciente.cpf, paciente.email, paciente.telefone);
    fclose(arquivo);


    return 1;
}

int ultimoPaciente(){

    FILE *arquivo;
    arquivo = fopen("dados/pacientes.txt", "r");

    int ultimoId = 0;

    Paciente paciente;
    paciente.id = 0;
    

    if (arquivo == NULL) {
        printf("\n\nERRO AO ABRIR ARQUIVO DE USUARIOS !!\n\n");
        exit(1);
    }

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;]", &paciente.id, paciente.nome, paciente.cpf, paciente.email, paciente.telefone) != EOF)
    {
        ultimoId = paciente.id;
    }  
    

    ultimoId++;
    return ultimoId;

}


#endif