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

    char username[255];
    char password[255], c, screen[255];

    printf("INFORME SEU USUARIO: ");
    scanf(" %s", username);

    printf("INFORME SUA SENHA: ");
    scanf(" %s", username);

    /* Exibe a senha como asteristico */
    // int i = 0;
    // while ( (c = getch()) != 13 ) // 13 = ENTER na tabela cII
    // {   
        
    //     password[i] = c;

    //     printf("*");
    //     Beep(1500,50);
    //     i++;
    // }
    // password[i] = '\0';
    // i = 0;
    
    // Validar usuário e senha
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

void showNewSchedule(){
    system("cls");
    drawHeader("NOVO AGENDAMENTO");
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
        printf("1 - CADASTRO DE FUNCIONARIOS\n");
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
    drawHeader("CADASTRO DE PACIENTE");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
}

void showViewPacientData(){
    system("cls");

    printf("2 - VISUALIZAR DADOS DO PACIENTE: \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
   
}

void showModifyPatientData(){
    system("cls");

    printf("3 - MODIFICAR DADOS DO PACIENTE: \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
   
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
    drawHeader("CADASTRO DE MEDICO");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
}

void showAddNewUser(){
    system("cls");
    drawHeader("CADASTRO DE FUNCIONARIO");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
}

void showMedicalunit(){
    system("cls");

    printf("5 - UNIDADE MEDICA: \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
       
}

void showFeedback(){
    system("cls");
    drawHeader("RECLAMACOES E ELOGIOS");

    printf("Difgite sua sugestao: \n");
   
}

void leave(){
    system("cls");
    printf("OBRIGADO POR USAR O MYCLINIC, ATE A PROXIMA !!!\n\n");
}





#endif //UNIP_PIM_CLINIC_SCREENS_H
