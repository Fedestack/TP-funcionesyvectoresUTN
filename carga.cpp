#include <iostream>
#include <cstring>
#include "structs.h"
#include "carga.h"
#include "funciones.h"


using namespace std;


void limpiarPantalla();


void cargarMarcas(Marca marcas[], int &cantidadMarcas, bool &cargado)
{

    if (cargado)
    {
        cout << "Ya se cargaron las marcas.\n";
        limpiarPantalla();
        return;
    }



    cout << "\n--- CARGA DE MARCAS ---\n";

    for (int i = 0; i < 10; i++)
    {
        int codigo;
        string nombre;

        cout << endl;
        cout << "Marca #" << (i + 1) << endl;

        cout << "Ingresa codigo de marca (de 1 a 10): ";
        cin >> codigo;
        cin.ignore();

        if (codigo < 1 || codigo > 10)
        {
            cout << "Codigo invalido. Debe estar entre 1 y 10.\n";
            cantidadMarcas = 0;
            cargado = false;
            limpiarPantalla();
            return;
        }

        cout << "Nombre de la marca: ";
        //cin.ignore();
        getline(cin, nombre);

        if (nombre.empty())
        {
            cout << "Nombre no puede estar vac�o.\n";
            cantidadMarcas = 0;
            cargado = false;
            limpiarPantalla();
            return;

        }

        marcas[i].codigo = codigo;
        marcas[i].nombre = nombre;
        cantidadMarcas++;
    }

    cargado = true;
    cout << "\nLote de marcas cargado correctamente.\n";
    limpiarPantalla();
}



void cargarProductos(Producto productos[], int &cantidadProductos, bool &productosCargados, Marca marcas[], int cantidadMarcas)
{
    if (!cantidadMarcas)
    {
        cout << "No se han cargado marcas. Debe cargar el lote de marcas antes.\n";
        limpiarPantalla();
        return;
    }

    if (productosCargados)
    {
        cout << "Ya se cargaron los productos.\n";
        limpiarPantalla();
        return;
    }

    cout << "\n--- CARGA DE PRODUCTOS ---\n";

    for (int i = 0; i < 20; i++)
    {
        Producto p;

        cout << "\nProducto #" << i + 1 << endl;

        cout << "Codigo de producto (3 digitos): ";
        cin >> p.codigoProducto;
        if (p.codigoProducto < 100 || p.codigoProducto > 999 || esConsecutivo(p.codigoProducto))
        {
            cout << "Codigo invalido. Debe tener 3 digitos y no ser consecutivos (ej.123).\n";
            cantidadProductos = 0;
            productosCargados = false;
            limpiarPantalla();
            return;
        }

        cout << "Nombre del producto: ";
        cin.ignore();
        getline(cin, p.nombre);
        if (p.nombre.empty())
        {
            cout << "El nombre no puede estar vac�o.\n";
            cantidadProductos = 0;
            productosCargados = false;
            limpiarPantalla();
            return;
        }

        cout << "Precio de venta: ";
        cin >> p.precioVenta;
        if (p.precioVenta <= 0)
        {
            cout << "El precio debe ser mayor a 0.\n";
            cantidadProductos = 0;
            productosCargados = false;
            limpiarPantalla();
            return;
        }

        cout << "Precio de compra: ";
        cin >> p.precioCompra;
        if (p.precioCompra <= 0)
        {
            cout << "El precio debe ser mayor a 0.\n";
            cantidadProductos = 0;
            productosCargados = false;
            limpiarPantalla();
            return;
        }

        cout << "Stock disponible: ";
        cin >> p.stock;
        if (p.stock <= 0)
        {
            cout << "El stock debe ser mayor a 0.\n";
            cantidadProductos = 0;
            productosCargados = false;
            limpiarPantalla();
            return;
        }

        cout << "Codigo de marca: ";
        cin >> p.codigoMarca;

        bool marcaExiste = false;
        for (int j = 0; j < cantidadMarcas; j++)
        {
            if (p.codigoMarca == marcas[j].codigo)
            {
                marcaExiste = true;
                break;
            }
        }

        if (!marcaExiste)
        {
            cout << "Codigo de marca no encontrado. No se puede continuar.\n";
            cantidadProductos = 0;
            limpiarPantalla();
            return;
        }

        productos[i] = p;
        cantidadProductos++;
    }

    productosCargados = true;
    cout << "\nProductos cargados correctamente.\n";
    limpiarPantalla();
}

