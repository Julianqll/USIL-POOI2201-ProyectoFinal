#pragma once
#include <stdio.h>  
#include "Customer.h"
#include "Product.h"
#include "Seller.h"
#include "Sale.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

class Sesion {
private:
  string customerID, customerNickName, customerName, customerPassword, customerDNI;
  int customerAge;
  Customer customer;
  //vector<Customer> customers;
  string sellerID, sellerNickName, sellerName, sellerPassword, sellerDNI;
  int sellerAge;
  Seller seller;
  //vector<Seller> sellers;
  string productID, productName, productCategory, productBrand, productSize;
  int productQuantity;
  float productPrice;
  Product product;
  vector<Product> products;
  vector<Product> sale;
public:
    Sesion(){}
    ~Sesion(){}


void userCreation(string userType, string ID, string nickName, string password)
{
  if (userType == "Customer")
  {
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file("customers.csv", ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ';'))
                row.push_back(word);
            content.push_back(row);
        }
    }
    for(int i=0;i<content.size();i++)
    {
    if(ID == content[i][0])
    {
        customer = Customer(content[i][0], content[i][1], nickName, password, content[i][3], stoi(content[i][2]));
        break;
    }
}
  }
  else if (userType == "Seller")
  {
      vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file("sellers.csv", ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ';'))
                row.push_back(word);
            content.push_back(row);
        }
    }
    for(int i=0;i<content.size();i++)
    {
    if(ID == content[i][0])
    {
        seller = Seller(content[i][0], content[i][1], nickName, password, content[i][3], stoi(content[i][2]));
        break;
    }
}
  }
}

bool userExistence(string fileName, string userNickName){
  string userNickNameData;
  string userID;
  string userNickNameDataDecrypted;
  ifstream loginFile(fileName, ios::app);
  while (loginFile >> userID >> userNickNameData) {
    userNickNameDataDecrypted = decrypt(userNickNameData);
    
    if (userNickName == userNickNameDataDecrypted) {
      return true;
    }
  }
  return false;
}

void customerSignUp() {
  ofstream customerLoginFile("customerlogin.csv", ios::app),
  customersFile("customers.csv",ios::app),
  customersBinaryFile("customers.dat",ios::out|ios::binary);

  
  if (customerLoginFile.fail() || customersFile.fail() || customersBinaryFile.fail()) {
    cout << "Archivo no existente" << endl;
    exit(1);
  }
  cout << "Digite su nombres y apellidos: ";
  cin.ignore();
  getline(cin, customerName);
    cout << "Digite su nombre de usuario: ";
  getline(cin, customerNickName);
  cout << "Digite su contraseña: ";
  getline(cin, customerPassword);
  cout << "Digite su edad: ";
  cin >> customerAge;
  cout << "Digite su DNI: ";
  cin >> customerDNI;
  customerID = randomCodeGeneration();

  // verificar si no existe un nombre repetido, de lo contrario volver a pedir nombre
  bool userExists = userExistence("customerlogin.csv", customerNickName);
  if (userExists)
  {
    do{
      cout << "Nombre de usuario existente. Digite un nuevo nombre de usuario: ";
      cin.ignore();
      getline(cin, customerNickName);
      userExists = userExistence("customerlogin.csv", customerNickName);
    }
    while(userExists);
  }
  customerLoginFile << customerID << " " <<encrypt(customerNickName) << " "
<< encrypt(customerPassword) << endl;
  customerLoginFile.close();
  
  customersFile << customerID << ";" << customerName << ";"
              << customerAge << ";" << customerDNI << endl;
  
  customersBinaryFile.write(customerID.c_str(),customerID.size());     
  customersBinaryFile.write(customerName.c_str(),customerName.size());
  customersBinaryFile.write(customerDNI.c_str(),customerDNI.size());
  customersBinaryFile.write(reinterpret_cast<const char *>(&customerAge),sizeof(customerAge));
  
  customersFile.close();
  customersBinaryFile.close();
  
}

