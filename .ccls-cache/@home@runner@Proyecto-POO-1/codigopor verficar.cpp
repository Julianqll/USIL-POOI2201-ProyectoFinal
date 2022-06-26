class VendedorVector
{
	private:

		vector<Vendedor> vectorVendedor;
	public:
		VendedorVector()
		{
			vector<Vendedor> vectorVendedor;
		   cargarDatosDelArchivoAlVector();
		}
		
		
		void add(Vendedor obj)/*Agrgar Objetos al Vector*/
		{
			vectorVendedor.push_back(obj);
		}
		
		Vendedor get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
		{
			return vectorVendedor[pos];
		}
		
		int rows()
		{
			return vectorVendedor.size();
		}
		
		
		Vendedor buscarPorCodigo(int codigo)
		{
			Vendedor objError;
			objError.setNombre_usuario("Error");
			for(Vendedor x:vectorVendedor)
			{
				if(codigo == x.getCodigo())
				{
					return x;
				}
			}
		   return objError;
		}
		
		
		int getPostArray(Vendedor obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					return i;
				}
			}
			return -1;
		}
		
		void remove(Vendedor obj)
		{
			vectorVendedor.erase(vectorVendedor.begin() + getPostArray(obj));	
		}
		int getCorrelativo()
		{
		   if(vectorVendedor.size()==0)
		{
		    return 1;
		}
		else
		{
		  return vectorVendedor[vectorVendedor.size()-1].getCodigo()+1;
		}
		}
		bool modificar(Vendedor obj,string nombre_usuario)
		{
		  for(int i=0;i<rows();i++)
		  {
		   if(obj.getCodigo()==get(i).getCodigo())
		    {
		   vectorVendedor[i].setNombre_usuario(nombre_usuario);
		   return true ;
	
		}  
		 }
		 return false; 
		}
		
		void grabarEnArchivo(Vendedor vendedor)
		{
			try
			{
				fstream archivoVendedor;
				archivoVendedor.open("alumnos.csv",ios::app);
				if(archivoVendedor.is_open())
				{
					archivoVendedor<<vendedor.getCodigo()<<";"<<vendedor.getNombre_usuario()<<";"<<vendedor.getedad()<<";";
					archivoVendedor.close();
				}
			}			
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarEliminarArchivo() 
         { 
          try
        {  
           fstream archivoVendedores;
        archivoVendedores.open("alumnos.csv", ios::out);
           if (archivoVendedores.is_open())
        {
           for (Vendedor x : vectorVendedor)
      {
archivoVendedores << x.getCodigo() << ";" << x.getNombre_usuario() << ";" <<x.getedad()<<"\n";
               
             }
              archivoVendedores.close();
            }
         }
         catch (exception e)
       {
     cout << "Ocurrio un error al grabar en el archivo";
        }
 }   
	
	void cargarDatosDelArchivoAlVector()
    {
     try
     {
    int i;
      size_t posi;//Cantidad maxima
       string linea;
        string temporal[3];//Cantidad de columnas
       fstream archivoVendedor;
       archivoVendedor.open("alumnos.csv", ios::in);
        if (archivoVendedor.is_open())
        {
         while (!archivoVendedor.eof()) 
        {
        while (getline(archivoVendedor, linea))
        {
         i = 0;
        while ((posi = linea.find(";")) != string::npos) 
           {/*string::npos es -1, termina cuando llega a este punto*/
          temporal[i] = linea.substr(0, posi);/*posi 
= Es la cantidad de caracteres antes del ;*/
        linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, 	ara que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso ,
    i++;
      }
   //Asignando los valores al vector
   Vendedor vendedor;
   vendedor.setCodigo(std::stoi(temporal[0]));
   vendedor.setNombre_usuario(temporal[1]);
   vendedor.setedad(std::stoi(temporal[2]));
   add(vendedor);
    }
     }
     }
    archivoVendedor.close();
    }
     catch (exception e)
    {
    cout << "Ocurrio un error al leer el archivo";
   }
    }
};  



