#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <random>

#include "Archivo.h"
#include "Juego.h"
#include "Sistema.h"

using namespace std; 

    
int Sistema::ingresar_datos(string nickname,string password){
    if(validar_datos(nickname,password)==true){
        if (opt==1){
            loguear(nickname,password);
        }
        if(opt==2){
            registrar(nickname,password);
        }

    }
    else{
        cout<<"datos incorrectos"<<endl;
        estado=4;
    }
    return estado;
};

int Sistema::loguear(string nickname,string password){
    string acu2;
    string acu;
    int x;
    int y;
    ifstream ad("jugadores.txt");
    ifstream ad2("passwords.txt");

    ad >> acu;
    ad2 >> acu2;
    /*while(ad >> acu){
        cout<<acu<<" "<<endl;  */       
        if(acu == nickname){
            x = 1;
        }    
        else{
            x=2;
        }
    //}
   /* while(ad2 >> acu2){
        cout<<acu2<<" "<<endl;       */ 
        if(acu2 == password){
            y = 1;
        }
            
        else{
            y=2;
        }
    //}  
    ad.close();
    ad2.close();
    if(x==1 && x==y){
        estado=1;     
    }
    else if(x==1 && y==2){
        estado =3;
    }
    else if(x==2){
        estado=2;
    }
    return estado;
};


bool Sistema::validar_datos(string nickname,string password){
    bool res;
    if((int)nickname[0]>=65 && (int)nickname[0]<=90 && nickname.length()<12 && password.length()<9 ){
        res=true;
    }
     else{
        res=false;
    }
    for(int i=0;i<password.length();i++){
        if((int)password[i]>=56 && (int)password[i] <= 64 || (int)password[i]>=33 && (int)password[i] <= 47 && (int)password[i]!=32 && (int)nickname[i]!=32){
            res=true;   
        }
        else{
            res=false;
        }
    }
    return true;
};

int Sistema::registrar(string nickname,string password){
    string acu;
    ifstream ad("jugadores.txt");
    ifstream ad2("passwords.txt");
    while(ad >> acu){         
        if(acu == nickname){
            estado = 5;
            return estado;
        }
    }
    ad.close();
    ad2.close();
    ofstream texto;
    texto.open("jugadores.txt",ios::app);
    texto<<"-"+nickname+"\n";
    texto.close();
    texto.open("passwords.txt",ios::app);
    texto<<"-"+password+"\n";
    return estado;
};




/*void Sistema::cargar_opcion(string name_new_arch){    
    Archivo ar;
    if(opcion==1){
        ar.buscar_aprendizaje();
    }
    if(opcion==2){
        ar.crear_registro(name_new_arch);
        
    }  
};*/
