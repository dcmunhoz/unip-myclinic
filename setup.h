#ifndef UNIP_PIM_CLINIC_SETUP_H
#define UNIP_PIM_CLINIC_SETUP_H

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

void setup() {

    // Verifica se a pasta de dados esta criada
    int check = mkdir("dados");

    if (!check) {
        mkdir("dados/tmp");
        printf("* NECESSARIO CRIAR ESTRUTURA DE ARQUIVOS * \n\n");

        // Validar se arquivos de usuários existe
        FILE *usuarios;
        usuarios = fopen("dados/usuarios.txt", "r");
        if (usuarios == NULL) {
            printf("ARQUIVO DE USUARIOS SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/usuarios.txt", "w+");
            fprintf(arquivo, "%d %s %s\n", 1, "admin", "admin");
            fclose(arquivo);
            printf("ARQUIVO DE USUARIOS CRIADO COM SUCESSO !\n");
        }
        fclose(usuarios);

        // Validar se arquivos de medicos existe
        FILE *medicos;
        medicos = fopen("dados/medicos.txt", "r");
        if (medicos == NULL) {
            printf("ARQUIVO DE MEDICOS SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/medicos.txt", "w+");
            fclose(arquivo);
            printf("ARQUIVO DE MEDICOS CRIADO COM SUCESSO !\n");
        }
        fclose(medicos);

        // Validar se arquivos de agendas existe
        FILE *agendas;
        agendas = fopen("dados/agendas.txt", "r");
        if (agendas == NULL) {
            printf("ARQUIVO DE AGENDAS SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/agendas.txt", "w+");
            fclose(arquivo);
            printf("ARQUIVO DE AGENDAS CRIADO COM SUCESSO !\n");
        }
        fclose(agendas);

        // Validar se arquivos de cadastro existe
        FILE *cadastro;
        cadastro = fopen("dados/cadastro.txt", "r");
        if (cadastro == NULL) {
            printf("ARQUIVO DE CADASTRO SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/cadastro.txt", "w+");
            fclose(arquivo);
            printf("ARQUIVO DE CADASTRO CRIADO COM SUCESSO !\n");
        }
        fclose(cadastro);

        // Validar se o arquivo de usuários existe 
        FILE *cadastropaciente;
        cadastropaciente = fopen("dados/pacientes.txt", "r");
        if (cadastropaciente == NULL) {
            printf("ARQUIVO DE PACIENTES SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/pacientes.txt", "w+");
            fclose(arquivo);
            printf("ARQUIVO DE PACIENTES CRIADO COM SUCESSO !\n");
        }
        fclose(cadastropaciente);


        // Verificar se o arquivo de feedback existe
        FILE *feedback;
        feedback = fopen("dados/feedbacks.txt", "r");
        if (feedback == NULL) {
            printf("ARQUIVO DE FEEDBACK SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/feedback.txt", "w+");
            fclose(arquivo);
            printf("ARQUIVO DE FEEDBACK CRIADO COM SUCESSO !\n");
        }
        fclose(feedback);


        printf("ESTRUTURA CRIADA, EXECUTE O PROGRAMA NOVAMENTE \n\n");
        system("pause");
        exit(0);
    }

}

#endif //UNIP_PIM_CLINIC_SETUP_H