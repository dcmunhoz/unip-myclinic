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

#include "usuarios.h"
#include "agenda.h"
#include "medico.h"
#include "paciente.h"


int defaultUserClinic = 0;

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
        showLogin();
        
    }
    else if (menuChoise == 0)
    {
        exit(1);
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
    int userId, userClinic;
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
        fscanf(fUsers, "%d %s %s %d", &userId, validUsername, validPassword, &userClinic);
        if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0)
        {
            userValidated = 1;
        }
    }

    if (userValidated == 1)
    {
        defaultUserClinic = userClinic;
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
            showMedicalunit();
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

/* ==== AGENDA ==== */

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
        drawHeader("MENU DE CADASTROS");

        printf("1 - CADASTRO DE PACIENTE\n");
        printf("2 - CADASTRO DE MEDICOS\n");
        printf("3 - CADASTRO DE FUNCIONARIOS\n");
        printf("0 - VOLTAR\n\n");
        printf("ESCOLHA: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            showPatientMenu();
        }
        else if (opcao == 2)
        {
            showDoctorMenu();
        }
        else if (opcao == 3)
        {
            showUserMenu();
        }
        else if (opcao == 0)
        {
            showHome();
        }

    } while (opcao < 0);
}

/* ==== PACIENTES ==== */

void showPatientMenu(){
    int opcao = 0;
    drawHeader("MENU DE PACIENTES");

    printf("O QUE DESEJA FAZER ? \n \n");
    printf("1 - CADASTRAR PACIENTES \n");
    printf("2 - LISTAR PACIENTES \n");
    printf("3 - EDITAR PACIENTES \n");
    printf("4 - EXCLUIR PACIENTES \n");
    printf("0 - VOLTAR \n\n");

    printf("ESCOLHA >: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            showAddPatient();
        break;
        case 2:
            showListPatient();
        break;
        case 3:
            showEditPatient();
        break;
        case 4:
            showRemovePatient();
        break;
        case 0:
            showHome();
        break;
        default:
            showHome();
        break;
    }

}

void showAddPatient()
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

    printf("Informe a unidade Medica >: ");
    fflush(stdin);
    scanf("%d", &paciente.unidadeMedica);

    if (gravarPaciente(paciente) == 0) {
        printf("\n\n HOUVE UM ERRO AO TENTAR GRAVAR OS DADOS DO PACIENTE !!! \n\n");
        exit(1);
    } else { 
        printf("DADOS DO PACIENTE FORAM SALVOS !! \n \n");
        system("pause");
    }

    showPatientMenu();
}

void showListPatient()
{
    drawHeader("LISTAGEM PACIENTES");
    listarPacientes();
    system("pause");
    showPatientMenu();
}

void showEditPatient()
{
    drawHeader("EDITAR PACIENTE");
    listarPacientes();

    int pacienteEdicao = 0;

    printf("Qual paciente deseja editar? (0 - VOLTAR) >:");
    scanf("%d", &pacienteEdicao);

    Paciente paciente;
    paciente.id = pacienteEdicao;

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

    printf("Informe a unidade Medica >: ");
    fflush(stdin);
    scanf("%d", &paciente.unidadeMedica);



    if (editarPaciente(paciente) == 0) {
        printf("\n \n HOUVE UM ERRO AO TENTAR EDITAR OS DADOS DO PACIENTE !!! \n\n");
        exit(1);
    } else { 
        printf("DADOS DO PACIENTE FORAM SALVOS !! \n \n");
        system("pause");
    }

    showPatientMenu();
}

void showRemovePatient(){
    drawHeader("EXCLUSAO DE PACIENTE");
    listarPacientes();

    int pacienteExcluir;
    printf("Qual ID do paciente a remover? (0 - VOLTAR) >: ");
    scanf("%d", &pacienteExcluir);

    if (pacienteExcluir != 0) {

        if (excluirPaciente(pacienteExcluir) == 0) {
            printf("ERRO AO EXCLUIR O PACIENTE");
            exit(1);
        } else {
            printf("\n\nO PACIENTE FOI EXCLUIDO COM SUCESSO !! \n\n");
            system("pause");
        }

    }

    showPatientMenu();

}

/* ==== MEDICOS ==== */

void showDoctorMenu() {

    drawHeader("MENU DE MEDICOS");

    int opcao = 0;

    printf("O QUE DESEJA FAZER ?\n\n");
    printf("1 - CADASTRAR MEDICO \n");
    printf("2 - LISTAR MEDICO \n");
    printf("3 - EDITAR MEDICO \n");
    printf("4 - REMOVER MEDICO \n");
    printf("0 - VOLTAR \n");
    printf("ESCOLHA >: ");
    scanf("%d", &opcao);


    switch(opcao){
        case 1:
            showAddNewDoctor();
        break;
        case 2:
            showListDoctor();
        break;
        case 3:
            showEditDoctor();
        break;
        case 4:
            showRemoveDoctor();
        break;
        case 0:
            showHome();
        break;
        default:
            showHome();
        break;

    }
    

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


    showDoctorMenu();
}