void sellerSignUp() {
  ofstream sellerLoginFile("sellerlogin.csv", ios::app),
  sellersFile("sellers.csv",ios::app),
  sellersBinaryFile("sellers.dat",ios::out|ios::binary);
  if (sellerLoginFile.fail() || sellersFile.fail() || sellersBinaryFile.fail()) {
    cout << "Archivo no existente" << endl;
    exit(1);
  }
  cout << "Digite su nombres y apellidos: ";
  cin.ignore();
  getline(cin, sellerName);
  cout << "Digite su nombre de usuario: ";
  getline(cin, sellerNickName);
  cout << "Digite su contraseña: ";
  getline(cin, sellerPassword);  
  cout << "Digite su edad: ";
  cin >> sellerAge;
  cout << "Digite su DNI: ";
  cin >> sellerDNI;
  sellerID = randomCodeGeneration();


  //verificar si el usuario existe
    // verificar si no existe un nombre repetido, de lo contrario volver a pedir nombre
  bool userExists = userExistence("sellerlogin.csv", sellerNickName);
  if (userExists)
  {
    do{
      cout << "Nombre de usuario existente. Digite un nuevo nombre de usuario: ";
      cin.ignore();
      getline(cin, sellerNickName);
      userExists = userExistence("sellerlogin.csv", sellerNickName);
    }
    while(userExists);
  }

  sellerLoginFile << sellerID << " " <<encrypt(sellerNickName) << " "
<< encrypt(sellerPassword) << endl;
  sellerLoginFile.close();

  
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
  string customerNickNameData, customerPasswordData, customerIDData;
  string customerNickName, customerPassword, customerID;
  bool authenticated = false;
  customerLoginFile.open("customerlogin.csv", ios::in);
  cout << "Nombre de usuario: ";
  cin>>customerNickName;
  cout << "Contraseña: ";
  cin.ignore();
  getline(cin, customerPassword);

  // Dentro de este if se lee el archivo para validar los datos ingresados
  while (customerLoginFile >> customerIDData >> customerNickNameData >> customerPasswordData) {
    customerNickNameData = decrypt(customerNickNameData);
    customerPasswordData = decrypt(customerPasswordData);
    
    if (customerNickNameData == customerNickName && customerPasswordData == customerPassword) {
      authenticated = true;
      customerID = customerIDData;
      //crear objeto de cliente
      userCreation("Customer", customerID, customerNickName, encrypt(customerPassword));
      break;
    }
  }
  customerLoginFile.close();
  
  return authenticated;
}

