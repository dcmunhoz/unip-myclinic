#ifndef AGENDA_H
#define AGENDA_H

#include <stdlib.h>
#include <stdio.h>

struct agenda{
    int id;
    char nomePaciente[50];
    char nomeMedico[50];
    char dataAtendimento[10];
    char horaAtendimento[5];
};

typedef struct agenda Agenda;

int gravarAgenda(Agenda agenda){

    int ultimoId = ultimaAgenda();

   FILE * fSchedule = fopen("dados/agendas.txt", "a+");

    if (fSchedule == NULL) {
        return 0;
    }

    ultimoId++;

    fprintf(fSchedule, "%d;%s;%s;%s;%s\n", ultimoId, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento);
    fclose(fSchedule);

    return 1;

}

int ultimaAgenda(){
    FILE *arquivo;
    arquivo = fopen("dados/agendas.txt", "r");
    
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO !!!!");
        exit(1);
    }

    Agenda agenda;
    agenda.id = 0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d;%s;%s;%s;%s\n", &agenda.id, agenda.nomePaciente, agenda.nomeMedico, agenda.dataAtendimento, agenda.horaAtendimento);
    }
    fclose(arquivo);
    return agenda.id;
}

#endif      