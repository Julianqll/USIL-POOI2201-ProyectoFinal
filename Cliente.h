#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Cliente { 
protected:
  string nombre_usuario, password, codigo,dni;
  int edad;
public:
  Cliente() 
  {
    
  }
  ~Cliente() {
    
  }
  Cliente(string nombre_usuario, string password,string dni, string codigo, int edad) 
  {
    this->nombre_usuario = nombre_usuario;
    this->password = password;
    this->dni=dni;
    this->codigo=codigo;
    this->edad = edad; 
  }
  // metodos
  // set
  void setNombre_usuario(string nombre_usuario){
    this->nombre_usuario=nombre_usuario;
  } 
   void setpassword(string password){
     this->password=password;
   }
void setDni(string dni){
  this->dni=dni;
  }
  void setcodigo(string codigo){
    this->codigo=codigo;
  }
  void setedad(int edad){
   this->edad=edad;  
  }   
// get
  string getNombre_usuario(){
    return nombre_usuario;
  }   
string getpassword(){
  return password;
}
 string getDni(){
   return dni;
 } 
string getcodigo(){
  return codigo;
}
int getedad(){
  return edad;
} 
};







