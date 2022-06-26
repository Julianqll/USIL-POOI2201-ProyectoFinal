#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Vendedor{
  protected:
  string nombre_usuario,password,dni,codigo;
  int edad;
  public:
  Vendedor(){
  }
  ~Vendedor(){
  }
  Vendedor(string nombre_usuario,string password,string dni,string  codigo,int edad)
  {
    this->nombre_usuario=nombre_usuario;
    this->password=password;
    this->codigo=codigo;
    this->edad=edad;
    this->dni=dni;
  }
//metodos
//set
void setNombre_usuario(string nombre_usuario){
  this->nombre_usuario=nombre_usuario;
}
void setpassword(string password){
  this->password=password;
}
void setCodigo(int  codigo){
  this->codigo=codigo;
}
void setedad(int edad){
  this->edad=edad;
}
void setdni(string dni){
  this->dni=dni;
}   

//get
string getNombre_usuario(){
  return nombre_usuario;
}
string getpassword(){
  return password;
}
string getCodigo(){
  return codigo;
}
int getedad(){
  return edad;
}
string getdni(){
  return dni;
}
};


