// Hashear contraseñas y nicks de usuarios
// metodos de ordenamiento quicksort
#include "Cliente.h"
#include "Producto.h"
#include "Vendedor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
// variables globales
//  variables del cliente (se cambiaran mas adelante)
string codigo_cliente, nombre_usuario_cliente, password_cliente, dni_cliente;
int edad_cliente;
Cliente cli;
vector<Cliente> clientes;
//  variables del vendedor (se cambiaran mas adelante)
string codigo_vendedor, nombre_usuario_vendedor, password_vendedor,
    dni_vendedor;
int edad_vendedor;
Vendedor vend;
vector<Vendedor> vendedores;

string  codigo_producto,nombre_producto,categoria_producto, marca_producto, size_producto;
  int cantidad_producto;
float precio_producto;
Producto producto;
vector<Producto> productos;
// funciones de registro
void registrar_cliente();

void registrar_vendedor();
// implementar al programa con los objetos
// funciones de logeo para la generacion de una venta
bool iniciar_sesion_cliente();
// Tres intentos para el inicio de sesion
bool iniciar_sesion_vendedor();
string generar_codigo_aleatorio();
string encryptar(string);
string desencryptar(string);
void registrar_producto();
void generar_compra();
int main() 
{
  int opcion;
  int intentos = 3;
    // Agregar Unicode
    cout << "\tSistema de ventas:" << endl;
    cout << "\t1. Inicar sesion: " << endl;
    cout << "\t2. Resgitrarse: " << endl;
    cout << "\t3. Salir" << endl;
    cout << "Digite la opcion: ";
    cin >> opcion;
    switch (opcion) 
    {
    case 1:
      cout << "\033[2J\033[0;0H";
      cout<<"Inicie sesion como:"<<endl;
      cout << "\t1.Cliente: " << endl;
      cout << "\t2.Vendedor: " << endl;
      cout << "\t3. Salir" << endl;
      cout << "Digite la opcion: ";
      cin >> opcion;
      switch (opcion) {
      case 1:        
        do {
          
          if (!iniciar_sesion_cliente()) 
          {
            cout << "\033[2J\033[0;0H";
            cout << "Por favor vuelva a intertarlo de nuevo " << endl;
            intentos--;
            cout<<"Le quedan "<<intentos<<" intentos "<<endl;
            
          } 
          else 
          {
            cout << "\033[2J\033[0;0H";
            cout << "\tBienvenido" << endl;
            
            break;
          }
        } while (intentos > 0);
        break;
      case 2:
        do {
          
          if (!iniciar_sesion_vendedor()) 
          {
            cout << "\033[2J\033[0;0H";
            cout << "Por favor vuelva a intertarlo de nuevo " << endl;
            intentos--;
            
            cout<<"Le quedan "<<intentos<<" intentos "<<endl;
            
          } 
          else 
          {
            cout << "\033[2J\033[0;0H";
            cout <<"\tBienvenido " << endl;
            cout<<"1.Que desea realizar "<<endl;
            cout<<"2.Realizar compra "<<endl;
            cin>>opcion;
            switch(opcion)
              {
                case 1:
                  registrar_producto();
                break;
                case 2:
                  
                break;
                default:
                break;
              }
            break;
          }
        }while (intentos > 0);
        break;
      default:
        break;
      }
    break;
    case 2:
      cout << "\033[2J\033[0;0H";
      cout<<"Escoga su tipo de usuario: "<<endl;
      cout << "\t1.Cliente: " << endl;
      cout << "\t2.Vendedor: " << endl;
      cout << "\t3. Salir" << endl;
      cout << "Digite la opcion: ";
      cin >> opcion;
      switch (opcion) {
      case 1:
        cout << "\033[2J\033[0;0H";
        registrar_cliente();
        //esto limpia la consola
        
        break;
      case 2:
        cout << "\033[2J\033[0;0H";
        registrar_vendedor();
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
  return 0;
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
void registrar_vendedor() {
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

// funciones de loggeo
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
  productosarch<<";"<<nombre_producto<<";"<<categoria_producto<<";"<<size_producto<<";"<<cantidad_producto<<";"<<precio_producto<<endl;
  codigo_producto=generar_codigo_aleatorio();
  producto=Producto(codigo_producto,nombre_producto,categoria_producto,marca_producto,cantidad_producto,precio_producto);
  productosarch.close();
  productos.push_back(producto);
}