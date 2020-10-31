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

int menuChoise;
int nome; 

void drawHeader(char *headerName){
    showWellcome();
    printf("\t\t** %s **\n", headerName);
    printf("-----------------------------------------------------------\n\n");
}

void showWellcome(){
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

    // char *ptrPassword;

    // ptrUsername = malloc(255);

    char username[16], password[16];
    char c;

    printf("INFORME SEU USUARIO: ");
    scanf("%s", username);

    printf("INFORME SUA SENHA: ");
    // scanf("%s", password);

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
    showHome();


}

void showHome(){
    int opcao = 0;

    do {
        system("cls");
        drawHeader("MENU PRINCIPAL");
        printf("1 - NOVO AGENDAMENTO \n");
        printf("2 - VISUALIZAR AGENDAMENTOS \n");
        printf("3 - CANCELAR AGENDAMENTO \n");
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
{   char nome[50]; 
    int i = 0;
    int opcao = 0;
    char nomeMedico[50];
    int data[10];
    float horario[10];
    system("cls");
    
    
        for(i = 0; i < 1; i++){
            drawHeader("NOVO AGENDAMENTO");
            printf("infome o nome do paciente: \n",nome);
            scanf("%s", &nome[i]);
            printf("Informe o nome do medico: ", nomeMedico);
            scanf("%s", &nomeMedico[i]);
            printf("Informe a data da consulta: ", data);
            scanf("%d", &data[i]);
            printf("Informe o horario da consulta: ", horario);
            scanf("%d", &horario[i]);
            printf("Voltar para o menu");

        }
         if (opcao == 0) {
            showHome();
        }

    
}

void showSchedule(){
    system("cls");
    drawHeader("LISTA DE AGENDAMENTOS");

}

void showCancelSchedule(){
    system("cls");
    drawHeader("CANCELAR AGENDAMENTO");
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
    system("cls");
    char nome[50]; 
    int CPF[50]; 
    int telefone[50]; 
    char email[100];
    int i = 0;
    int opcao = 0;
        for(i = 0; i < 1; i++){
            drawHeader("CADASTRO DE PACIENTE");
            printf("infome o nome do paciente: \n",nome);
            scanf("%s", &nome[i]);
            printf("infome o CPF: \n", CPF);
            scanf("%d", &CPF[i]);
            printf("infome o telefone: \n", telefone);
            scanf("%d", &telefone[i]);
            printf("infome E-mail: \n", email);
            scanf("%s", &email[i]);
            printf("Voltar para o menu");

        }
         if (opcao == 0) {
            showHome();
        }

       
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
   
}

void showAddNewDoctor(){
    system("cls");
    int CPF[50], crc[10], telefone[10];
    char email[50], nomeMedico[50];
    int i = 0, opcao = 0;

        for(i = 0; i < 1; i++){
            drawHeader("CADASTRO DE MEDICO");
            printf("infome o nome do medico: \n", nomeMedico);
            scanf("%s", &nomeMedico[i]);
            printf("infome informe crc \n", crc);
            scanf("%d", &crc[i]);
            printf("infome o cpf:\n", CPF);
            scanf("%d", &CPF[i]);
            printf("infome o telefone: \n", telefone);
            scanf("%d", &telefone[i]);
            printf("Informe o E-mail: \n", email);
            scanf("%s", &email[i]);
    }
    if (opcao == 0) {
            showHome();
        }
}

void showAddNewUser(){
    system("cls");   
    char nome[50], cargo[10]; 
    int CPF[50], codigo[10]; 
    int telefone[50]; 
    char email[100];
    int i = 0;
    int opcao = 0;
        for(i = 0; i < 1; i++){
            drawHeader("CADASTRO DE FUNCIONARIO");
            printf("Infome o nome do funcionario: \n",nome);
            scanf("%s", &nome[i]);
            printf("Infome o CPF: \n", CPF);
            scanf("%d", &CPF[i]);
            printf("Infome o telefone: \n", telefone);
            scanf("%d", &telefone[i]);
            printf("Infome E-mail: \n", email);
            scanf("%s", &email[i]);
            printf("Informe o Cargo: \n", cargo);
            scanf("%s", &cargo[i]);
            printf("Informe o Codigo que sera cadastrado: \n", codigo);
            scanf("%d", &codigo[i]);
            

        }
        printf("Voltar para o menu");
         if (opcao == 0) {
            showHome();
        }
}

void showMedicalunit(){
    system("cls");
    int opcao = 0;
    printf("5 - UNIDADE MEDICA: \n");
    for (int i = 0; i < 1; i++)
    {
        printf("Clinica 1 - rua: Lafaiete 779 \n");
        printf("Clinica 2 - rua: Tibirica 1053 \n");
        printf("Clinica 3 - rua: 9 de julho 668 \n");   
    }
    if(opcao == 1){
        opcao = 1;
    } else if (opcao == 2){
        opcao = 2;
    } else if(opcao);
    
       
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
