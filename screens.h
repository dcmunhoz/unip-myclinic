//
// Created by daniel.munhoz on 25/09/2020.
//

#ifndef UNIP_PIM_CLINIC_SCREENS_H
#define UNIP_PIM_CLINIC_SCREENS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h> //Biblioteca para usar a funçao strcmp
#include<windows.h>
#include<conio.h>

#include "source/usuarios.h"
#include "source/agenda.h"

int menuChoise;
int nome; 

void showPrincipal(){
    menuChoise = 999;
    do{
        system("cls");
        showWellcome();
        showMenu();

        printf("\nESCOLHA: ");
        scanf("%d", &menuChoise);

    } while (menuChoise != 1 && menuChoise != 0);

    if (menuChoise == 1) {
        showLogin();
    } else if (menuChoise == 0) {
        leave();
    }

}

void drawHeader(char *headerName){
    showWellcome(); 
    printf("\t\t** %s **\n", headerName);
    printf("-----------------------------------------------------------\n\n");
}

void showWellcome(){
    system("cls");
    // Tela de boas vindas
    printf("|=========================================================|\n");
    printf("\t\tBEM VINDO AO MYCLINIC !!!\n");
    printf("|=========================================================|\n\n");
}

void showMenu(){
    // Exibir o menu
    printf("ESCOLHA UMA DAS OPCOES: \n\n");
    printf("1 - LOGAR-SE\n");
    printf("0 - SAIR\n");
}


void showLogin(){

    drawHeader("ACESSAR SISTEMA");
   
    char username[16], password[16];
    char validUsername[16], validPassword[16];
    char c;
    int userId;

    printf("INFORME SEU USUARIO: ");
    scanf("%s", username);

    printf("INFORME SUA SENHA: ");
    
    /* Exibe a senha como asteristico */
    int i = 0;
    int passwordLenght = 0;
    while ( (c = getch()) != 13 ) // 13 = ENTER na tabela ASCII
    {   
        Beep(1500,50);
        
        if (c != 8) {
            password[i] = c;
            printf("*");
            i++;
            passwordLenght++;
        } else {
            if (passwordLenght > 0) {
                i--;
                passwordLenght--;
                password[i] = '\0';
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            
        }
    }
    password[i] = '\0';
    i = 0;
    passwordLenght = 0;

    //Validar usuário e senha
    FILE * fUsers = fopen("dados/usuarios.txt", "r");

    if (fUsers == NULL) {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE USUÁRIOS.");
        exit(1);
    }

    while (!feof(fUsers)) { 
        fscanf(fUsers, "%d %s %s", &userId, validUsername, validPassword);
        if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
            showHome();
        }
    }
    fclose(fUsers);
    
    printf("\n\nUSUARIO E/OU SENHA INCORRETOS \n\n");
    system("pause");
    system("cls");
    showPrincipal();


}

void showHome(){
    int opcao = 0;

    do {
        system("cls");
        drawHeader("MENU PRINCIPAL");
        printf("1 - NOVO AGENDAMENTO \n");
        printf("2 - VISUALIZAR AGENDAMENTOS \n");
        printf("3 - ALTERAR AGENDAMENTO \n");
        printf("4 - CADASTROS \n");
        printf("5 - RELATORIOS \n");
        printf("6 - RECLAMACOES / ELOGIO DO PACIENTE \n");
        printf("0 - SAIR DO MENU...\n");
        printf("\nESCOLHA: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            showNewSchedule();
        } else if (opcao == 2) {
            showSchedule();
        } else if (opcao == 3) {
            showCancelSchedule();
        } else if (opcao == 4) {
            showRegisters();
        } else if (opcao == 5) {
            
        } else if (opcao == 6) {
            showFeedback();
        } else if (opcao == 0){
            leave();
        }

    } while(opcao < 0 || opcao > 6);
}

