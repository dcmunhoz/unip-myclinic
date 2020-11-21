//
// Created by daniel.munhoz on 25/09/2020.
//

#ifndef UNIP_PIM_CLINIC_SCREENS_H
#define UNIP_PIM_CLINIC_SCREENS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca para usar a funçao strcmp
#include <windows.h>
#include <conio.h>

#include "source/usuarios.h"
#include "source/agenda.h"
#include "source/medico.h"
#include "source/paciente.h"

void showPrincipal()
{
    int menuChoise = 999;
    do
    {
        system("cls");
        showWellcome();
        showMenu();

        printf("\nESCOLHA: ");
        scanf("%d", &menuChoise);

    } while (menuChoise != 1 && menuChoise != 0);

    if (menuChoise == 1)
    {
        //showLogin();
        showHome();
    }
    else if (menuChoise == 0)
    {
        leave();
    }
}

void drawHeader(char *headerName)
{
    showWellcome();
    printf("\t\t** %s **\n", headerName);
    printf("-----------------------------------------------------------\n\n");
}

void showWellcome()
{
    system("cls");
    // Tela de boas vindas
    printf("|=========================================================|\n");
    printf("\t\tBEM VINDO AO MYCLINIC !!!\n");
    printf("|=========================================================|\n\n");
}

void showMenu()
{
    // Exibir o menu
    printf("ESCOLHA UMA DAS OPCOES: \n\n");
    printf("1 - LOGAR-SE\n");
    printf("0 - SAIR\n");
}