bool sellerSignIn() {
  ifstream sellerLoginFile;
  string sellerNickNameData, sellerPasswordData, sellerIDData;
  string sellerNickName, sellerPassword, sellerID;
  bool authenticated = false;
  sellerLoginFile.open("sellerlogin.csv", ios::in);

  cout << "Nombre de usuario: ";
  cin>>sellerNickName;
  cout << "Contraseña: ";
  cin.ignore();
  getline(cin, sellerPassword);


    while (sellerLoginFile >> sellerIDData >> sellerNickNameData >> sellerPasswordData) {
    sellerNickNameData = decrypt(sellerNickNameData);
    sellerPasswordData = decrypt(sellerPasswordData);
    
    if (sellerNickNameData == sellerNickName && sellerPasswordData == sellerPassword) {
      authenticated = true;
      sellerID = sellerIDData;
      //crear objeto de cliente
      userCreation("Seller", sellerID, sellerNickName, encrypt(sellerPassword));
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
    int randomIndex = 0 + rand() / (RAND_MAX / (sample.size()) + 1);
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

string toLower(string word)
{
  for(int i = 0; i < word.length(); i++)
    {
      word[i] = tolower(word[i]);
    }
  return word;
}

void productRegistration() {
  ofstream productsFile("products.csv",ios::app);
  cin.ignore();
  cout<<"\t Nombre del producto: "<<endl;
  getline(cin,productName);
  productName = toLower(productName);
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
  productsFile<<productID<<","<<productName<<","<<productCategory<<","<<productSize<<","<<productQuantity<<","<<productPrice<<endl; product=Product(productID,productName,productCategory,productBrand,productQuantity,productPrice);
  productsFile.close();
}

void quickSort(vector<Product>&products, int start, int end) {
  if (start < end)
  {
    int pivot = splitVector(products, start, end);
    quickSort(products, start, pivot - 1);
    quickSort(products, pivot + 1, end);
    
  }
}

void printElements(vector<Product>products) {
  for (Product product : products)
    {
      string productName = product.getName();
      productName[0] = toupper(productName[0]);
      cout << productName << endl;
    }
}

void swap(Product &a,Product &b) {
    Product aux = a;
    a = b;
    b = aux;
}

int splitVector(vector<Product>&products, int start, int end) {
  string pivot = products[start].getName();
  int i = start + 1;
  for (int j = i; j <= end; j++)
  {
    if (products[j].getName() < pivot)
    {
      swap(products[i], products[j]);
      i++;
    }
  }
  swap(products[start], products[i-1]);
  return i - 1;
}

vector<vector<string>> getFileContent (string filename)
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file(filename, ios::in);
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
      return content;
    }
    else
        cout<<"No se pudo abrir el archivo\n";  
}

void productSearching() {
    string productName;
    int productQuantity, answer;
    cin.ignore();
    vector<vector<string>> content = getFileContent("products.csv");
    answer = 0;
    do
    {               
      if (answer == 0)
      {
        answer = 1;
      }
      else
      {
        cout << "¿Desea continuar comprando?" <<endl;
      cout << "1. Sí, deseo continuar" <<endl;
      cout<<"2.Eliminar elemento "<<endl;
      cout << "3. No" <<endl;
      cout<<"Opcion: ";
      cin >> answer;
      }
      switch(answer)
      {
          
        case 1:
          {            
          cout<<"\tBusque el nombre del producto: ";
            //getline(cin,productName);
            cin>>productName;
            cin.ignore();
            productName = toLower(productName);
            
          for(int i=0;i<content.size();i++)
          {
            if(productName == content[i][1] && stoi(content[i][4]) > 0)
            {
                cout<<"\tStock del producto: " << content[i][4]<<endl;
                cout<<"\tCuantas unidades del producto desea adquirir: ";
                cin >> productQuantity;
                while (productQuantity > stoi(content[i][4]))
                {
                    cout<<"\tCantidad digitada errónea. Cuantas unidades del producto desea adquirir:";
                    cin >> productQuantity;
                }
                int newProductQuantity = (stoi(content[i][4]) - productQuantity);
                cout<<"\tProcesando venta..."<<endl;
                product=Product(content[i][0],content[i][1],content[i][2],content[i][3], productQuantity, stof(content[i][5]));
                sale.push_back(product);
                quickSort(sale, 0, sale.size() - 1);
                cout << "Carrito de compra: " << endl;
                printElements(sale);
                products.push_back(product);
                content[i][4] = to_string(newProductQuantity);
                updateFile(content);
            }
          }
          }
          break;
    cin.ignore();             
        case 2:
          {
          string delete_product;
          cout<<"Digite el producto que desea eliminar: "<<endl;
        cin.ignore();  
         getline(cin,delete_product); 
            delete_product = toLower(delete_product);
          binarySearch(sale,delete_product);
          break;
          }
        default:
          break;
      }
    cin.ignore();            
      
    }while(answer <3&&answer>0);
  if (sale.size() > 0)
  {
    Sale sesionSale = Sale(sale, customer);
    cout << "\033[2J\033[0;0H";
    cout <<"Venta realizada"<<endl;
    sesionSale.printTicket();
  }
}

void updateFile(vector<vector<string>> content) {
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

void binarySearch(vector<Product>&products, string To_Find) {
            vector<vector<string>> content = getFileContent("products.csv");
    int lo = 0, hi = products.size() - 1;
    int mid=lo-(hi-lo)/2;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) 
    {
        int mid = (hi + lo) / 2;
        if (products[mid].getName() < To_Find) 
        {
            lo = mid + 1;
        }
        else 
        {
            hi = mid;
        }
    }
    if (products[lo].getName() == To_Find) 
    {
      for(int i=0;i<content.size();i++)
      {
        if(products[lo].getName() == content[i][1])
        {
          int newProductQuantity = (stoi(content[i][4]) + products[lo].getQuantity());
            content[i][4] = to_string(newProductQuantity);
            updateFile(content);
            break;
        }
      }
      products.erase(products.begin()+lo);
    }
    else if (products[hi].getName() == To_Find) 
    {
      for(int i=0;i<content.size();i++)
      {
        if(products[hi].getName() == content[i][1])
        {
          int newProductQuantity = (stoi(content[i][4]) + products[hi].getQuantity());
            content[i][4] = to_string(newProductQuantity);
            updateFile(content);
            break;
        }
      }
      products.erase(products.begin()+hi);
    }
    else 
    {
        cout << "No se encontro" << endl;
    }
}

Customer getCustomer()
{
  return customer;
}

Seller getSeller()
{
  return seller;  
}

};





