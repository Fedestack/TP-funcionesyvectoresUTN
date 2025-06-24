#include <iostream>

#include "menu.h"

using namespace std;

int main()
{
    menuPrincipal();
    return 0;
}


void reporte()
{
    int opcion;


    do
    {
        cout << "\n===== REPORTES =====\n" << endl;
        cout << "1. Reporte de recaudacion por producto" << endl;
        cout << "2. Reporte de porcentaje de ventas por forma de pago" << endl;
        cout << "3. Reporte de ventas por marca y forma de pago" << endl;
        cout << "4. Reporte de productos sin ventas" << endl;
        cout << "5. Top 10 clientes + sorteo de cupones" << endl;
        cout << "0. Volver al menu principal\n" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch(opcion)
        {

        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            cout << "Regresando al menu principal\n";
            system("pause");
            system("cls");
            return;
            break;

        }

    }
    while (opcion != 0);


}
