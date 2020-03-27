#include<iostream> 
#include<string> 
#include<vector>
#include<bits/stdc++.h>
#include "Tupla.cpp"

#ifndef RELACION_CPP
#define RELACION_CPP
using namespace std;

class Relacion{
      
  private:
    vector<string>encabezados;                        
    string nombre;
    vector<Tupla*>tuplas;
  public:

    Relacion(){
      nombre="";
    }//constructor vacio
            
    Relacion(string nombre){
      this->nombre=nombre;        
    }//constructor sobrecargado 

    void setEncabezados(vector<string>encabezados){
      this->encabezados=encabezados;
    }//set de los encabezados
             
    void setEncabezado(string encabezado){
      this->encabezados.push_back(encabezado);
    }//set de una solo encabezado
             
    vector<string> getEncabezados(){
      return this->encabezados;
    }//Get del vector de los encabezados     
        
    void setNombre(string nombre){
      this->nombre=nombre;  
    }//set del nombre

    string getNombre(){
      return nombre;
    }//get del nombre

    void setTuplas(vector<Tupla*>tuplas){
      this->tuplas=tuplas;
    }//set de los tuplas
             
    void setTupla(Tupla*tupla){
      this->tuplas.push_back(tupla);
    }//set de una sola tupla
             
    vector<Tupla*> getTuplas(){
      return this->tuplas;
    }//set del vector las tuplas

    void Relacion_Sencilla(){

      ofstream Escribir;
      Escribir.open("./relaciones.txt",std::ios::app);
      Escribir<<nombre<<";";
      for (int i = 0; i < encabezados.size(); ++i){
          Escribir<<encabezados[i]<<",";
      }
      Escribir<<";"<<endl;
      Escribir.close();

    }//fin del metodo para guardar relaciones con sus encabezados

    void Relacion_tupla(string ruta){

      ofstream Escribir;
      Escribir.open("./"+ruta+"txt",std::ios::app);
      for (int i = 0; i <tuplas.size(); ++i){
          Escribir<<tuplas.at(i)->getId()<<","
          <<tuplas.at(i)->getAtributos().at(i)<<",";
      }

      Escribir<<";"<<endl;
      Escribir.close();
    }//fin del metodo para escribir el 
    ~Relacion(){

    }//destructor             

};
#endif