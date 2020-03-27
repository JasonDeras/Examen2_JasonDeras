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
       
        void print(){

          cout<<"La Relacion \n Nombre: "<<nombre<<endl;

          cout<<"\nLos encabezados";
          for(int i=0;i<encabezados.size();i++){
            cout<<encabezados.at(i);
          }//Fin del for de impresion de los encabezados


          cout<<"\n\nTuplas";
          for(int i=0;i<tuplas.size();i++){
            tuplas.at(i)->print();
          }//Fin del for de impresion de las tuplas

       }//fin del print
       
       ~Relacion(){

       }//destructor             
};
#endif