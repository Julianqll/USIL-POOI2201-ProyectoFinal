#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Venta{
protected:
  string fecha;
  int codCliente,codVendedor;//estado ,codigo de venta
  float total;
public:

  Venta() 
  {
    
  }
  ~Venta() {
    
  }
  Venta (string fecha, int codCliente,int codVendedor,float total) 
  {
    this->fecha = fecha;
    this->codCliente = codCliente;
    this->codVendedor=codVendedor;
    this->total = total; 
  }
  // metodos
  // set
  void setfecha(string);
  void setcodCliente(int);
  void setcodVendedor(int);
  void settoal(float);
  // get
  string  getfecha();
  int getcodCliente();
  int getcodVendedor();
  float gettotal();
};
















}