void showNewSchedule()
{   

    Agenda agenda;
    
    char nome[253]; 
    char nomeMedico[255]; 
    char data[255];
    char horario[255];
    char line[255];
    system("cls");

    drawHeader("NOVO AGENDAMENTO");

    printf("Infome o nome do paciente: ");
    // scanf("%s", agenda.nomePaciente);
    fflush(stdin);
    gets(agenda.nomePaciente);
    
    printf("Informe o nome do medico: ");
    // scanf("%s", agenda.nomeMedico);
    gets(agenda.nomeMedico);

    printf("Informe a data da consulta: ");
    // scanf("%s", agenda.dataAtendimento);
    gets(agenda.dataAtendimento);

    printf("Informe o horario da consulta: ");
    // scanf("%s", agenda.horaAtendimento);
    gets(agenda.horaAtendimento);

    if( gravarAgenda(agenda) == 1 ){
        showHome();
    } else {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE AGENDA.");
        exit(1);
    }

}

void showSchedule(){
    char nome[253]; 
    char nomeMedico[255]; 
    char data[255];
    char horario[255];
    char line;

    system("cls");
    drawHeader("LISTA DE AGENDAMENTOS");

    int idUltimaAgenda = ultimaAgenda();

    printf("%d -> ", idUltimaAgenda);

    system("pause");

    // FILE * agendas = fopen("dados/agendas.txt", "r");

    // if (agendas != NULL) {
    //     while (fscanf(agendas, "%s %s %s %s ",&nome, nomeMedico, data, horario)!= EOF )
    //     {
    //         printf(" %s %s %s %s\n", nome, nomeMedico, data, horario);
    //     }
        
    // }
    // system("pause");

    // showHome();
   
    // fputs(line, agendas);
    // fclose(agendas);

   
}

void showCancelSchedule(){
    int opcao = 0;
    char nome[253]; 
    char nomeMedico[255]; 
    char data[255];
    char horario[255];
    char line;
    system("cls");
    drawHeader("ALTERAR AGENDAMENTO");

    printf("1 - Alterar\n2 - Cancelar\n");
    printf("Deseja alterar informacoes: ");
    scanf("%d", &opcao);
    if(opcao == 1){
        FILE * agendas = fopen("dados/agendas.txt", "r");
        
        if (agendas != NULL) {
        while (fscanf(agendas, "%s %s %s %s ",&nome, nomeMedico, data, horario)!= EOF )
        {
            printf(" %s %s %s %s\n", nome, nomeMedico, data, horario);
        }
        
        }
    }else if(opcao == 2){
        FILE * agendas = fopen("dados/agendas.txt", "r");

        if (agendas != NULL) {
        while (fscanf(agendas, "%s %s %s %s ",&nome, nomeMedico, data, horario)!= EOF )
        {
            printf(" %s %s %s %s\n", nome, nomeMedico, data, horario);
        }
        
        }
    }
    system("pause");

    showHome();
}

void showRegisters() {
    int opcao = 0;

    do { 
        system("cls");
        drawHeader("MANU DE CADASTROS");
        
        printf("1 - CADASTRO DE PACIENTE\n");
        printf("2 - CADASTRO DE MEDICOS\n");
        printf("3 - CADASTRO DE FUNCIONARIOS\n");
        printf("0 - VOLTAR\n\n");
        printf("ESCOLHA: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            showAddPatientRecord();
        } else if (opcao == 2) {
            showAddNewDoctor();
        } else if (opcao == 3) {
            showAddNewUser();
        } else if (opcao == 0) {
            showHome();
        }

    } while(opcao < 0);
}

void showAddPatientRecord(){
    char nome[253]; 
    char cpf[255]; 
    char telefone[255]; 
    char email[255];
    char line[255];
    system("cls");

    drawHeader("CADASTRO DE PACIENTE");
    printf("infome o nome do paciente: ");
    scanf("%s", nome);
    strcat(line, nome);
    strcat(line, "; ");

    printf("infome o CPF: ");
    scanf("%s", cpf);
    strcat(line, cpf);
    strcat(line, "; ");

    printf("infome o telefone: ");
    scanf("%s", telefone);
    strcat(line, telefone);
    strcat(line, "; ");

    printf("infome E-mail: ");
    scanf("%s", email);
    strcat(line, email);
    strcat(line, "; \n");

    FILE * fPaciente = fopen("dados/cadastro paciente.txt", "a+");

    if (fPaciente == NULL) {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE USUÁRIOS.");
        exit(1);
    }
    
    fputs(line, fPaciente);
    fclose(fPaciente);

    showHome();
               
}

