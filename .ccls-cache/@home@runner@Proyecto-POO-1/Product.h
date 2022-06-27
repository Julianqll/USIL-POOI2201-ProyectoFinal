#pragma once

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Product {
protected:
  string ID, name, category, brand, size;
  int quantity;
  float price;

public:
  Product() {}
  ~Product() {}
  Product(string ID, string name, string category,string brand,int quantity, float price) 
  {
  
   this->name=name;this->quantity=quantity;this->ID=ID;
   this->price=price;this->category=category;this->brand=brand;
  }
  // Metodos
  
  // set
  void setID(string valor){
    ID=valor;   
  }
  void setName(string valor){
    name=valor; 
  }
  void setQuantity(int valor){
    quantity=valor;
  }
  void setPrice(float valor){
    price=valor;
  }
  void setCategory(string valor){
    category=valor;
  }
  void setBrand(string valor){
    brand=valor;
  }

  // get
  string  getID(){
    return ID;
  }
  string getName(){
    return name;
  }
  int getQuantity(){
    return quantity;
  }
  float getPrice(){
    return price;
  }
  string getCategory(){
    return category;
  }
  string getBrand(){
    return brand;
  }
};
