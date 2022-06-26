#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include "Producto.h"

using namespace std;

class Venta {
private:
    vector<Producto> productos;
    string cliente;
public:
    Venta()
    {

    }
    ~Venta() {

    }
    Venta(vector<Producto> productos, string cliente)
    {
        this->productos = productos;
        this->cliente = cliente;
    }
    // metodos

    void imprimirBoleta()
    {
        cout << "Detalle de compra: "<< endl;
        int sum = 0;
        for (Producto producto : productos)
        {
            cout << "Item: " << producto.getnombre() << " Cantidad: " << producto.getcantidad() << " Total: " << producto.getcantidad()*producto.getprecio() <<  endl;
            sum += producto.getcantidad()*producto.getprecio();
        }
        cout << "Importe total: " << sum << endl;
    }

};