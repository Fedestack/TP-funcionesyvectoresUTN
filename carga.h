#ifndef CARGA_H_INCLUDED
#define CARGA_H_INCLUDED
#include "structs.h"

void cargarMarcas(Marca marcas[], int &cantidad, bool &cargado);

void cargarProductos(Producto productos[], int &cantidadProductos, bool &productosCargados, Marca marcas[], int cantidadMarcas);

void cargarFormasPago(FormaPago formas[], bool &cargado, int &cantidad, Marca marcas[], int cantidadMarcas);

void cargarVentas(Producto productos[], int cantidadProductos, FormaPago formasPago[], int cantidadFormas,
                  bool &marcasCargadas, bool &productosCargados, bool &formasCargadas, int &cantidadVentas, Venta venta[]);

void reporte(Producto productos[], Marca marcas[], FormaPago formasPago[], int cantidadProductos, int cantidadVentas, Venta venta[],
             int cantidadFormas, int cantidadMarcas);

void reporteRecaudacionPorProducto(Producto productos[], int cantidadProductos, Venta venta[], int cantidadVentas);

void reportePorcentajeDeVentaPorFormaDePago(FormaPago formasPago[], int cantidadFormas, Venta venta[], int cantidadVentas);

void reporteVentasPorMarcaYPago(Marca marcas[], int cantidadMarcas, Venta venta[], int cantidadVentas, FormaPago formasPago[],
                                int cantidadFormas, Producto productos[], int cantidadProductos);

#endif // CARGA_H_INCLUDED
