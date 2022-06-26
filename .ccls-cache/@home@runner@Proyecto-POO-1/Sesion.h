#pragma once

#include "Cliente.h"
#include "Producto.h"
#include "Vendedor.h"
#include "Venta.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
#include "Venta.h"
using namespace std;

class Sesion {
private:
  string codigo_cliente, nombre_usuario_cliente, password_cliente, dni_cliente;
  int edad_cliente;
  Cliente cli;
  vector<Cliente> clientes;
  string codigo_vendedor, nombre_usuario_vendedor, password_vendedor, dni_vendedor;
  int edad_vendedor;
  Vendedor vend;
  vector<Vendedor> vendedores;
  string codigo_producto,nombre_producto,categoria_producto, marca_producto, size_producto;
  int cantidad_producto;
  float precio_producto;
  Producto producto;
  vector<Producto> productos;
  vector<Producto> ventas;
public:
    Sesion()
    {

    }
    ~Sesion() {

    }
void registrar_cliente() {
  ofstream login("loginCliente.csv", ios::app),clientearch("Cliente.csv",ios::app),clientearchb("Clientes.dat",ios::out|ios::binary);
  if (login.fail() || clientearch.fail()||clientearchb.fail()) {
    cout << "Archivo no existente" << endl;
    exit(1);
  }

  cout << "Digite su nombre de usuario: ";
  cin >> nombre_usuario_cliente;
  cout << "Digite su contraseña: ";
  cin.ignore();

  getline(cin, password_cliente);

  cout << "Digite su edad: ";
  cin >> edad_cliente;
  cout << "Digite su DNI: ";
  cin >> dni_cliente;
  // aca se guarda el usuario y la contraseña
  login << encryptar(nombre_usuario_cliente) << " "
        << encryptar(password_cliente) << endl;
  login.close();
  codigo_cliente = generar_codigo_aleatorio();
  cli = Cliente(nombre_usuario_cliente, password_cliente, dni_cliente,
                codigo_cliente, edad_cliente);

  clientearch << codigo_cliente << ";" << nombre_usuario_cliente << ";"
              << edad_cliente << ";" << dni_cliente << endl;
  
  clientearchb.write(codigo_cliente.c_str(),codigo_cliente.size());     
  clientearchb.write(nombre_usuario_cliente.c_str(),nombre_usuario_cliente.size());
  clientearchb.write(dni_cliente.c_str(),dni_cliente.size());
  clientearchb.write(reinterpret_cast<const char *>(&edad_cliente),sizeof(edad_cliente));
  
  clientearch.close();
  clientearchb.close();
  clientes.push_back(cli);
}
void registrar_vendedor()
{
   ofstream login, vendedorarchi,vendedorarchib;
  string user_password;
  login.open("loginVendedor.csv", ios::out);
  vendedorarchi.open("Vendedor.csv", ios::out);
  vendedorarchib.open("Vendendor.dat",ios::out|ios::binary);
  if (login.fail() || vendedorarchi.fail()||vendedorarchib.fail()) {
    cout << "Archivo no existente" << endl;
    exit(1);
  }
  cout << "Digite su nombre de usuario: ";
  cin >> nombre_usuario_vendedor;
  cout << "Digite su contraseña: ";
  cin >> password_vendedor;
  cout << "Digite su edad: ";
  cin >> edad_vendedor;
  cout << "Digite su DNI: ";
  cin >> dni_vendedor;

  login << encryptar(nombre_usuario_vendedor) << " " << encryptar(password_vendedor) << endl;

  login.close();
  
  codigo_vendedor = generar_codigo_aleatorio();
  vend = Vendedor(nombre_usuario_vendedor, password_vendedor, dni_vendedor,
                  codigo_vendedor, edad_vendedor);
  vendedorarchi << codigo_vendedor << ";" << nombre_usuario_vendedor << ";"
                << edad_vendedor << ";" << dni_vendedor << endl;

  vendedorarchib.write(codigo_vendedor.c_str(),codigo_vendedor.size());
  vendedorarchib.write(nombre_usuario_vendedor.c_str(),nombre_usuario_vendedor.size());
  vendedorarchib.write(dni_cliente.c_str(),dni_cliente.size());
  vendedorarchib.write(reinterpret_cast<const char *>(&edad_vendedor),sizeof(edad_vendedor));
  
  vendedorarchi.close();
  vendedorarchib.close();
  vendedores.push_back(vend);
}
bool iniciar_sesion_cliente() {
  ifstream login;
  string user, pass;
  string usuario, password;
  bool band = false;

  login.open("loginCliente.csv", ios::in);

  cout << "Nombre de usuario: ";
  cin.ignore();
  getline(cin, usuario);
  cout << "Contraseña: ";
  // cin.ignore();
  getline(cin, password);
  
  // Dentro de este if se lee el archivo para validar los datos ingresados
  while (login >> user >> pass) {
    user = desencryptar(user);
    pass = desencryptar(pass);
    if (user == usuario && pass == password) {
      band = true;
      login.close();
      break;
    }
  }
  login.close();
  return band;
}
bool iniciar_sesion_vendedor() {
  ifstream login;
  string user, pass;
  string usuario, password;
  bool band = false;
  login.open("loginVendedor.csv", ios::in);

  cout << "Nombre de usuario: ";
  cin.ignore();
  getline(cin, usuario);
  cout << "Contraseña: ";
  getline(cin, password);
  while (login >> user >> pass) 
  {
    user=desencryptar(user);
    pass=desencryptar(pass);
    if (user == usuario && pass == password) {
      band = true;
      login.close();
      break;
    }
  }
  login.close();
  return band;
}
string generar_codigo_aleatorio() {
  string muestra =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  srand(getpid());
  string codigo;
  char codigo_temp[20 + 1] = ""; //  +1 por el caracter nulo
  for (int x = 0; x < 20; x++) {
    int indice_aleatorio = 0 + rand() / (RAND_MAX / ((int)muestra.size()) + 1);
    codigo_temp[x] = muestra[indice_aleatorio];
  }
  codigo = codigo_temp;
  return codigo;
}
string encryptar(string cadenita) {
  for (int i = 0; (i < cadenita.length() && cadenita[i] != '\0'); i++) {
    cadenita[i] = cadenita[i] + i; // hashea con ascii
  }
  return cadenita;
}
string desencryptar(string cadenita) {
  for (int i = 0; (i < cadenita.length() && cadenita[i] != '\0'); i++) {
    cadenita[i] = cadenita[i] - i; // libera hasheo
  }
  return cadenita;
}
void registrar_producto()
{
  ofstream productosarch("Productos.csv",ios::app);
  cin.ignore();
  cout<<"\t Nombre del producto: "<<endl;
  getline(cin,nombre_producto);
  cout<<"\t Categoria: "<<endl;
  getline(cin,categoria_producto);
  cout<<"\t Marca: "<<endl;
  getline(cin,marca_producto);
  cout<<"\tTamaño del producto: "<<endl;
  getline(cin,size_producto);
  cout<<"\tCantidad del producto: "<<endl;
  cin>>cantidad_producto;
  cout<<"\tPrecio del producto: "<<endl;
  cin>>precio_producto;
  codigo_producto=generar_codigo_aleatorio();
  productosarch<<codigo_producto<<","<<nombre_producto<<","<<categoria_producto<<","<<size_producto<<","<<cantidad_producto<<","<<precio_producto<<endl;  producto=Producto(codigo_producto,nombre_producto,categoria_producto,marca_producto,cantidad_producto,precio_producto);
  productosarch.close();
  productos.push_back(producto);
}


void buscar_producto()
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    string nombre;
    int cantidad;
    fstream file("Productos.csv", ios::in);
    cin.ignore();
    cout<<"\tBusque el nombre del producto: ";
    getline(cin,nombre);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";

