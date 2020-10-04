#include<stdio.h>
#include<stdlib.h>
#include<string.h> //Biblioteca para usar a funçao strcmp
#include<windows.h>
#include<conio.h>
#include "screens.h"
#include "setup.h"

void main() {
    setup();
//    system("cls");

    do{
        system("cls");
        showWellcome();
        showMenu();

        printf("ESCOLHA: ");
        scanf("%d", &menuChoise);

    } while (menuChoise != 1 && menuChoise != 0);

    if (menuChoise == 1) {
        system("cls");
        showLogin();
        

    } else if (menuChoise == 0) {
        return;
    }

    printf("\n\nFIM");
    system("pause");
    
    return;
}



