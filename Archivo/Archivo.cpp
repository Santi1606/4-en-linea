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

    
void Archivo::buscar_aprendizaje(){
    ifstream archivo;
    string acu;
    archivo.open("aprendizaje_1.txt",ios::in);
    while(!archivo.eof()){
        getline(archivo,acu);
        lista_archivos=lista_archivos+acu;    
    }
    cout<<lista_archivos;
    archivo.close();
};

void Archivo::crear_registro(string name_new_arch){
    ofstream texto;
    texto.open(name_new_arch+".txt",ios::out);

};

