#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class User { 
private:
  string ID, names, nickName, password , DNI;
  int age;
public:
  User() 
  {
    
  }
  ~User() {
    
  }
  User(string ID, string names, string nickName, string password, string DNI, int age) 
  {
    this->ID = ID;
    this->names = names;
    this->nickName = nickName;
    this->password = password;
    this->DNI = DNI;
    this->age = age; 
    
  }
  // metodos
  // set
  void setID (string ID){
    this->ID = ID;
  } 

  void setNames (string names){
    this->names = names;
  } 

  void setNickName (string nickName){
    this->nickName = nickName;
  } 

   void setPassword(string password){
     this->password=password;
   }

  void setDNI(string DNI){
  this->DNI=DNI;
  }
  void setAge(int age){
   this->age=age;  
  }   

// get

  string getID(){
    return ID;
  }

  string getNames(){
    return names;
  }

  string getNickName(){
    return nickName;
  }

  string getPassword(){
    return password;
  }
 string getDNI(){
   return DNI;
 } 
  
  int getAge(){
    return age;
  } 
};







