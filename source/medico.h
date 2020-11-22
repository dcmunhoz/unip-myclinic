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

    fprintf(arquivo, "%d;%s;%s;%s;%d; \n", medico.crm, medico.nome, medico.cpf, medico.email, medico.clinica);

    fclose(arquivo);

    return 1;
}

void listarMedicos(){

    FILE *arquivo;
    arquivo = fopen("dados/medicos.txt", "r");

    if (arquivo == NULL) {
        printf("\n\n ERRO AO LISTAR PACIENTES \n\n");
        exit(0);
    }   

    Medico medico;
    medico.crm = 0;
    medico.clinica = 0;

    printf("    CRM    |        NOME MEDICO        |  CPF MEDICO  |        E-MAIL MEDICO      | CLICINA ATENDIMENTO \n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%d; ", &medico.crm, medico.nome, medico.cpf, medico.email, &medico.clinica) != EOF) {
        printf("%10d | %25s | %12s | %25s | %3d \n", medico.crm, medico.nome, medico.cpf, medico.email, medico.clinica);
    }

    fclose(arquivo);

}

int editarMedico(Medico medicoEdicao) {
    FILE *arquivoLeitura, *arquivoEdicao;
    arquivoLeitura = fopen("dados/medicos.txt", "r");
    arquivoEdicao = fopen("dados/tmp/medicos.txt", "w+");

    if (arquivoLeitura == NULL || arquivoEdicao == NULL) {
        return 0;
    }

    Medico medicoAtual;

    while (fscanf(arquivoLeitura, "%d;%[^;];%[^;];%[^;];%d; ", &medicoAtual.crm, medicoAtual.nome, medicoAtual.cpf, medicoAtual.email, &medicoAtual.clinica) != EOF) {
        if (medicoAtual.crm == medicoEdicao.crm) {
            fprintf(arquivoEdicao, "%d;%s;%s;%s;%d; \n", medicoEdicao.crm, medicoEdicao.nome, medicoEdicao.cpf, medicoEdicao.email, medicoEdicao.clinica);
        } else {
            fprintf(arquivoEdicao, "%d;%s;%s;%s;%d; \n", medicoAtual.crm, medicoAtual.nome, medicoAtual.cpf, medicoAtual.email, medicoAtual.clinica);
        }
    }

    fclose(arquivoLeitura);
    fclose(arquivoEdicao);

    system("pause");
    remove("dados/medicos.txt");
    rename("dados/tmp/medicos.txt", "dados/medicos.txt");

    return 1;
}

int excluirMedico(int medicoExclusao) {
    FILE *arquivoLeitura, *arquivoEdicao;
    arquivoLeitura = fopen("dados/medicos.txt", "r");
    arquivoEdicao = fopen("dados/tmp/medicos.txt", "w+");

    if (arquivoLeitura == NULL || arquivoEdicao == NULL) {
        return 0;
    }

    Medico medicoAtual;

    while (fscanf(arquivoLeitura, "%d;%[^;];%[^;];%[^;];%d; ", &medicoAtual.crm, medicoAtual.nome, medicoAtual.cpf, medicoAtual.email, &medicoAtual.clinica) != EOF) {
        if (medicoAtual.crm != medicoExclusao) {
            fprintf(arquivoEdicao, "%d;%s;%s;%s;%d; \n", medicoAtual.crm, medicoAtual.nome, medicoAtual.cpf, medicoAtual.email, medicoAtual.clinica);
        } 
    }

    fclose(arquivoLeitura);
    fclose(arquivoEdicao);

    remove("dados/medicos.txt");
    rename("dados/tmp/medicos.txt", "dados/medicos.txt");

    return 1;
}

#endif