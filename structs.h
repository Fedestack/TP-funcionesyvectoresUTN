#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <string>
using namespace std;

struct Marca {
    int codigo;
    string nombre;
};

struct Producto {
    int codigoProducto;
    string nombre;
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoMarca;
};

struct FormaPago {
    string codigo;      // EF, MP, TR, TC, CT
    string nombre;
    int porcentaje;      // Positivo (interés), negativo (descuento)
};

struct Venta {
    int numeroDeCompra;
    int codigoProducto;   //mismo codigo que el de producto
    string formaDePago;
    int cantidadVendida;
    int codigoDeCliente;
    int diaDeLaVenta;
};



#endif // STRUCTS_H_INCLUDED