void cargarFormasPago(FormaPago formasPago[], bool &formasCargadas, int &cantidadFormas, Marca marcas[], int cantidadMarcas)
{

//    if (!cantidadMarcas)
//    {
//        cout << "No se han cargado marcas. Debe cargar el lote de marcas antes.\n";
//        limpiarPantalla();
//        return;
//    }
//
//
//
//    if (formasCargadas)
//    {
//        cout << "Ya se cargaron las formas de pago.\n";
//        limpiarPantalla();
//        return;
//    }

    const string codigosValidos[] = {"EF", "MP", "TR", "TC", "CT"};
    bool codigoUsado[5] = {false};

    cout << "\n--- CARGA DE FORMAS DE PAGO ---\n";

    while (cantidadFormas < 5)
    {
        FormaPago f;
        string codigoIngresado;

        cout << "\nForma de pago #" <<(cantidadFormas + 1) << endl;
        cout << "Codigo (EF, MP, TR, TC, CT): ";
        cin >> codigoIngresado;

        bool valido = false;
        for (int j = 0; j < 5; j++)
        {
            if ((codigoIngresado == codigosValidos[j]) && codigoUsado[j] == false)
            {
                f.codigo = codigoIngresado;
                codigoUsado[j] = true;
                valido = true;
                break;
            }
        }

        if (!valido)
        {
            cout << "Codigo invalido o repetido. Solo se permite uno de: EF, MP, TR, TC, CT.\n";
            cantidadFormas = 0;
            formasCargadas = false;
            limpiarPantalla();
            return;
        }

        cout << "Nombre de la forma de pago: ";
        cin.ignore();
        getline(cin, f.nombre);

        if (f.nombre.empty())
        {
            cout << "El nombre no puede estar vac�o.\n";
            cantidadFormas = 0;
            formasCargadas = false;
            limpiarPantalla();
            return;
        }

        cout << "Porcentaje de descuento/interes (negativo = descuento, positivo = interes): ";
        cin >> f.porcentaje;


        if (f.porcentaje == 0 || f.porcentaje < -100 || f.porcentaje > 100)
        {
            cout << "Porcentaje invalido. Debe estar entre -100 y 100 y no puede ser 0.\n";
            cantidadFormas = 0;
            formasCargadas = false;
            limpiarPantalla();
            return;
        }

        formasPago[cantidadFormas] = f;
        cantidadFormas++;

//        if (cantidadFormas < 5)
//        {
//            char opcion;
//            cout << "�Deseas cargar otra forma de pago? (S/N): ";
//            cin >> opcion;
//
//            if (toupper(opcion) != 'S')
//            {
//                break;
//            }
//        }
    }

    formasCargadas = true;
    cout << "\n Formas de pago cargadas correctamente.\n";
    limpiarPantalla();
}