void showViewPacientData(){
    system("cls");

    printf("2 - VISUALIZAR DADOS DO PACIENTE: \n");
    printf("infome o nome que deseja consultar: \n", nome);
    scanf("%s", &nome);

   
}

void showModifyPatientData(){
    system("cls");
    char nome[50];
    int i=0;

    printf("3 - MODIFICAR DADOS DO PACIENTE: \n");
    printf("infome o nome: \n", nome);
    scanf("%s", &nome[i]);

   
}

void showDeletepatientData(){
    system("cls");

    printf("4 - EXCLUIR DADOS DO PACIENTE: \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    FILE * fCadas = fopen("dados/cadastro.txt", "r");

    if (fCadas == NULL) {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE USUÁRIOS.");
        exit(1);
    }
   
}

void showAddNewDoctor(){

    char nomeMedico[255];
    char crc[255];
    char CPF[255];
    char telefone[252];
    char email[252];
    char line[255];
    system("cls");

        
    drawHeader("CADASTRO DE MEDICO");
    printf("Infome o nome do medico: ");
    scanf("%s", nomeMedico);
    strcat(line, nomeMedico);
    strcat(line, "; ");
    printf("Informe informe crc: ");
    scanf("%s", crc);
    strcat(line, crc);
    strcat(line, "; ");
    printf("Informe o cpf:");
    scanf("%s", CPF);
    strcat(line, CPF);
    strcat(line, "; ");
    printf("Informe o telefone: ");
    scanf("%s", telefone);
    strcat(line, telefone);
    strcat(line, "; ");
    printf("Informe o E-mail: ");
    scanf("%s", email);
    strcat(line, email);
    strcat(line, "; \n");
    
    FILE * fCadas = fopen("dados/cadastro.txt", "a+");

    if (fCadas == NULL) {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE USUÁRIOS.");
        exit(1);
    }
    
    fputs(line, fCadas);
    fclose(fCadas);

    showHome();
        
}

void showAddNewUser(){
    system("cls");   
    char nome[253], cargo[255]; 
    char CPF[255], codigo[255]; 
    char telefone[255]; 
    char email[255];
    char line[255];
        
    drawHeader("CADASTRO DE FUNCIONARIO");
    printf("Informe o nome do funcionario: ");
    scanf("%s", nome);
    strcat(line, nome);
    strcat(line, "; ");
    printf("Infome o CPF: ");
    scanf("%s", CPF);
    strcat(line, CPF);
    strcat(line, "; ");
    printf("Infome o telefone: ");
    scanf("%s", telefone);
    strcat(line, telefone);
    strcat(line, "; ");
    printf("Infome E-mail: ");
    scanf("%s", email);
    strcat(line, email);
    strcat(line, "; ");
    printf("Informe o Cargo: ");
    scanf("%s", cargo);
    strcat(line, cargo);
    strcat(line, "; ");
    printf("Informe o Codigo que sera cadastrado: ");
    scanf("%s", codigo);
    strcat(line, codigo);
    strcat(line, "; \n");
    FILE * fCadasfun = fopen("dados/cadastro.txt", "a+");

    if (fCadasfun == NULL) {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE USUÁRIOS.");
        exit(1);
    }
    
    fputs(line, fCadasfun);
    fclose(fCadasfun);

        
    showHome();
       
}

void showMedicalunit(){    
    int opcao = 0;

    system("cls");
    printf("5 - RELATORIOS: \n");
    
}

void showFeedback(){
    system("cls");
    char sugestao [500];
    int i =0, opcao = 0;
    int fedback;
    drawHeader("RECLAMACOES E ELOGIOS");

    printf("Difgite sua sugestao: \n", sugestao);
    scanf("%s", &sugestao[i]);
    printf(" Deseja enviar seu fedback? 1 - sim \t 0 - nao ", fedback);
    scanf("%d", &fedback);
        if (opcao == 0) {
            showHome();
        }else if(opcao == 1){
            opcao = 1;
        }
   
}

void leave(){
    system("cls");
    printf("OBRIGADO POR USAR O MYCLINIC, ATE A PROXIMA !!!\n\n");
}





#endif //UNIP_PIM_CLINIC_SCREENS_H