void showListDoctor(){
    drawHeader("LISTAGEM DE MEDICOS");
    listarMedicos();
    system("pause");
    showDoctorMenu();

}

void showEditDoctor(){

    drawHeader("EDITAR MEDICO");
    listarMedicos();

    int medicoEdicao = 0;

    printf("\n QUAL CRM DO MEDICO VOCE DESEJA EDITAR? (0 - VOLTAR) >: ");
    scanf("%d", &medicoEdicao);

    if (medicoEdicao != 0) {

        Medico medico;
        medico.crm = medicoEdicao;
        medico.clinica = 0;

        printf("NOME DO MEDICO >: ");
        fflush(stdin);
        gets(medico.nome);

        printf("CPF DO MEDICO >: ");
        fflush(stdin);
        gets(medico.cpf);

        printf("E-MAIL DO MEDICO >: ");
        fflush(stdin);
        gets(medico.email);

        printf("CLINICA ATENDIMENTO >: ");
        scanf("%d", &medico.clinica);

        if (editarMedico(medico) == 0) {
            printf("\n\n ERRO AO EDITAR MEDICO \n\n");
            exit(1);
        } else {
            printf("\n \n DADOS DO MEDICO ALTERADOS \n\n");
            system("pause");
        }
    } 


    showDoctorMenu();
}

void showRemoveDoctor(){
    drawHeader("EDITAR MEDICO");
    listarMedicos();

    int medicoRemover = 0;

    printf("\n QUAL CRM DO MEDICO VOCE DESEJA REMOVER? (0 - VOLTAR) >: ");
    scanf("%d", &medicoRemover);

    if (medicoRemover != 0) {

        if (excluirMedico(medicoRemover) == 0) {
            printf("\n\n ERRO AO REMOVER MEDICO \n\n");
            exit(1);
        } else {
            printf("\n \n O MEDICO FOI REMOVIDO \n\n");
            system("pause");
        }
    } 


    showDoctorMenu();
}

/* ==== USUARIOS ==== */

void showUserMenu(){
    drawHeader("MENU DE USUARIOS");

    int opcao = 0;

    printf("O QUE DESEJA FAZER ?\n\n");
    printf("1 - CADASTRAR USUARIO \n");
    printf("2 - LISTAR USUARIO \n");
    printf("3 - EDITAR USUARIO \n");
    printf("4 - REMOVER USUARIO \n");
    printf("0 - VOLTAR \n");
    printf("ESCOLHA >: ");
    scanf("%d", &opcao);


    switch(opcao){
        case 1:
            showAddNewUser();
        break;
        case 2:
            showListUsers();
        break;
        case 3:
            
        break;
        case 4:
            
        break;
        case 0:
            
        break;
        default:
            showHome();
        break;

    }
}

void showAddNewUser()
{
    system("cls");
    drawHeader("CADASTRO DE FUNCIONARIO");

    Usuario usuario;
    usuario.id = 0;
    usuario.clinicaAtendimento = 0;

    printf("Digite o novo usuario >: ");
    fflush(stdin);
    gets(usuario.username);

    printf("Digite qual a senha >: ");
    fflush(stdin);
    gets(usuario.password);

    printf("Qual a clinica pertencente? >: ");
    scanf("%d", &usuario.clinicaAtendimento);

    if (gravarUsuario(usuario) == 0) {
        printf("\n\nHOUVE UM ERRO AO TENTAR GRAVAR O USUARIO !! \n\n");
        exit(1);
    }else {
        printf("\nDADOS DO USUARIO SALVOS COM SUCESSO !! \n \n");
        system("pause");
    }
    
    showUserMenu();
}

void showListUsers(){

    drawHeader("LISTAGEM USUARIOS");
    //listarUsuarios();

}

void showMedicalunit()
{
    drawHeader("MENU DE RELATORIO");
    int opcao = 0;


    printf("1 - VALOR DE FATURAMENTO DIARIO \n");
    printf("2 - VALOR DE FATURAMENTO MENSAL \n");
    printf("3 - VALOR DE FATURAMENTO TOTAL \n");
    printf("4 - PACIENTES POR UNIDADE \n");
    printf("5 - UNIDADE DA CLINICA QUE MAIS ATENDE \n");
    printf("0 - VOLTAR \n");
    printf("ESCOLHA >: ");
    scanf("%d", &opcao);


    switch(opcao){
        case 1:
            valordeFaturamentoD();
        break;
        case 2:
            valordeFaturamentoM();
        break;
        case 3:
            valordeFaturamentoT();
        break;
        case 4:
            pacienteporUnidade();
        break;
        case 5:
            unidademaiorAtendimento();
        break;
        default:
            showHome();
        break;
    }
    
}

