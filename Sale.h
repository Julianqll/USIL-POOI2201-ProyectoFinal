#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include "Product.h"
#include "Customer.h"

using namespace std;

class Sale {
private:
    vector<Product> products;
    Customer customer;
public:
    Sale()
    {

    }
    ~Sale() {

    }
    Sale(vector<Product> products, Customer customer)
    {
        this->products = products;
        this->customer = customer;
    }
    // metodos

    void printTicket()
    {
        cout << "Detalle de compra: "<< endl;
        cout << "Cliente: " << customer.getNames() << " (" << customer.getNickName() << ") - " << customer.getDNI() << endl;
        int sum = 0;
        for (Product product : products)
        {
            cout << "Item: " << product.getName() << " Cantidad: " << product.getQuantity() << " Total: " << product.getQuantity()*product.getPrice() <<  endl;
            sum += product.getQuantity()*product.getPrice();
        }
        cout << "Importe total: " << sum << endl;
    }

};