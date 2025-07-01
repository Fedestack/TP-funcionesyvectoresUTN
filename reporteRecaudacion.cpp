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

void reportePorcentajeDeVentaPorFormaDePago(FormaPago formasPago[], int cantidadFormas, Venta venta[], int cantidadVentas)
{
    if (cantidadVentas == 0)
    {
        cout << "No hay ventas registradas para generar el reporte.\n";
        limpiarPantalla();
        return;
    }

    // Contadores para cada forma de pago
    int conteoPorForma[5] = {0}; // Asumimos máximo 5 formas de pago

    // Contamos cuántas ventas tiene cada forma de pago
    for (int i = 0; i < cantidadVentas; i++)
    {
        for (int j = 0; j < cantidadFormas; j++)
        {
            if (venta[i].formaDePago == formasPago[j].codigo)
            {
                conteoPorForma[j]++;
                break;
            }
        }
    }

    cout << "\n--- PORCENTAJE DE VENTAS POR FORMA DE PAGO ---\n\n";
    cout << left;
    cout << setw(25) << "Forma de Pago"
         << setw(15) << "Porcentaje" << endl;
    cout << string(40, '-') << endl;

    // Calculamos y mostramos el porcentaje de cada forma de pago
    for (int i = 0; i < cantidadFormas; i++)
    {
        float porcentaje = (float)conteoPorForma[i] / cantidadVentas * 100.0;
        cout << setw(25) << formasPago[i].nombre
             << fixed << setprecision(2) << porcentaje << "%" << endl;
    }

    limpiarPantalla();
}