void showLogin()
{

    drawHeader("ACESSAR SISTEMA");

    char username[16], password[16];
    char validUsername[16], validPassword[16];
    char c;
    int userId;
    int userValidated = 0;

    printf("INFORME SEU USUARIO: ");
    scanf("%s", username);

    printf("INFORME SUA SENHA: ");

    /* Exibe a senha como asteristico */
    int i = 0;
    int passwordLenght = 0;
    while ((c = getch()) != 13) // 13 = ENTER na tabela ASCII
    {
        Beep(1500, 50);

        if (c != 8)
        {
            password[i] = c;
            printf("*");
            i++;
            passwordLenght++;
        }
        else
        {
            if (passwordLenght > 0)
            {
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
    FILE *fUsers = fopen("dados/usuarios.txt", "r");

    if (fUsers == NULL)
    {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE USUÁRIOS.");
        exit(1);
    }

    while (!feof(fUsers))
    {
        fscanf(fUsers, "%d %s %s", &userId, validUsername, validPassword);
        if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0)
        {
            userValidated = 1;
        }
    }

    if (userValidated == 1)
    {
        showHome();
    }
    else
    {
        fclose(fUsers);
        printf("\n\nUSUARIO E/OU SENHA INCORRETOS \n\n");
        system("pause");
        system("cls");
        showPrincipal();
    }
}

void showHome()
{
    int opcao = 0;

    do
    {
        system("cls");
        drawHeader("MENU PRINCIPAL");
        printf("1 - NOVO AGENDAMENTO \n");
        printf("2 - VISUALIZAR AGENDAMENTOS \n");
        printf("3 - EDITAR AGENDAMENTO \n");
        printf("4 - CADASTROS \n");
        printf("5 - RELATORIOS \n");
        printf("6 - RECLAMACOES / ELOGIO DO PACIENTE \n");
        printf("0 - SAIR DO MENU...\n");
        printf("\nESCOLHA: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            showNewSchedule();
        }
        else if (opcao == 2)
        {
            showSchedule();
        }
        else if (opcao == 3)
        {
            showEditSchedule();
        }
        else if (opcao == 4)
        {
            showRegisters();
        }
        else if (opcao == 5)
        {
        }
        else if (opcao == 6)
        {
            showFeedback();
        }
        else if (opcao == 0)
        {
            leave();
        }

    } while (opcao < 0 || opcao > 6);
}

void showNewSchedule()
{

    Agenda agenda;
    agenda.unidadeMedica = 0;
    agenda.valorConsulta = 0.0;

    system("cls");

    drawHeader("NOVO AGENDAMENTO");

    printf("Infome o nome do paciente:");
    fflush(stdin);
    gets(agenda.nomePaciente);

    printf("Informe o nome do medico:");
    fflush(stdin);
    gets(agenda.nomeMedico);

    printf("Informe a data da consulta:");
    fflush(stdin);
    gets(agenda.dataAtendimento);

    printf("Informe o horario da consulta:");
    fflush(stdin);
    gets(agenda.horaAtendimento);

    printf("Infome a Clinica:");
    fflush(stdin);
    scanf("%d", &agenda.unidadeMedica);

    printf("Infome o Valor da consulta:");
    fflush(stdin);
    scanf("%f", &agenda.valorConsulta);

    if (gravarAgenda(agenda) == 1)
    {
        showHome();
    }
    else
    {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE AGENDA.");
        exit(1);
    }
}

void showSchedule()
{

    system("cls");
    drawHeader("LISTA DE AGENDAMENTOS");
    listarAgenda();
    system("pause");
    showHome();
}

void showEditSchedule()
{
    int opcao = 0;

    system("cls");
    drawHeader("ALTERAR AGENDAMENTO");

    printf("1 - EDITAR\n2 - CANCELAR\n0 - VOLTAR\n");
    printf("SELECIONE UMA OPCAO >: ");
    scanf("%d", &opcao);
    if (opcao == 1)
    {

        Agenda agenda;

        system("cls");

        drawHeader("EDITAR AGENDAMENTO");
        listarAgenda();
        printf("QUAL ID DESEJA ALTERAR? (0 - SAIR) >: ");
        scanf("%d", &agenda.id);

        if (agenda.id != 0)
        {
            printf("Infome o nome do paciente: ");
            fflush(stdin);
            gets(agenda.nomePaciente);

            printf("Informe o nome do medico: ");
            fflush(stdin);
            gets(agenda.nomeMedico);

            printf("Informe a data da consulta: ");
            fflush(stdin);
            gets(agenda.dataAtendimento);

            printf("Informe o horario da consulta: ");
            fflush(stdin);
            gets(agenda.horaAtendimento);

            printf("Infome a Clinica:");
            fflush(stdin);
            scanf("%d", &agenda.unidadeMedica);

            printf("Infome o Valor da consulta:");
            fflush(stdin);
            scanf("%f", &agenda.valorConsulta);

            if (editarAgenda(agenda) == 0)
            {

                printf("\n \n ** ERRO AO ABRIR AGENDA PARA EDICAO ** \n \n");
                exit(1);
            }

            printf("\n \n AGENDA EDITADA COM SUCESSO !! \n \n");
            system("pause");
        }
    }
    else if (opcao == 2)
    {
        system("cls");
        drawHeader("CANCELAR AGENDAMENTO");

        int idCancel;
        listarAgenda();
        printf("\n QUAL ID DA AGENDA A CANCELAR? (0 - SAIR) >: ");
        scanf("%d", &idCancel);

        if (idCancel != 0)
        {
            if (cancelarAgenda(idCancel) == 0)
            {

                printf("\n \n ** ERRO AO ABRIR AGENDA PARA CANCELAMENTO ** \n \n");
                exit(1);
            }

            printf("\n \n AGENDA EDITADA COM SUCESSO !! \n \n");
            system("pause");
        }
    }
    else if (opcao == 0)
    {
        showHome();
    }

    showHome();
}

void showRegisters()
{
    int opcao = 0;

    do
    {
        system("cls");
        drawHeader("MANU DE CADASTROS");

        printf("1 - CADASTRO DE PACIENTE\n");
        printf("2 - CADASTRO DE MEDICOS\n");
        printf("3 - CADASTRO DE FUNCIONARIOS\n");
        printf("0 - VOLTAR\n\n");
        printf("ESCOLHA: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            showAddPatientRecord();
        }
        else if (opcao == 2)
        {
            showAddNewDoctor();
        }
        else if (opcao == 3)
        {
            showAddNewUser();
        }
        else if (opcao == 0)
        {
            showHome();
        }

    } while (opcao < 0);
}

void showAddPatientRecord()
{
    drawHeader("CADASTRO DE PACIENTE");

    Paciente paciente;
    paciente.id = 0;

    printf("Informe o nome do paciente >: ");
    fflush(stdin);
    gets(paciente.nome);    

    printf("Informe o CPF do paciente (SOMENTE NUMEROS) >: ");
    fflush(stdin);
    gets(paciente.cpf);

    printf("Informe o e-mail do paciente >: ");
    fflush(stdin);
    gets(paciente.email);

    printf("Informe o telefone do paciente (SOMENTE NUMEROS) >: ");
    fflush(stdin);
    gets(paciente.telefone);

    if (gravarPaciente(paciente) == 0) {
        printf("\n\n HOUVE UM ERRO AO TENTAR GRAVAR OS DADOS DO PACIENTE !!! \n\n");
        exit(1);
    } else { 
        printf("DADOS DO PACIENTE FORAM SALVOS !! \n \n");
        system("pause");
    }

    showHome();
}

void showViewPacientData()
{
    system("cls");

    printf("2 - VISUALIZAR DADOS DO PACIENTE: \n");
    //printf("infome o nome que deseja consultar: \n", nome);
    //scanf("%s", &nome);
}

void showModifyPatientData()
{
    system("cls");
    char nome[50];
    int i = 0;

    printf("3 - MODIFICAR DADOS DO PACIENTE: \n");
    printf("infome o nome: \n", nome);
    scanf("%s", &nome[i]);
}

void showAddNewDoctor()
{
    system("cls");
    drawHeader("CADASTRO DE MEDICO");

    Medico medico;
    medico.crm = 0;
    medico.clinica = 0;

    printf("Informe o CRM do medico >: ");
    fflush(stdin);
    scanf("%d", &medico.crm);    
    
    printf("Informe o nome do medico >: ");
    fflush(stdin);
    gets(medico.nome);
    
    printf("Informe o CPF do medico >: ");
    fflush(stdin);
    gets(medico.cpf);

    printf("Informe o e-mail do medico >: ");
    fflush(stdin);
    gets(medico.email);
    
    printf("Informe a clinica de atendimento >: ");
    fflush(stdin);
    scanf("%d", &medico.clinica);

    if (gravarMedico(medico) != 0) {
        printf("\n\n MEDICO CADASTRADO COM SUCESSO !! \n \n");
        system("pause");
    } else {
        printf("HOUVE UM ERRO AO TENTAR GRAVAR O MEDICO !!!");
        exit(1);
    }    


    showHome();
}

void showAddNewUser()
{
    system("cls");
    drawHeader("CADASTRO DE FUNCIONARIO");
    
    showHome();
}

void showMedicalunit()
{
    FILE *agendas;
    agendas = fopen("dados/agendas.txt", "r");
    float valorConsulta;

    system("cls");
    printf("5 - RELATORIOS: \n");

    while (fscanf(agendas, "%f", &valorConsulta) != EOF)
    {
        printf("%f", valorConsulta);
    }
    
    

    //if (agendas != 0)
    //{
    //    
    //    
    //    for (int i=5;i<=5;i++)
    //    {
    //        printf("5 - RELATORIOS: \n");
    //        fseek(agendas, i, SEEK_SET); // vai pra coluna 'i' do arquivo
    //        valorConsulta = fgetc(agendas); // pega o caractere
    //        printf("%d %.2f", valorConsulta); // imprime na tela
    //    }
    //}
}

void showFeedback()
{
    char sugestao[500];
    int i = 0, opcao = 0;
    int feedback;
    char line[255];

    drawHeader("RECLAMACOES E ELOGIOS");

    printf("Difgite sua sugestao: \n");
    fflush(stdin);
    gets(sugestao);
    printf(" Deseja enviar seu feedback? 1 - sim \t 0 - nao ");
    scanf("%d", &feedback);
    FILE *fFeedBack = fopen("dados/feedback.txt", "a+");

    if (fFeedBack == NULL)
    {
        system("CLS");
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO DE FEEDBACK.");
        exit(1);
    }

    fprintf(fFeedBack, "%s\n", sugestao);
    fclose(fFeedBack);

    showHome();
}

void leave()
{
    system("cls");
    printf("OBRIGADO POR USAR O MYCLINIC, ATE A PROXIMA !!!\n\n");
}

#endif //UNIP_PIM_CLINIC_SCREENS_H
