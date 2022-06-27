#pragma once
#include <stdio.h>  
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
  string customerID, customerName, customerPassword, customerDNI;
  int customerAge;
  Cliente customer;
  vector<Cliente> customers;
  string sellerID, sellerName, sellerPassword, sellerDNI;
  int sellerAge;
  Vendedor seller;
  vector<Vendedor> sellers;
  string productID, productName, productCategory, productBrand, productSize;
  int productQuantity;
  float productPrice;
  Producto product;
  vector<Producto> products;
  vector<Producto> sale;
public:
    Sesion()
    {

    }
    ~Sesion() {

    }
void customerSignUp() {
  ofstream customerLoginFile("customerlogin.csv", ios::app),
  customersFile("customers.csv",ios::app),
  customersBinaryFile("customers.dat",ios::out|ios::binary);
  if (customerLoginFile.fail() || customersFile.fail() || customersBinaryFile.fail()) {
    cout << "Archivo no existente" << endl;
    exit(1);
  }
  cout << "Digite su nombre de usuario: ";
  cin.ignore();
  getline(cin, customerName);
  cout << "Digite su contraseña: ";
  getline(cin, customerPassword);

  cout << "Digite su edad: ";
  cin >> customerAge;
  cout << "Digite su DNI: ";
  cin >> customerDNI;
  
  // aca se guarda el usuario y la contraseña
  
  customerLoginFile << encrypt(customerName) << " "
        << encrypt(customerPassword) << endl;
  customerLoginFile.close();
  customerID = randomCodeGeneration();
  customer = Cliente(customerName, customerPassword, customerDNI,
                customerID, customerAge);
  customersFile << customerID << ";" << customerName << ";"
              << customerAge << ";" << customerDNI << endl;
  
  customersBinaryFile.write(customerID.c_str(),customerID.size());     
  customersBinaryFile.write(customerName.c_str(),customerName.size());
  customersBinaryFile.write(customerDNI.c_str(),customerDNI.size());
  customersBinaryFile.write(reinterpret_cast<const char *>(&customerAge),sizeof(customerAge));
  
  customersFile.close();
  customersBinaryFile.close();
  
}
void sellerSignUp()
{
  ofstream sellerLoginFile("sellerlogin.csv", ios::app),
  sellersFile("sellers.csv",ios::app),
  sellersBinaryFile("sellers.dat",ios::out|ios::binary);
  if (sellerLoginFile.fail() || sellersFile.fail() || sellersBinaryFile.fail()) {
    cout << "Archivo no existente" << endl;
    exit(1);
  }
  cout << "Digite su nombre de usuario: ";
  cin.ignore();
  getline(cin, sellerName);  
  cout << "Digite su contraseña: ";
  getline(cin, sellerPassword);  
  cout << "Digite su edad: ";
  cin >> sellerAge;
  cout << "Digite su DNI: ";
  cin >> sellerDNI;

  sellerLoginFile << encrypt(sellerName) << " " << encrypt(sellerPassword) << endl;

  sellerLoginFile.close();
  
  sellerID = randomCodeGeneration();
  seller = Vendedor(sellerName, sellerPassword, sellerDNI,
                  sellerID, sellerAge);
  sellersFile << sellerID << ";" << sellerName << ";"
                << sellerAge << ";" << sellerDNI << endl;

  sellersBinaryFile.write(sellerID.c_str(),sellerID.size());
  sellersBinaryFile.write(sellerName.c_str(),sellerName.size());
  sellersBinaryFile.write(customerDNI.c_str(),customerDNI.size());
  sellersBinaryFile.write(reinterpret_cast<const char *>(&sellerAge),sizeof(sellerAge));
  
  sellersFile.close();
  sellersBinaryFile.close();
  
}
bool customerSignIn() {
  
  ifstream customerLoginFile;
  string customerNameData, customerPasswordData;
  string customerName, customerPassword;
  bool authenticated = false;
  customerLoginFile.open("customerlogin.csv", ios::in);
  cout << "Nombre de usuario: ";
  cin>>customerName;
  cout << "Contraseña: ";
  cin.ignore();
  getline(cin, customerPassword);
  cout<<customerName << endl;
  cout<<customerPassword << endl;

  // Dentro de este if se lee el archivo para validar los datos ingresados
  while (customerLoginFile >> customerNameData >> customerPasswordData) {
    customerNameData = decrypt(customerNameData);
    customerPasswordData = decrypt(customerPasswordData);
    
    if (customerNameData == customerName && customerPasswordData == customerPassword) {
      authenticated = true;
      break;
    }
  }
  customerLoginFile.close();
  return authenticated;
}

bool sellerSignIn() {
  ifstream sellerLoginFile;
  string sellerNameData, sellerPasswordData;
  string sellerName, sellerPassword;
  bool authenticated = false;
  sellerLoginFile.open("sellerlogin.csv", ios::in);

  cout << "Nombre de usuario: ";
  cin>>sellerName;
  cout << "Contraseña: ";
  cin.ignore();
  getline(cin, sellerPassword);
  while (sellerLoginFile >> sellerNameData >> sellerPasswordData) 
  {
    sellerNameData=decrypt(sellerNameData);
    sellerPasswordData=decrypt(sellerPasswordData);
    if (sellerNameData == sellerName && sellerPasswordData == sellerPassword) {
      authenticated = true;
      sellerLoginFile.close();
      break;
    }
  }
  sellerLoginFile.close();
  return authenticated;
}

