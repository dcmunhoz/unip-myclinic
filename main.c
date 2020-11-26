#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca para usar a funçao strcmp
#include <windows.h>
#include <conio.h>

#include "source/screens.h"
#include "source/setup.h"

/*
    Função de execução principal do programa.
*/
void main() {
    setup();
    system("cls");
    showPrincipal();
    system("pause");
    
    return;
}
