#include <iostream>
#include "menu.h"
#include "structs.h"
#include "carga.h"
#include "funciones.h"

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
    Venta venta[100];
    int cantidadVentas = 0;

    int opcion;

    do
    {
        cout << "\n===== MENU PRINCIPAL =====\n" << endl;
        cout << "1. Cargar marcas" << endl;
        cout << "2. Cargar productos" << endl;
        cout << "3. Cargar formas de pago" << endl;
        cout << "4. Cargar ventas" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "0. Salir\n" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cargarMarcas(marcas, cantidadMarcas, marcasCargadas);
            break;
        case 2:
            cargarProductos(productos, cantidadProductos, productosCargados, marcas, cantidadMarcas);
            break;
        case 3:
            cargarFormasPago(formasPago, formasCargadas, cantidadFormas, marcas, cantidadMarcas);
            break;
        case 4:
            cargarVentas(productos, cantidadProductos, formasPago, cantidadFormas,
                         marcasCargadas, productosCargados, formasCargadas, cantidadVentas, venta);
            break;
        case 5:
            reporte(productos, marcas, formasPago, cantidadProductos, cantidadVentas, venta, cantidadFormas, cantidadMarcas);
            break;
        case 0:
            cout << "\n Gracias Vuelva prontos.\n";
            break;
        default:
            cout << "\n Opcion no valida.\n";
               limpiarPantalla();
        }

    }
    while (opcion != 0);
}


void reporte(Producto productos[], Marca marcas[], FormaPago formasPago[], int cantidadProductos, int cantidadVentas, Venta venta[],
             int cantidadFormas, int cantidadMarcas)
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
            reporteRecaudacionPorProducto(productos, cantidadProductos, venta, cantidadVentas);
            break;
        case 2:
            reportePorcentajeDeVentaPorFormaDePago(formasPago, cantidadFormas, venta, cantidadVentas);
            break;
        case 3:
            reporteVentasPorMarcaYPago(marcas, cantidadMarcas, venta, cantidadVentas, formasPago, cantidadFormas, productos, cantidadProductos);
            break;
        case 4:
            reporteProductosSinVentas(productos, cantidadProductos,
                                venta, cantidadVentas);
            break;
        case 5:
            reporteTopClientesConSorteo(venta, cantidadVentas);
            break;
        case 0:
            cout << "Regresando al menu principal\n";
            limpiarPantalla();
            return;
            break;
        default:
            cout << "Opcion no valida\n";
            limpiarPantalla();
        }

    }
    while (opcion != 0);


}
