#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

class Seller : public User{ 
public:
  Seller() {
    
  }
  ~Seller() {
    
  }
  Seller(string ID, string names, string nickName, string password, string DNI, int age):User(ID, names, nickName, password, DNI, age){}
};
