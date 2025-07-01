#include <iostream>
#include "funciones.h"


bool esConsecutivo(int numero)
{
    int num1 = numero/100;
    int num2 = (numero/10) % 10;
    int num3 = numero % 10;

    if((num2 == num1 + 1 && num3 == num2 + 1) || (num2 == num1 - 1 && num3 == num2 - 1))
    {
        return true;
    }
    return false;
}


void limpiarPantalla()
{
    system("pause");
    system("cls");
}

