#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

class Customer : public User{ 
public:
  Customer() 
  {
    
  }
  ~Customer() {
    
  }
  Customer(string ID, string names, string nickName, string password, string DNI, int age) : User(ID, names, nickName, password, DNI, age){}

};







