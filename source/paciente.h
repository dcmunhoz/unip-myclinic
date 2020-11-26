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
    int unidadeMedica;

};

typedef struct paciente Paciente;

int gravarPaciente(Paciente paciente){

    FILE *arquivo;
    arquivo = fopen("dados/pacientes.txt", "a+");

    int ultimoId = ultimoPaciente();

    if (arquivo == NULL) {
        return 0;
    }

    fprintf(arquivo, "%d;%s;%s;%s;%s;%d; \n", ultimoId, paciente.nome, paciente.cpf, paciente.email, paciente.telefone, paciente.unidadeMedica);
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

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%d; ", &paciente.id, paciente.nome, paciente.cpf, paciente.email, paciente.telefone, &paciente.unidadeMedica) != EOF)
    {
        ultimoId = paciente.id;
    }  
    
    ultimoId++;
    return ultimoId;

}

void listarPacientes(){

    FILE *arquivo;
    arquivo = fopen("dados/pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("\n \nERRO AO LISTAR PACIENTES !!! \n \n");
        exit(1);
    }   

    Paciente paciente;
    paciente.id = 0;

    printf(" ID |       NOME PACIENTE       | CPF PACIENTE |      E-MAIL PACIENTE      | TELEFONE PACIENTE  |      UNIDADE \n");
    printf("-----------------------------------------------------------------------------------------------\n");
    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%d; ", &paciente.id, paciente.nome, paciente.cpf, paciente.email, paciente.telefone, &paciente.unidadeMedica) != EOF) {
        printf("%3d | %25s | %12s | %25s | %11s | %13d \n", paciente.id, paciente.nome, paciente.cpf, paciente.email, paciente.telefone, paciente.unidadeMedica);
    }

    fclose(arquivo);

}

int editarPaciente(Paciente pacienteEditado){
    FILE *arquivoLeitura, *arquivoEdicao;
    Paciente pacienteAtual;

    arquivoLeitura = fopen("dados/pacientes.txt", "r");
    arquivoEdicao  = fopen("dados/tmp/pacientes.txt", "w+");

    if (arquivoLeitura == NULL || arquivoEdicao == NULL) {
        return 0;
    }

    while (fscanf(arquivoLeitura, "%d;%[^;];%[^;];%[^;];%[^;];%d; ", &pacienteAtual.id, pacienteAtual.nome, pacienteAtual.cpf, pacienteAtual.email, pacienteAtual.telefone, &pacienteAtual.unidadeMedica) != EOF) {

        if (pacienteAtual.id == pacienteEditado.id) {
            fprintf(arquivoEdicao, "%d;%s;%s;%s;%s;%d; \n", pacienteEditado.id, pacienteEditado.nome, pacienteEditado.cpf, pacienteEditado.email, pacienteEditado.telefone, pacienteEditado.unidadeMedica);
        } else {
            fprintf(arquivoEdicao, "%d;%s;%s;%s;%s;%d; \n", pacienteAtual.id, pacienteAtual.nome, pacienteAtual.cpf, pacienteAtual.email, pacienteAtual.telefone, pacienteAtual.unidadeMedica);
        }

    }

    fclose(arquivoLeitura);
    fclose(arquivoEdicao);

    remove("dados/pacientes.txt");
    rename("dados/tmp/pacientes.txt", "dados/pacientes.txt");

    return 1;
}

int excluirPaciente(int pacienteExcluir){
    FILE *arquivoLeitura, *arquivoEdicao;
    Paciente pacienteAtual;

    arquivoLeitura = fopen("dados/pacientes.txt", "r");
    arquivoEdicao  = fopen("dados/tmp/pacientes.txt", "w+");

    if (arquivoLeitura == NULL || arquivoEdicao == NULL) {
        return 0;
    }

    while (fscanf(arquivoLeitura, "%d;%[^;];%[^;];%[^;];%[^;];%d; ", &pacienteAtual.id, pacienteAtual.nome, pacienteAtual.cpf, pacienteAtual.email, pacienteAtual.telefone, &pacienteAtual.unidadeMedica) != EOF) {

        if (pacienteAtual.id != pacienteExcluir) {
            fprintf(arquivoEdicao, "%d;%s;%s;%s;%s;%d; \n", pacienteAtual.id, pacienteAtual.nome, pacienteAtual.cpf, pacienteAtual.email, pacienteAtual.telefone, pacienteAtual.unidadeMedica);
        }

    }

    fclose(arquivoLeitura);
    fclose(arquivoEdicao);

    remove("dados/pacientes.txt");
    rename("dados/tmp/pacientes.txt", "dados/pacientes.txt");

    return 1;
}


#endif