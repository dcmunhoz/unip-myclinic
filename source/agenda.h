#ifndef AGENDA_H
#define AGENDA_H

#include <stdlib.h>
#include <stdio.h>

struct agenda{
    int id;
    float valorConsulta;
    int unidadeMedica;
    char nomePaciente[25];
    char nomeMedico[25];
    char dataAtendimento[12];
    char horaAtendimento[6];

};

typedef struct agenda Agenda;

/*
    Guarda os dados de uma agenda no arquivo.
*/
int gravarAgenda(Agenda agenda){

    int ultimoId = ultimaAgenda();

    FILE *fSchedule = fopen("dados/agendas.txt", "a+");

    if (fSchedule == NULL) {
        return 0;
    }

    ultimoId++;

    fprintf(fSchedule, "%d;%s;%s;%s;%s;%.2f;%d; \n", ultimoId, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, agenda.valorConsulta, agenda.unidadeMedica);
    fclose(fSchedule);

    return 1;

}

/*
    Busca no arquivo de agendas qual o ultimo ID adicionado.
*/
int ultimaAgenda(){
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "r");
    
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO !!!!");
        exit(1);
    }

    Agenda agenda;
    agenda.id = 0;
    agenda.unidadeMedica = 0;
    agenda.valorConsulta = 0.0;
    float valorConsulta = agenda.valorConsulta;


    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.dataAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica);
    }


    fclose(arquivo);
    return agenda.id;
}

/*
    Exibe toda a agenda para o usuário.
*/
void listarAgenda(){
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "r");

    // int ch, c;

    Agenda agenda;
    agenda.id = 0;
    agenda.unidadeMedica = 0;
    agenda.valorConsulta = 0.0;
    char dataAtendimento[12];


    if (arquivo == NULL) {
        system("cls");
        printf("ERRO AO ABRIR ARQUIVO");
        exit(1);
    }

    printf("DIGITE A DATA QUE DESEJA VISUALIZAR:");
    scanf("%s", dataAtendimento);
    drawHeader("LISTA DE AGENDAMENTOS");
    printf(" ID |       NOME PACIENTE       |       NOME MEDICO         |     DATA     |    HORA    |    Valor    |    UNIDADE  \n");
    printf("------------------------------------------------------------------------------------\n");
    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica) != EOF ) {
        
        if(strcmp(dataAtendimento, agenda.dataAtendimento)==0){

            printf("%3d | %25s | %25s | %12s | %10s | %11.2f | %12d \n", agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, agenda.valorConsulta, agenda.unidadeMedica);
        
        }
    }



    fclose(arquivo);

}

/*
    Permite o usuário fazer a edição de uma agenda existente.
*/
int editarAgenda(Agenda agendaEditar){

    FILE *agendaL, *agendaE;

    Agenda agendaAtual;

    agendaL = fopen("dados/agendas.txt", "r");
    agendaE = fopen("dados/tmp/agendas.txt", "w+");

    if (agendaL == NULL || agendaE == NULL) {
        return 0;
    }

    while (fscanf(agendaL, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agendaAtual.id, agendaAtual.nomePaciente, agendaAtual.nomeMedico, agendaAtual.dataAtendimento, agendaAtual.horaAtendimento, &agendaAtual.valorConsulta, &agendaAtual.unidadeMedica) != EOF) {

        if (agendaAtual.id == agendaEditar.id) {
            fprintf(agendaE, "%d;%s;%s;%s;%s;%f;%d \n", agendaEditar.id, agendaEditar.nomePaciente, agendaEditar.nomeMedico, agendaEditar.dataAtendimento, agendaEditar.horaAtendimento, agendaEditar.valorConsulta, agendaEditar.unidadeMedica);
        } else {
            fprintf(agendaE, "%d;%s;%s;%s;%s;%f;%d \n", agendaAtual.id, agendaAtual.nomePaciente, agendaAtual.nomeMedico, agendaAtual.dataAtendimento, agendaAtual.horaAtendimento, agendaAtual.valorConsulta, agendaAtual.unidadeMedica);
        }

    }

    fclose(agendaL);
    fclose(agendaE);

    remove("dados/agendas.txt");
    rename("dados/tmp/agendas.txt", "dados/agendas.txt");

    return 1;

}

/*
    Permite o usuário fazer o cancelamento de uma agenda existente.
*/
int cancelarAgenda(int idAgendaCancela){

    FILE *agendaL;
    FILE *agendaC;

    Agenda agenda;
    agenda.id = 0;

    agendaL = fopen("dados/agendas.txt", "r");
    agendaC = fopen("dados/tmp/agendas.txt", "w+");

    if (agendaL == NULL || agendaC == NULL) {
        return 0;
    }

    while(fscanf(agendaL, "%d;%[^;];%[^;];%[^;];%[^;];%f;%d; ", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, &agenda.valorConsulta, &agenda.unidadeMedica) != EOF){

        if (idAgendaCancela != agenda.id) {

            fprintf(agendaC, "%d;%s;%s;%s;%s;%f;%d \n", agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento, agenda.valorConsulta, agenda.unidadeMedica);

        } 

    }

    fclose(agendaL);
    fclose(agendaC);

    remove("dados/agendas.txt");
    rename("dados/tmp/agendas.txt", "dados/agendas.txt");

    return 1;

}

#endif