void cargarVentas(Producto productos[], int cantidadProductos, FormaPago formas[], int cantidadFormas,
                  bool &marcasCargadas, bool &productosCargados, bool &formasCargadas, int &cantidadVentas, Venta venta[])
{


    if (!marcasCargadas || !productosCargados || !formasCargadas)
    {
        cout << "Error: Debe cargar todos los lotes (marcas, productos y formas de pago) antes de cargar ventas.\n";
        limpiarPantalla();
        return;
    }

    cout << "\n--- CARGA DE VENTAS ---\n";
    cout << "Ingrese los datos de las ventas (ingrese 0 para finalizar):\n";

    int numeroCompra;

    do
    {
        cout << "\n--- Venta #" << (cantidadVentas + 1) << " ---\n";
        cout << "Numero de compra (0 para finalizar): ";
        cin >> numeroCompra;

        if (numeroCompra == 0)
        {
            break;
        }

        if (numeroCompra < 0)
        {
            cout << "Error: Numero de compra invalido. Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }


        venta[cantidadVentas].numeroDeCompra = numeroCompra;


        cout << "Codigo de producto: ";
        cin >> venta[cantidadVentas].codigoProducto;

        bool productoExiste = false;
        int indiceProducto = -1;
        for (int i = 0; i < cantidadProductos; i++)
        {
            if (productos[i].codigoProducto == venta[cantidadVentas].codigoProducto)
            {
                productoExiste = true;
                indiceProducto = i;
                break;
            }
        }

        if (!productoExiste)
        {
            cout << "Error: Codigo de producto no encontrado en el lote de productos. Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }

        cout << "Forma de pago: ";
        cin >> venta[cantidadVentas].formaDePago;


        bool formaPagoExiste = false;
        for (int i = 0; i < cantidadFormas; i++)
        {
            if (formas[i].codigo == venta[cantidadVentas].formaDePago)
            {
                formaPagoExiste = true;
                break;
            }
        }

        if (!formaPagoExiste)
        {
            cout << "Error: Forma de pago no encontrada en el lote de formas de pago. Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }

        cout << "Cantidad vendida: ";
        cin >> venta[cantidadVentas].cantidadVendida;
        if (venta[cantidadVentas].cantidadVendida <= 0)
        {
            cout << "Error: Cantidad vendida invalida. Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }

        if (productos[indiceProducto].stock < venta[cantidadVentas].cantidadVendida)
        {
            cout << "Error: Stock insuficiente. Stock disponible: " << productos[indiceProducto].stock
                 << ", cantidad solicitada: " << venta[cantidadVentas].cantidadVendida << ". Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }



        cout << "Codigo de cliente (1-50): ";
        cin >> venta[cantidadVentas].codigoDeCliente;
        if (venta[cantidadVentas].codigoDeCliente < 1 || venta[cantidadVentas].codigoDeCliente > 50)
        {
            cout << "Error: Codigo de cliente invalido. Debe estar entre 1 y 50. Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }

        cout << "Dia de la venta (1-30): ";
        cin >> venta[cantidadVentas].diaDeLaVenta;
        if (venta[cantidadVentas].diaDeLaVenta < 1 || venta[cantidadVentas].diaDeLaVenta > 30)
        {
            cout << "Error: Dia invalido. Debe estar entre 1 y 30. Carga interrumpida.\n";
            limpiarPantalla();
            return;
        }



        // ACTUALIZO EL STOCK
        productos[indiceProducto].stock -= venta[cantidadVentas].cantidadVendida;


        float porcentajeFormaPago = 0;
        string nombreFormaPago = "";
        for (int i = 0; i < cantidadFormas; i++)
        {
            if (formas[i].codigo == venta[cantidadVentas].formaDePago)
            {
                porcentajeFormaPago = formas[i].porcentaje;
                nombreFormaPago = formas[i].nombre;
                break;
            }
        }

        float precioBase = productos[indiceProducto].precioVenta * venta[cantidadVentas].cantidadVendida;
        float precioFinal;

        if (porcentajeFormaPago < 0)
        {

            precioFinal = precioBase * (1 + porcentajeFormaPago/100.0);
        }
        else
        {

            precioFinal = precioBase * (1 + porcentajeFormaPago/100.0);
        }


        cout << "\n--- VENTA PROCESADA ---\n";
        cout << "Producto: " << productos[indiceProducto].nombre << endl;
        cout << "Cantidad vendida: " << venta[cantidadVentas].cantidadVendida << endl;
        cout << "Forma de pago: " << venta[cantidadVentas].formaDePago << " (" << nombreFormaPago << ")" << endl;
        cout << "Stock restante: " << productos[indiceProducto].stock << endl;
        cout << "Precio unitario: $" << productos[indiceProducto].precioVenta << endl;
        cout << "Subtotal: $" << precioBase << endl;

        if (porcentajeFormaPago < 0)
        {
            cout << "Descuento " << nombreFormaPago << ": " << (porcentajeFormaPago) << "%" << endl;
            cout << "Descuento aplicado: $" << (precioBase - precioFinal) << endl;
        }
        else if (porcentajeFormaPago > 0)
        {
            cout << "Recargo " << nombreFormaPago << ": " << porcentajeFormaPago << "%" << endl;
            cout << "Recargo aplicado: $" << (precioFinal - precioBase) << endl;
        }
        else
        {
            cout << "Sin descuento ni recargo" << endl;
        }

        cout << "TOTAL DE LA VENTA: $" << precioFinal << endl;



        cout << "Venta registrada correctamente.\n";
        cantidadVentas++;

    }
    while (numeroCompra != 0);

    cout << "\nSe registraron " << cantidadVentas << " ventas correctamente.\n";
    cout << "Lote de ventas cargado exitosamente.\n";
    limpiarPantalla();
}





