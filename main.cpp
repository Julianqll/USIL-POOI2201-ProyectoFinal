// Hashear contraseñas y nicks de usuarios
// metodos de ordenamiento quicksort

#include <iostream>
#include "Sesion.h"
using namespace std;
int main() 
{
  Sesion sesion = Sesion();
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
          
          if (!sesion.iniciar_sesion_cliente()) 
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
              cout<<"1.Buscar producto"<<endl;
              cin>>opcion;
              switch(opcion)
              {
                  case 1:
                      sesion.buscar_producto();
                      break;
                  case 2:

                      break;
                  default:
                      break;
              }
              break;
          }
        } while (intentos > 0);
        break;
      case 2:
        do {
          
          if (!sesion.iniciar_sesion_vendedor()) 
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
                  sesion.registrar_producto();
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
      switch (opcion) 
      {
      case 1:
        cout << "\033[2J\033[0;0H";
        sesion.registrar_cliente();
        //esto limpia la consola
        
        break;
      case 2:
        cout << "\033[2J\033[0;0H";
        sesion.registrar_vendedor();
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

