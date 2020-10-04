#ifndef UNIP_PIM_CLINIC_SETUP_H
#define UNIP_PIM_CLINIC_SETUP_H

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

void setup() {

    // Verifica se a pasta de dados esta criada
    int check = mkdir("dados");

    if (!check) {
        printf("* NECESSARIO CRIAR ESTRUTURA DE ARQUIVOS * \n\n");

        // Validar se arquivos de usuários existe
        FILE *usuarios;
        usuarios = fopen("dados/usuarios.txt", "r");
        if (usuarios == NULL) {
            printf("ARQUIVO DE USUARIOS SENDO CRIADO..... \n");
            FILE *arquivo;
            arquivo = fopen("dados/usuarios.txt", "w+");
            fputs("admin;admin", arquivo);
            fclose(arquivo);
            printf("ARQUIVO DE USUARIOS CRIADO COM SUCESSO !\n");
        }
        fclose(usuarios);

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




        printf("ESTRUTURA CRIADA, EXECUTE O PROGRAMA NOVAMENTE \n\n");
        system("pause");
        exit(0);
    }

}

#endif //UNIP_PIM_CLINIC_SETUP_H