#include <iostream>
#include "structs.h"
#include "menuReportes.h"
#include "funciones.h"

using namespace std;

void menuReportes(Producto productos[], int cantidadProductos, Venta ventas[], int cantidadVentas)
{
    int opcion;

    do
    {
        cout << "\n===== MENU DE REPORTES =====\n" << endl;
        cout << "1. Recaudacion por producto" << endl;
        cout << "2. Porcentaje de ventas por forma de pago" << endl;
        cout << "3. Ventas por marca y forma de pago" << endl;
        cout << "4. Productos sin ventas" << endl;
        cout << "5. Top 10 clientes + sorteo de cupones" << endl;
        cout << "0. Volver al menu principal\n" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            reporteRecaudacionPorProducto(productos, cantidadProductos, ventas, cantidadVentas);
            break;
        case 2:
            cout << "Reporte de porcentaje de ventas por forma de pago (pendiente)\n";
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Reporte de ventas por marca y forma de pago (pendiente)\n";
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Reporte de productos sin ventas (pendiente)\n";
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Top 10 clientes y sorteo de cupones (pendiente)\n";
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "\nVolviendo al menu principal...\n";
            system("pause");
            system("cls");
            return;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
           limpiarPantalla();
        }

    } while (opcion != 0);
}

