#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include "Product.h"

using namespace std;

class Sale {
private:
    vector<Product> products;
    string cliente;
public:
    Sale()
    {

    }
    ~Sale() {

    }
    Sale(vector<Product> products, string cliente)
    {
        this->products = products;
        this->cliente = cliente;
    }
    // metodos

    void imprimirBoleta()
    {
        cout << "Detalle de compra: "<< endl;
        int sum = 0;
        for (Product product : products)
        {
            cout << "Item: " << product.getnombre() << " Cantidad: " << product.getcantidad() << " Total: " << product.getcantidad()*product.getprecio() <<  endl;
            sum += product.getcantidad()*product.getprecio();
        }
        cout << "Importe total: " << sum << endl;
    }

};