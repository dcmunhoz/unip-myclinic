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

void showWellcome(){
    // Tela de boas vindas
    printf("***************************************\n");
    printf("      Bem Vindo ao MyClinic !!!\n");
    printf("***************************************\n\n");
}

void showMenu(){
    // Exibir o menu
    printf("ESCOLHA UMA DAS OPCOES INICIAIS: \n");
    printf("1 - LOGAR-SE\n");
    printf("0 - SAIR\n");
}

void showLogin(){
    char username[255];
    char password[255], c, screen[255];

    showWellcome();
    printf("INFORME SEU USUARIO: ");
    scanf(" %s", username);

    printf("INFORME SUA SENHA: ");
    int i = 0;
    while ( (c = getch()) != 13 ) // 13 = ENTER na tabela cII
    {   
        
        password[i] = c;

        printf("*");
        Beep(1500,50);
        i++;
    }
    password[i] = '\0';
    i = 0;
    
    // Validar usuário e senha
    showHome();
}
void showHome(){

    int num = 0;

    system("cls");

    printf("\t\t\tCADASTRO DE PACIENTES - CLINICA\n\n\n\n");
		printf("|=========================================================|\n");
		printf(	"		1 - CADASTRO DE PACIENTE: \n");
		printf("|---------------------------------------------------------|\n");
		printf(	"		2 - VISUALIZAR DADOS DO PACIENTE: \n");
		printf("|---------------------------------------------------------|\n");
		printf(	"		3 - MODIFICAR DADOS DO PACIENTE: \n");
		printf("|---------------------------------------------------------|\n");
		printf(	"		4 - EXCLUIR DADOS DO PACIENTE: \n");
		printf("|---------------------------------------------------------|\n");
		printf(	"		5 - UNIDADE MEDICA: \n");
		printf("|---------------------------------------------------------|\n");
		printf(	"		6 - RECLAMACOES / ELOGIO DO PACIENTE: \n");
		printf("|---------------------------------------------------------|\n");
		printf("		0 - SAIR DO MENU...\n");
		printf("|=========================================================|\n");
        scanf("%d", &num);

    if(num == 1){
        showPatientRecord();
        
    }   else if( num == 2){
        showViewPacientData();
    }   else if( num == 3){
        showModifyPatientData();
    }   else if( num == 4){
        showDeletepatientData();
    }   else if( num == 5){
        showMedicalunit();
    }   else if( num == 6){
        showfeedback();
    }   else if( num == 0){
        showGetout();
    }


}

void showPatientRecord(){
    system("cls");

    printf("1 - CADASTRO DE PACIENTE: \n");
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
void showMedicalunit(){
    system("cls");

    printf("5 - UNIDADE MEDICA: \n");
    printf("infome \n");
    printf("infome \n");
    printf("infome \n");
       
}

void showfeedback(){
    system("cls");

    printf("6 - RECLAMACOES / ELOGIO DO PACIENTE: \n");
    printf("Difgite sua sugestao: \n");
   
}

void showGetout(){
    system("cls");

    printf("0 - SAIR DO MENU... \n");
   
}
#endif //UNIP_PIM_CLINIC_SCREENS_H
