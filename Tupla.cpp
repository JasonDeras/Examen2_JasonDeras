#include<iostream> 
#include<string> 
#include<vector>
#include<bits/stdc++.h>

#ifndef TUPLA_CPP
#define TUPLA_CPP
using namespace std;

class Tupla{
      
      private:
        int id;
		vector<string>atributos;                        
      public:

            Tupla(){
                id=0;
            }//constructor vacio
            
            Tupla(int id){
                this->id=id;        
             } 
                         
             void setId(int id){
                this->id=id;  
             }//set del id;

             int getId(){
                return id;
             }//get del id

            void setAtributos(vector<string>atributos){
                this->atributos=atributos;
            }//Set de los atributos
             
            void setAtributo(string atributo){
                this->atributos.push_back(atributo);
            }//Set de una solo atributo
             
            vector<string> getAtributos(){
                return this->atributos;
            }//Get del vector de los atributos

            void print(){

                cout<<"La Tupla "<<endl 
                <<"id:"<<id<<endl;

                cout<<"Atributos"<<endl;
                for(int i=0;i<atributos.size();i++){
                  	cout<<atributos.at(i);
				}//fin del for de impresion de los atributos
                cout<<endl<<endl;

             }//fin del print
			 
			~Tupla(){

            }//destructor           
};
#endif