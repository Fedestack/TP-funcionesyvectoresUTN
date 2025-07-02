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

    cout << "\n--- REPORTE DE RECAUDACION POR PRODUCTO ---\n\n";

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


    int conteoPorForma[5] = {0};


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


    for (int i = 0; i < cantidadFormas; i++)
    {
        float porcentaje = (float)conteoPorForma[i] / cantidadVentas * 100.0;
        cout << setw(25) << formasPago[i].nombre
             << fixed << setprecision(2) << porcentaje << "%" << endl;
    }

    limpiarPantalla();
}

void reporteVentasPorMarcaYPago(Marca marcas[], int cantidadMarcas, Venta ventas[], int cantidadVentas, FormaPago formasPago[],
                                int cantidadFormas, Producto productos[], int cantidadProductos)
{

    if (cantidadVentas == 0)
    {
        cout << "No hay ventas registradas para generar el reporte.\n";
        limpiarPantalla();
        return;
    }

    cout << "\n--- VENTAS POR MARCA Y FORMA DE PAGO ---\n\n";

    for (int i = 0; i < cantidadMarcas; i++)
    {
        cout << "Marca: " << marcas[i].nombre << endl;


        int ventasPorForma[5] = {0};

        for (int j = 0; j < cantidadVentas; j++)
        {
            int codigoProductoVenta = ventas[j].codigoProducto;
            string formaPagoVenta = ventas[j].formaDePago;


            for (int k = 0; k < cantidadProductos; k++)
            {
                if (productos[k].codigoProducto == codigoProductoVenta &&
                        productos[k].codigoMarca == marcas[i].codigo)
                {

                    for (int l = 0; l < cantidadFormas; l++)
                    {
                        if (formasPago[l].codigo == formaPagoVenta)
                        {
                            ventasPorForma[l] += ventas[j].cantidadVendida;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        for (int m = 0; m < cantidadFormas; m++)
        {
            cout << "  " << formasPago[m].codigo << " (" << formasPago[m].nombre << "): "
                 << ventasPorForma[m] << " unidades vendidas" << endl;
        }

        cout << "-----------------------------------------\n";
    }

    limpiarPantalla();
}



void reporteProductosSinVentas(Producto productos[], int cantidadProductos,
                               Venta ventas[], int cantidadVentas)
{

    if (cantidadVentas == 0)
    {
        cout << "No hay ventas registradas. Todos los productos están sin ventas.\n";

        for (int i = 0; i < cantidadProductos; i++)
        {
            cout << "Código: " << productos[i].codigoProducto
                 << " - Nombre: " << productos[i].nombre << endl;
        }
        limpiarPantalla();
        return;
    }

    cout << "\n--- PRODUCTOS SIN VENTAS ---\n\n";

    bool haySinVentas = false;

    for (int i = 0; i < cantidadProductos; i++)
    {
        bool vendido = false;

        for (int j = 0; j < cantidadVentas; j++)
        {
            if (productos[i].codigoProducto == ventas[j].codigoProducto)
            {
                vendido = true;
                break; // ya encontramos una venta de este producto
            }
        }

        if (!vendido)
        {
            haySinVentas = true;
            cout << "Código: " << productos[i].codigoProducto
                 << " - Nombre: " << productos[i].nombre << endl;
        }
    }

    if (!haySinVentas)
    {
        cout << "¡Todos los productos registraron al menos una venta!\n";
    }

    limpiarPantalla();
}

void reporteTopClientesConSorteo(Venta venta[], int cantidadVentas)
{
    if (cantidadVentas == 0)
    {
        cout << "No hay ventas registradas. No se puede hacer el sorteo.\n";
        limpiarPantalla();
        return;
    }

    // Paso 1: contar compras por cliente
    int comprasPorCliente[50] = {0}; // índice 0 = cliente 1, índice 49 = cliente 50

    for (int i = 0; i < cantidadVentas; i++)
    {
        int cod = venta[i].codigoDeCliente;
        if (cod >= 1 && cod <= 50)

        {
            comprasPorCliente[cod - 1]++;
        }
    }

    // Paso 2: crear vectores paralelos solo con clientes que compraron
    int codigosClientes[50];     // códigos de los clientes
    int cantidadCompras[50];     // cantidad de compras de cada cliente
    int cantidadClientesConCompras = 0;

    for (int i = 0; i < 50; i++)
    {
        if (comprasPorCliente[i] > 0)
        {
            codigosClientes[cantidadClientesConCompras] = i + 1;      // código del cliente
            cantidadCompras[cantidadClientesConCompras] = comprasPorCliente[i]; // sus compras
            cantidadClientesConCompras++;
        }
    }

    if (cantidadClientesConCompras == 0)
    {
        cout << "Ningún cliente realizó compras.\n";
        limpiarPantalla();
        return;
    }




    // Paso 2: armar vector de estructuras para ordenarlos
//    ClienteCompra clientes[50];
//    int cantidadClientesConCompras = 0;
//
//    for (int i = 0; i < 50; i++)
//    {
//        if (comprasPorCliente[i] > 0)
//        {
//            clientes[cantidadClientesConCompras].codigoCliente = i + 1;
//            clientes[cantidadClientesConCompras].cantidadCompras = comprasPorCliente[i];
//            cantidadClientesConCompras++;
//        }
//    }

//    if (cantidadClientesConCompras == 0)
//    {
//        cout << "Ningún cliente realizó compras.\n";
//        limpiarPantalla();
//        return;
//    }

    // Paso 3: ordenar por cantidad de compras (burbujeo descendente)
//    for (int i = 0; i < cantidadClientesConCompras - 1; i++)
//    {
//        for (int j = 0; j < cantidadClientesConCompras - i - 1; j++)
//        {
//            if (clientes[j].cantidadCompras < clientes[j + 1].cantidadCompras)
//            {
//                // Usar una variable auxiliar para intercambiar
//                ClienteCompra aux = clientes[j];
//                clientes[j] = clientes[j + 1];
//                clientes[j + 1] = aux;
//            }
//        }
//    }

    // Paso 3: ordenar por cantidad de compras (burbujeo descendente)
    // Hay que mantener sincronizados ambos vectores
    for (int i = 0; i < cantidadClientesConCompras - 1; i++)
    {
        for (int j = 0; j < cantidadClientesConCompras - i - 1; j++)
        {
            if (cantidadCompras[j] < cantidadCompras[j + 1])
            {
                // Intercambiar cantidades
                int tempCompras = cantidadCompras[j];
                cantidadCompras[j] = cantidadCompras[j + 1];
                cantidadCompras[j + 1] = tempCompras;

                // Intercambiar códigos (para mantener la relación)
                int tempCodigo = codigosClientes[j];
                codigosClientes[j] = codigosClientes[j + 1];
                codigosClientes[j + 1] = tempCodigo;
            }
        }
    }

    // Paso 4: mostrar top 10
    int top;
    if (cantidadClientesConCompras < 10)
    {
        top = cantidadClientesConCompras;
    }
    else
    {
        top = 10;
    }

    cout << "\n--- TOP " << top << " CLIENTES CON MÁS COMPRAS ---\n";
    for (int i = 0; i < top; i++)
    {
        cout << "Cliente #" << codigosClientes[i]
             << " - Compras: " << cantidadCompras[i] << endl;
    }

    // Paso 5: sorteo de 3 ganadores al azar del top 10
    srand(time(0));
    int ganadores[3];
    int usados[10] = {0};
    int cantidadGanadores = 0;

    while (cantidadGanadores < 3 && cantidadGanadores < top)
    {
        int elegido = rand() % top;
        if (!usados[elegido])
        {
            usados[elegido] = 1;
            ganadores[cantidadGanadores] = elegido;
            cantidadGanadores++;
        }
    }

    // Paso 6: mostrar ganadores
      cout << "\n--- GANADORES DE CUPONES ---\n";
    for (int i = 0; i < cantidadGanadores; i++)
    {
        int indice = ganadores[i];
        cout << "Cliente #" << codigosClientes[indice]
             << " - Compras: " << cantidadCompras[indice] << endl;
    }

    limpiarPantalla();
}











