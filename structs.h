#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <string>
using namespace std;

struct Marca
{
    int codigo;
    string nombre;
};

struct Producto
{
    int codigoProducto;
    string nombre;
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoMarca;
};

struct FormaPago
{
    string codigo;
    string nombre;
    int porcentaje;
};

struct Venta
{
    int numeroDeCompra;
    int codigoProducto;
    string formaDePago;
    int cantidadVendida;
    int codigoDeCliente;
    int diaDeLaVenta;
};

struct InfoProducto
{
    int codigo;
    string nombre;
    float totalRecaudado;
    int cantidadVendida;
    int stockRestante;
};

struct ClienteCompra
{
    int codigoCliente;
    int cantidadCompras;
};


#endif // STRUCTS_H_INCLUDED
