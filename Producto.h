#pragma once

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
string nombre;
class Producto {
protected:
  string codigo,nombre,categoria, marca, size;
  int cantidad;
  float precio;

public:
  Producto() {}
  ~Producto() {}
  Producto(string codigo, string nombre, string categoria,string marca,int cantidad, float precio) 
  {
  
   this->nombre=nombre;this->cantidad=cantidad;this->codigo=codigo;
    this->precio=precio;this->categoria=categoria;this->marca=marca;
  }
  // metodos
  
  // set
  void setcodigo(string valor){
     codigo=valor;   
  }
   void setnombre(string valor){
      nombre=valor; 
     }
void setcantidad(int valor){
  cantidad=valor;
}
 void setprecio(float valor){
   precio=valor;
 }
 void setcategoria(string valor){
   categoria=valor;
 }
void setmarca(string valor){
  marca=valor;
}
// get
  string  getcodigo(){
    return codigo;
  }
  string getnombre(){
    return nombre;
  }
  int getcantidad(){
return cantidad;
  }
float getprecio(){
  return precio;
}
string getcategoria(){
  return categoria;
}
string getmarca(){
  return marca;
}
};


