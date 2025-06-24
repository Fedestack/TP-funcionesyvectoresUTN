#include <iostream>
#include "menu.h"
#include "structs.h"
#include "carga.h"

using namespace std;


void menuPrincipal()
{
    // Lote de marcas
    Marca marcas[10];
    int cantidadMarcas = 0;
    bool marcasCargadas = false;

    // Lote de productos
    Producto productos[20];
    int cantidadProductos = 0;
    bool productosCargados = false;

    // LOTE DE FORMAS DE PAGO
    FormaPago formasPago[5];
    int cantidadFormas = 0;
    bool formasCargadas = false;

    //LOTE DE VENTAS
    Venta ventas;
    int cantidadVentas = 0;

    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n" << endl;
        cout << "1. Cargar marcas" << endl;
        cout << "2. Cargar productos" << endl;
        cout << "3. Cargar formas de pago" << endl;
        cout << "4. Cargar ventas" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "0. Salir\n" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cargarMarcas(marcas, cantidadMarcas, marcasCargadas);
            break;
        case 2:
            cargarProductos(productos, cantidadProductos, productosCargados, marcas, cantidadMarcas);
            break;
        case 3:
            cargarFormasPago(formasPago, formasCargadas, cantidadFormas);
            break;
        case 4:
            cargarVentas(productos, cantidadProductos, formasPago, cantidadFormas,
                   marcasCargadas, productosCargados, formasCargadas);
            break;
        case 5:
            reporte();
            break;
        case 0:
            cout << "\n Gracias por usar el sistema.\n";
            break;
        default:
            cout << "\n Opcion no valida.\n";
            system("pause");
            system("cls");
        }

    } while (opcion != 0);
}