string randomCodeGeneration() {
  string sample =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  srand(getpid());
  string code;
  char tempCode[20 + 1] = ""; //  +1 por el caracter nulo
  for (int x = 0; x < 20; x++) {
    int randomIndex = 0 + rand() / (RAND_MAX / ((int)sample.size()) + 1);
    tempCode[x] = sample[randomIndex];
  }
  code = tempCode;
  return code;
}

string encrypt(string chain) {
  for (int i = 0; (i < chain.length() && chain[i] != '\0'); i++) {
    chain[i] = chain[i] + i; // hashea con ascii
  }
  return chain;
}

string decrypt(string chain) {
  for (int i = 0; (i < chain.length() && chain[i] != '\0'); i++) {
    chain[i] = chain[i] - i; // libera hasheo
  }
  return chain;
}

void productRegistration()
{
  ofstream productsFile("products.csv",ios::app);
  cin.ignore();
  cout<<"\t Nombre del producto: "<<endl;
  getline(cin,productName);
  cout<<"\t Categoria: "<<endl;
  getline(cin,productCategory);
  cout<<"\t Marca: "<<endl;
  getline(cin,productBrand);
  cout<<"\tTamaño del producto: "<<endl;
  getline(cin,productSize);
  cout<<"\tCantidad del producto: "<<endl;
  cin>>productQuantity;
  cout<<"\tPrecio del producto: "<<endl;
  cin>>productPrice;
  productID=randomCodeGeneration();
  productsFile<<productID<<","<<productName<<","<<productCategory<<","<<productSize<<","<<productQuantity<<","<<productPrice<<endl; product=Producto(productID,productName,productCategory,productBrand,productQuantity,productPrice);
  productsFile.close();
}

void quickSort(vector<Producto>&products, int start, int end)
{
  if (start < end)
  {
    int pivot = splitVector(products, start, end);
    quickSort(products, start, pivot - 1);
    quickSort(products, pivot + 1, end);
    
  }
}
void printElements(vector<Producto>products)
{
  for (Producto product : products)
    {
      cout << product.getnombre() << endl;
    }
}

void swap(Producto &a,Producto &b){
    Producto aux = a;
    a = b;
    b = aux;
}


int splitVector(vector<Producto>&products, int start, int end)
{
  string pivot = products[start].getnombre();
  int i = start + 1;
  for (int j = i; j <= end; j++)
  {
    if (products[j].getnombre() < pivot)
    {
      swap(products[i], products[j]);
      i++;
    }
  }
  swap(products[start], products[i-1]);
  return i - 1;
}
void productSearching()
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    string productName;
    int productQuantity, answer;
    fstream file("products.csv", ios::in);
    cin.ignore();
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
        cout<<"No se pudo abrir el archivo\n";
  do
    {
    //cin.ignore();
    cout<<"\tBusque el nombre del producto: ";
    cin>>productName;
    cin.ignore();
    //getline(cin,productName);
  for(int i=0;i<content[0].size();i++)
  {
    if(productName == content[i][1] && stoi(content[i][4]) > 0)
    {
        cout<<"\tStock del producto: " << content[i][4]<<endl;
        cout<<"\tCuantas unidades del producto desea adquirir: ";
        cin >> productQuantity;
        while (productQuantity > stoi(content[i][4]))
        {
            cout<<"\tCantidad digitada errónea. Cuantas unidades del producto desea adquirir: ";
            cin >> productQuantity;
        }
        int newProductQuantity = (stoi(content[i][4]) - productQuantity);
        cout<<"\tProcesando venta..."<<endl;
        product=Producto(content[i][0],content[i][1],content[i][2],content[i][3], productQuantity, stof(content[i][5]));
        sale.push_back(product);
        quickSort(sale, 0, sale.size() - 1);
        printElements(sale);
        products.push_back(product);
        content[i][4] = to_string(newProductQuantity);
        updateFile(content);
        break;
    }
}
      cout << "¿Desea continuar comprando?" <<endl;
      cout << "1. Sí, deseo continuar" <<endl;
      cout<<"2.Eliminar elemento "<<endl;
      cout << "3. No" <<endl;
      cout<<"Opcion: ";
      cin >> answer;
      if(answer==2)
      {
        string delete_product;
        cout<<"Digite el producto que desea eliminar: "<<endl;
        cin>>delete_product;
        binarySearch(sale,delete_product);
      }
    }while(answer <3&&answer>0);
    Venta venta = Venta(sale, "Julian");
    cout << "\033[2J\033[0;0H";
    cout <<"Venta realizada"<<endl;
    venta.imprimirBoleta();
}

void updateFile(vector<vector<string>> content)
{
    fstream file;
    file.open("newproducts.csv", ios::out);
    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            file << content[i][j] << ",";
        }
        file<<"\n";
    }
    remove("products.csv");
    rename("newproducts.csv","products.csv" );
}
void binarySearch(vector<Producto>&products, string To_Find)
{
    int lo = 0, hi = products.size() - 1;
    int mid=lo-(hi-lo)/2;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) 
    {
        int mid = (hi + lo) / 2;
        if (products[mid].getnombre() < To_Find) 
        {
            lo = mid + 1;
        }
        else 
        {
            hi = mid;
        }
    }
    if (products[lo].getnombre() == To_Find) 
    {
      products.erase(products.begin()+lo);
    }
    else if (products[hi].getnombre() == To_Find) 
    {
      products.erase(products.begin()+hi);
    }
    else 
    {
        cout << "No se encontro" << endl;
    }
}
};