void valordeFaturamentoD(){
    
    drawHeader("FATURAMENTO DO DIA");
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "rt");
    Agenda agenda;
    agenda.valorConsulta=0.0;
    float valorConsulta = agenda.valorConsulta;
    char dataAtendimento[12];

    printf("DIGITE A DATA QUE DESEJA VISUALIZAR O FATURAMENTO:");
    scanf("%s", dataAtendimento);
    
    
    while (!feof(arquivo)){
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica);
        if(strcmp(dataAtendimento, agenda.dataAtendimento)==0){
            valorConsulta += agenda.valorConsulta;

        }
        
        
    }

    fclose(arquivo);
    printf("O VALOR DO FATURAMENTO DO DIA %s FOI DE R$: %.2f\n", dataAtendimento,valorConsulta);

    system("pause");
    showHome();
    
}

void valordeFaturamentoM(){

    drawHeader("FATURAMENTO MENSAL");
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "rt");
    Agenda agenda;
    char dataAtendimento[12];
    char mesBusca[12];
    int quantidadeAtendimentos = 0;
    agenda.valorConsulta=0.0;
    float valorConsulta = agenda.valorConsulta;

    printf("MES E ANO QUE DESEJA FERIFICAR O FATURAMENTO:");
    scanf("%s", dataAtendimento);
    
    while (!feof(arquivo)){
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica);
        for(int i = 0, j = 0; i<12; i++){
            if (i >= 3){
                mesBusca[j] = agenda.dataAtendimento[i];
                j++;
            }

        }   
        if (strcmp(mesBusca, dataAtendimento) == 0){
            quantidadeAtendimentos++;
            valorConsulta += agenda.valorConsulta;
        }
    
        
    }

    printf("QUANTIDADE DE FATURAMENTO DO MES: %d \n", quantidadeAtendimentos);
    printf("VALOR DE CONSULTAS DO MES: %.2f \n", valorConsulta);

    system("pause");
    showHome();
    


}
void valordeFaturamentoT(){

    drawHeader("FATURAMENTO TOTAL");
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "rt");
    Agenda agenda;
    agenda.valorConsulta=0.0;
    float valorConsulta = agenda.valorConsulta;
    

    
    while (!feof(arquivo)){
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.dataAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica);
        valorConsulta += agenda.valorConsulta;
    }

    fclose(arquivo);
    printf("O FATURAMENTO TOTAL FOI DE: %.2f\n", valorConsulta);

    system("pause");
    showHome();
    

}
void pacienteporUnidade(){

    drawHeader("UNIDADE COM MAIOR ATENDIMENTO");
    FILE *arquivo;
    arquivo = fopen("dados/pacientes.txt", "rt");
    Paciente paciente;
    int pacientePorUnidade[10] = {};
    int unidadeComMaiorPaciente = 0;


    
    while (!feof(arquivo)){
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%d; ", &paciente.id, paciente.nome, paciente.cpf, paciente.email, paciente.telefone, &paciente.unidadeMedica);
        pacientePorUnidade[paciente.unidadeMedica]++;
    }

    fclose(arquivo);
    for(int i=0; i<10; i++){
        if(pacientePorUnidade[i]>0){
            printf("A UNIDADE %d TEM %d PACIENTES\n", i, pacientePorUnidade[i]);
        }
      
    }
    

    system("pause");
    showHome();


}
void unidademaiorAtendimento(){

    drawHeader("UNIDADE COM MAIOR ATENDIMENTO");
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "rt");
    Agenda agenda;
    int unidadeMedica[10] = {};
    int unidadeMaiorAtendimento = 0;


    
    while (!feof(arquivo)){
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica);
        unidadeMedica[agenda.unidadeMedica]++;
    }

    fclose(arquivo);
    for(int i=0; i<10; i++){
        if(unidadeMedica[i] >= unidadeMaiorAtendimento){
            unidadeMaiorAtendimento = i;

        }
    }
    printf("A UNIDADE DE MAIOR ATENDIMENTO FOI A UNIDADE: %d\n", unidadeMaiorAtendimento);

    system("pause");
    showHome();


}




void showFeedback()
{
    char sugestao[500];
    int i = 0, opcao = 0;
    int feedback;
    char line[255];

    drawHeader("RECLAMACOES E ELOGIOS");

    printf("Digite sua sugestao: \n");
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