    for(int i=0;i<content[0].size();i++)
    {
        if(nombre == content[i][1] && stoi(content[i][4]) > 0)
        {
            cout<<"\tStock del producto: " << content[i][4]<<endl;
            cout<<"\tCuantas unidades del producto desea adquirir: ";
            cin >> cantidad;
            while (cantidad > stoi(content[i][4]))
            {
                cout<<"\tCantidad digitada errónea. Cuantas unidades del producto desea adquirir: ";
                cin >> cantidad;
            }
            cout<<"\tProcesando venta..."<<endl;
            producto=Producto(content[i][0],content[i][1],content[i][2],content[i][3], stoi(content[i][4]), stof(content[i][5]));
            ventas.push_back(producto);
            Venta venta = Venta(ventas, "Julian");
            content[i][4] = to_string((stoi(content[i][4]) - cantidad));
            actualizar_cantidad(content);
            cout <<"Venta realizada"<<endl;
            venta.imprimirBoleta();
            break;
        }
    }
}

void actualizar_cantidad(vector<vector<string>> content)
{
    fstream file;
    file.open("Productosnew.csv", ios::out);
    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            file << content[i][j] << ",";
        }
        file<<"\n";
    }
    remove("Productos.csv");
    rename("Productosnew.csv","Productos.csv" );
}
};