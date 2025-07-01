#include <iostream>
#include <iomanip>
#include "structs.h"
#include "funciones.h"

using namespace std;

void reporteRecaudacionPorProducto(Producto productos[], int cantidadProductos, Venta venta[], int cantidadVentas)
{


    InfoProducto resumen[20];


    for (int i = 0; i < cantidadProductos; i++)
    {
        resumen[i].codigo = productos[i].codigoProducto;
        resumen[i].nombre = productos[i].nombre;
        resumen[i].totalRecaudado = 0;
        resumen[i].cantidadVendida = 0;
        resumen[i].stockRestante = productos[i].stock;
    }


    for (int i = 0; i < cantidadVentas; i++)
    {
        int codigo = venta[i].codigoProducto;
        for (int j = 0; j < cantidadProductos; j++)
        {
            if (resumen[j].codigo == codigo)
            {
                resumen[j].cantidadVendida += venta[i].cantidadVendida;
                resumen[j].totalRecaudado += venta[i].cantidadVendida * productos[j].precioVenta;
                break;
            }
        }
    }

    // BURBUJEO
    for (int i = 0; i < cantidadProductos - 1; i++)
    {
        for (int j = 0; j < cantidadProductos - i - 1; j++)
        {
            if (resumen[j].cantidadVendida < resumen[j + 1].cantidadVendida)
            {
                InfoProducto temp = resumen[j];
                resumen[j] = resumen[j + 1];
                resumen[j + 1] = temp;
            }
        }
    }


//    cout << "\n=== REPORTE: RECAUDACION POR PRODUCTO ===\n\n";
//    cout << "COD\tNOMBRE\t\t\tRECAUDADO\tVENDIDO\tSTOCK\n";
//    cout << "----------------------------------------------------------------------\n";


    cout << left;
    cout << setw(10) << "COD"
         << setw(30) << "NOMBRE"
         << setw(15) << "RECAUDADO"
         << setw(10) << "VENDIDO"
         << setw(10) << "STOCK" << endl;
    cout << string(75, '-') << endl;

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (resumen[i].cantidadVendida > 0)
        {
//            cout << resumen[i].codigo << "\t"
//                 << resumen[i].nombre << "\t\t$"
//                 << resumen[i].totalRecaudado << "\t"
//                 << resumen[i].cantidadVendida << "\t\t"
//                 << resumen[i].stockRestante << endl;
            stringstream oss;
            oss << "$" << fixed << setprecision(2) << resumen[i].totalRecaudado;

            cout << setw(10) << resumen[i].codigo
                 << setw(30) << resumen[i].nombre
                 << setw(15) << oss.str()
                 << setw(10) << resumen[i].cantidadVendida
                 << setw(10) << resumen[i].stockRestante << endl;
        }
    }

    cout << endl;
    limpiarPantalla();
}