class ProductoVector
{
	private:
		vector<Producto> vectorProducto;
	public:
		ProductoVector()
		{
			vector<Producto> vectorProducto;
		   cargarDatosDelArchivoAlVector();
		}
		
		
		void add(Producto obj)/*Agrgar Objetos al Vector*/
		{
			vectorProducto.push_back(obj);
		}
		
		Producto get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
		{
			return vectorProducto[pos];
		}
		
		int rows()
		{
			return vectorProducto.size();
		}
		
		
		Producto buscarPorCodigo(int codigo)
		{
			Producto objError;
			objError.setnombre("Error");
			for(Producto x:vectorProducto)
			{
				if(codigo == x.getcodigo())
				{
					return x;
				}
			}
		   return objError;
		}
		
		
		int getPostArray(Producto obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getcodigo() == get(i).getcodigo())
				{
					return i;
				}
			}
			return -1;
		}
		
		void remove(Producto obj)
		{
			vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));	
		}
		int getCorrelativo()
		{
		   if(vectorProducto.size()==0)
		{
		    return 1;
		}
		else
		{
		  return vectorProducto[vectorProducto.size()-1].getcodigo()+1;
		}
		}
		bool modificar(Producto obj,string nombre_usuario)
		{
		  for(int i=0;i<rows();i++)
		  {
		   if(obj.getcodigo()==get(i).getcodigo())
		    {
		   vectorProducto[i].setnombre(nombre);
		   return true ;
	
		}  
		 }
		 return false; 
		}
		
		void grabarEnArchivo(Producto producto)
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("alumnos.csv",ios::app);
				if(archivoProducto.is_open())
				{
					archivoProducto<<producto.getcodigo()<<";"<<producto.getnombre()<<";"<<producto.getcantidad()<<";"<<producto.getprecio();
					archivoProducto.close();
				}
			}			
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarEliminarArchivo() 
         { 
          try
        {  
           fstream archivoProductos;
        archivoProductos.open("alumnos.csv", ios::out);
           if (archivoProductos.is_open())
        {
           for (Producto x : vectorProducto)
      {
archivoProductos << x.getcodigo() << ";" << x.getnombre() << ";" <<x.getcantidad()<<";"<<x.getprecio()<<";"<<"\n";
               
             }
              archivoProductos.close();
            }
         }
         catch (exception e)
       {
     cout << "Ocurrio un error al grabar en el archivo";
        }
 }   
	
	void cargarDatosDelArchivoAlVector()
    {
     try
     {
    int i;
      size_t posi;//Cantidad maxima
       string linea;
        string temporal[4];//Cantidad de columnas
       fstream archivoProducto;
       archivoProducto.open("alumnos.csv", ios::in);
        if (archivoProducto.is_open())
        {
         while (!archivoProducto.eof()) 
        {
        while (getline(archivoProducto, linea))
        {
         i = 0;
        while ((posi = linea.find(";")) != string::npos) 
           {/*string::npos es -1, termina cuando llega a este punto*/
          temporal[i] = linea.substr(0, posi);/*posi 
= Es la cantidad de caracteres antes del ;*/
        linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, 	ara que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso ,
    i++;
      }
   //Asignando los valores al vector
   Producto producto;
   producto.setcodigo(std::stoi(temporal[0]));
   producto.setnombre(temporal[1]);
   producto.setcantidad(std::stoi(temporal[2]));
 producto.setprecio(std::stoi(temporal[3]));
   add(producto);
    }
     }
     }
    archivoProducto.close();
    }
     catch (exception e)
    {
    cout << "Ocurrio un error al leer el archivo";
   }
    }
};

class ClienteVector {
private:
  vector<Cliente> vectorCliente;

public:
  ClienteVector() {
    vector<Cliente> vectorCliente;
    cargarDatosDelArchivoAlVector();
  }

