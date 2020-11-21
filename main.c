#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca para usar a funçao strcmp
#include <windows.h>
#include <conio.h>
#include "screens.h"
#include "setup.h"

void main() {
    setup();
    system("cls");
    showPrincipal();
    system("pause");
    
    return;
}
