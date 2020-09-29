//
// Created by daniel.munhoz on 25/09/2020.
//

#ifndef UNIP_PIM_CLINIC_SCREENS_H
#define UNIP_PIM_CLINIC_SCREENS_H

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
    char password[255];

    showWellcome();
    printf("INFORME SEU USUARIO: ");
    scanf(" %s", username);

    printf("INFORME SUA SENHA: ");
    scanf(" %s", password);

    // Validar usuário e senha

}

#endif //UNIP_PIM_CLINIC_SCREENS_H
