#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include "Relacion.cpp"
#include "Tupla.cpp"
#include <stdlib.h>
#include<time.h>
using namespace std;

//Variables de control
Relacion* relacion;
Tupla* tupla=new Tupla();

//Vector para contorlar las relaciones
vector<Relacion*>relaciones;
vector<string> comas;

string token(string cadena, string divisor,int pos){
               
    if(cadena.size()>0){
    	char oracion[cadena.size()]; 
                 
        for (int i=0;i<=cadena.size();i++){
          oracion[i]=cadena[i];
        }//fin del for 
        char *ptrtoken; 
        int num=1;
        const char* d=divisor.c_str();
        ptrtoken = strtok(oracion , d);
        while(ptrtoken){
          if(num==pos){ 
            return ptrtoken;
          }//fin del if                  
          ptrtoken = strtok(NULL, d);
          num++;
        }//fin del while
        return "";
    }else{
    	return "";
    }
}//fin del metodo del token 

void leer_Sencilla(){

    fstream Leer;
    string linea;              
    Leer.open("./relaciones.txt"); 
    int cont=0;

    if (Leer.is_open()){
    	while(! Leer.eof()){
    		getline(Leer,linea);             
        	if(linea.size()>0){//Atoi es de string a id o de cualquier otro numero  
         		cout<<"Posicion: "<<cont<<endl;
         		cout<<"Nombre: "<<token(linea,";",1);
         		relaciones.push_back(new Relacion(token(linea,";",1)));
            	cout<<"\nEncabezados: "<<token(linea,";",2);
            	comas.push_back(token(linea,";",2));
            	cont++;
            	cout<<endl<<endl;
        	} 
        }

    }     
     Leer.close();

}//fin del metodo lectura de realciones sencillas

int menu(){
	srand(time(NULL));
	int opcion;

	cout<<"Menu\n\n";
	cout<<"1. Crear Relacion"<<endl;
	cout<<"2. Ver Relaciones"<<endl;
	cout<<"3. Insertar Tupla"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>opcion;
	cout<<endl<<endl;
	return opcion;

}//fin del metodo del menu

void Crear_Relacion(){
	
	vector<string>encabezados;                        
    string nombre;
    int cantidad_encabezados;
    string encabezado;

    cout<<"Ingrese el nombre de la la relacion: ";
    cin>>nombre;
    cout<<"Ingrese la cantidad de encabezados que desea: ";
    cin>>cantidad_encabezados;

    while(cantidad_encabezados<=0){
    	cout<<"La cantidad de encabezados debe de ser mayor a cero "<<endl<<endl;
    	cout<<"Ingrese la cantidad de encabezados que desea: ";
    	cin>>cantidad_encabezados;
    }//while que valida los numeros negativos


    while(cantidad_encabezados>0){
    	cout<<"Ingrese el encabezado: ";
    	cin>>encabezado;
    	encabezados.push_back(encabezado);
    	cantidad_encabezados--;
    }//agrega los encabezados

    relacion=new Relacion(nombre);
    relacion->setEncabezados(encabezados);
    relacion->Relacion_Sencilla();
}//fin del metodo para crear las relaciones

int main(){

	int usuario=1;

	while(usuario==1){

		switch(menu()){

			case 1:{
				Crear_Relacion();
			break;}

			case 2:{
				cout<<"Realciones"<<endl<<endl;
				leer_Sencilla();	
			break;}

			case 3:{

				string atributo;
				int cant_comas=0;

				string coma;
				int pos;

				int id=1000+rand()%(10000-1);

				cout<<"Realciones"<<endl<<endl;
				leer_Sencilla();

				cout<<"Ingrese la poscion en la que inserta la tupla: ";
				cin>>pos;	
				while(pos<0|| pos>relaciones.size()){
					cout<<"Posicion no valida"<<endl<<endl;
					cout<<"Ingrese la poscion en la que inserta la tupla: ";
					cin>>pos;
				}//fin del while de las posiciones
				tupla=new Tupla(id);

				coma=comas[pos];

				for(int i=0;i<coma.size();++i){
					if(coma[i]==','){
						cant_comas++;
					}
				}//fin del for de los atributos

				while(cant_comas>0){
					cout<<"Ingrese un atributo de a tupla: ";
					cin>>atributo;
					tupla->setAtributo(atributo);
					cant_comas--;
				}//fin del while de los atributos para la coma
				relaciones[pos]->setTupla(tupla);
				relaciones[pos]->Relacion_tupla(relaciones[pos]->getNombre());

			break;}

			case 4:
				delete tupla;
				//delete relaciones;
				delete relacion;
				exit(1);
			break;

			default:{
				cout<<"Opcion no valida"<<endl<<endl;
			break;}	
		}//fin del swtich del men

		cout<<"Volver al menu [1.-Si/2.-No]: ";
		cin>>usuario;
		cout<<endl<<endl;
	}//fin del while repetitivo
	delete tupla;
	delete relacion;
	//delete relaciones;
}//fin del main 
