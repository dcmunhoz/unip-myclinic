#ifndef MEDICO_H
#define MEDICO_H

#include <stdlib.h>
#include <stdio.h>

struct medico {
    int crm;
    char nome[50];
    char email[255];
    char cpf[12];
    int clinica;

};

typedef struct medico Medico;

/* 
    Função que realiza o cadastro do médico dentro do arquivo médicos.txt
 */
int gravarMedico(Medico medico){

    FILE *arquivo;
    arquivo = fopen("dados/medicos.txt", "a+");

    if (arquivo == NULL) {
        
        return 0;

    }

    fprintf(arquivo, "%d;%s;%s;%s;%d ", medico.crm, medico.nome, medico.cpf, medico.email, medico.clinica);

    fclose(arquivo);

    return 1;
}

#endif