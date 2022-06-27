// metodos de ordenamiento quicksort
#include <iostream>
#include "Sesion.h"
using namespace std;
int main() 
{
  Customer customer;
  Seller seller;
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
    cout << "\033[2J\033[0;0H";
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
      cout << "\033[2J\033[0;0H";
      switch (opcion) {
      case 1:        
        do 
        {
          bool signedin = sesion.customerSignIn();
          if (!signedin) 
          {
            
            cout << "Por favor vuelva a intertarlo de nuevo " << endl;
            intentos--;
            cout<<"Le quedan "<<intentos<<" intentos "<<endl;
          } 
          else{
              cout << "\033[2J\033[0;0H";
              customer = sesion.getCustomer();
              cout << "\tBienvenido cliente(a), " << customer.getNames() << endl;
              cout<<"1.Buscar producto"<<endl;
              cout<<"Digite la opcion: ";
              cin>>opcion;
              switch(opcion)
              {
                  case 1:
                      sesion.productSearching();
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
      case 2:
        do {
          
          if (!sesion.sellerSignIn()) 
          {
            cout << "\033[2J\033[0;0H";
            cout << "Por favor vuelva a intertarlo de nuevo " << endl;
            intentos--;
            
            cout<<"Le quedan "<<intentos<<" intentos "<<endl;
            
          } 
          else 
          {
            cout << "\033[2J\033[0;0H";
            seller = sesion.getSeller();
            cout <<"\tBienvenido vendedor(a), "<< seller.getNames() << endl;
            cout<<"1.Registrar producto "<<endl;
            cout<<"Opcion: ";
            cin>>opcion;
            switch(opcion)
              {
                case 1:
                  sesion.productRegistration();
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
        sesion.customerSignUp();
        main();
        //esto limpia la consola
        
        break;
      case 2:
        cout << "\033[2J\033[0;0H";
        sesion.sellerSignUp();
        main();
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