  void add(Cliente obj) 
  {
    vectorCliente.push_back(obj);
  }

  Cliente get(int pos) /*entregar el objeto actual, según la posicion pasada
                          como parámetro*/
  {
    return vectorCliente[pos];
  }

  int rows() { return vectorCliente.size(); }

  Cliente buscarPorCodigo(int codigo) {
    Cliente objError;
    objError.setNombre_usuario("Error");
    for (Cliente x : vectorCliente) {
      if (codigo == x.getcodigo()) {
        return x;
      }
    }
    return objError;
  }

  int getPostArray(Cliente obj) {
    for (int i = 0; i < rows(); i++) {
      if (obj.getcodigo() == get(i).getcodigo()) {
        return i;
      }
    }
    return -1;
  }

  void remove(Cliente obj) {
    vectorCliente.erase(vectorCliente.begin() + getPostArray(obj));
  }
  int getCorrelativo() {
    if (vectorCliente.size() == 0) {
      return 1;
    } else {
      return vectorCliente[vectorCliente.size() - 1].getcodigo() + 1;
    }
  }
  bool modificar(Cliente obj, string nombre_usuario) {
    for (int i = 0; i < rows(); i++) {
      if (obj.getcodigo() == get(i).getcodigo()) {
        vectorCliente[i].setNombre_usuario(nombre_usuario);
        return true;
      }
    }
    return false;
  }

  void grabarEnArchivo(Cliente cliente) {
    try {
      fstream archivoCliente;
      archivoCliente.open("alumnos.csv", ios::app);
      if (archivoCliente.is_open()) {
        archivoCliente << cliente.getcodigo() << ";"
                       << cliente.getNombre_usuario() << ";"
                       << cliente.getedad() << ";";
        archivoCliente.close();
      }
    } catch (exception e) {
      cout << "Ocurrio un error al grabar el registro!!!";
    }
  }
  void grabarModificarEliminarArchivo() {
    try {
      fstream archivoClientes;
      archivoClientes.open("alumnos.csv", ios::out);
      if (archivoClientes.is_open()) {
        for (Cliente x : vectorCliente) {
          archivoClientes << x.getcodigo() << ";" << x.getNombre_usuario()
                          << ";" << x.getedad() << "\n";
        }
        archivoClientes.close();
      }
    } catch (exception e) {
      cout << "Ocurrio un error al grabar en el archivo";
    }
  }

  void cargarDatosDelArchivoAlVector() {
    try {
      int i;
      size_t posi; // Cantidad maxima
      string linea;
      string temporal[3]; // Cantidad de columnas
      fstream archivoCliente;
      archivoCliente.open("alumnos.csv", ios::in);
      if (archivoCliente.is_open()) {
        while (!archivoCliente.eof()) {
          while (getline(archivoCliente, linea)) {
            i = 0;
            while ((posi = linea.find(";")) !=
                   string::npos) { /*string::npos es -1, termina cuando llega a
                                      este punto*/
              temporal[i] = linea.substr(0, posi); /*posi
     = Es la cantidad de caracteres antes del ;*/
              linea.erase(
                  0, posi + 1); // borra la palabra de la primera posición
                                // encontrada   y con el +1 incluye hasta el ; y
                                // luego borra ese elemento, 	ara que en la
                                // siguiente iteracion iniciar con la siguiente
                                // palabra y de ese modo seguir el proceso ,
              i++;
            }
            // Asignando los valores al vector
            Cliente cliente;
            cliente.setcodigo(std::stoi(temporal[0]));
            cliente.setNombre_usuario(temporal[1]);
            cliente.setedad(std::stoi(temporal[2]));
            add(cliente);
          }
        }
      }
      archivoCliente.close();
    } catch (exception e) {
      cout << "Ocurrio un error al leer el archivo";
    }
  }
};

