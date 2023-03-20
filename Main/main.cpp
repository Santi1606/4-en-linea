#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>


#include "Archivo.h"
#include "Juego.h"
#include "Sistema.h"
#include "Usuario.h"


using namespace std;

int main(){
Jugador player;

Juego game;
Administrador admin;
Archivo ar;
Sistema sis;
int x;

    cout<<" 1 - Jugador "<<endl;
    cout<<" 2 - Administrador "<<endl;
    cout<<"Ingrese rol:"<<endl;
    cin>>x;
    if(x == 1){
        x = player.rol;
        do{
            cout<<"1-Loguearse"<<endl;
            cout<<"2-Registrarse"<<endl;
            cin>>sis.opt;
            cout<<"Ingrese nickname:"<<endl;
            cin.ignore();
            getline(cin,player.nickname);
            cout<<"Ingrese contraseña:"<<endl;
            getline(cin,player.password);
            sis.ingresar_datos(player.nickname,player.password);
            if(sis.estado==2){
                cout<<"usuario no existe"<<endl;
            }
            if(sis.estado==3){
                cout<<"password incorrecta"<<endl;
            }
            if(sis.estado==4){
                cout<<"formato invalido"<<endl;
            }
            if(sis.estado == 5){
                cout<<"usuario existente"<<endl;
            }
            /*cout<<sis.estado;
            cout<<sis.opt;*/
        }while(sis.opt!=1 && sis.estado!=1);
        cout<<"Logueo Correcto"<<endl;
        cout<<" -1 Para jugar contra la maquina"<<endl;
        cout<<" -2 Para 2 players"<<endl;
        cin>>game.modo_de_juego;      
        game.crear_matriz();
        int jugador=0;
        while(game.hay_jugada_ganadora()==false){
            cout<<"Ingrese columna"<<endl;
            cin>>game.colu;
            game.jugador_carga_ficha(jugador,game.colu);
            if(game.modo_de_juego==1){
                game.sistema_carga_ficha();
            }
            else{
                jugador++;
            }
        };
        cout<< "jugador gano"<<endl;
    }
        



    /*if(x == 2){
        x = admin.rol;
        do{
            cout<<"1-Loguearse"<<endl;
            cout<<"2-Registrarse"<<endl;
            cin>>sis.opt;
            do{
                cout<<"Ingrese nickname:"<<endl;
                cin.ignore();
                getline(cin,admin.nickname);
                cout<<"Ingrese contraseña:"<<endl;
                getline(cin,admin.password);
            }while(sis.ingresar_datos(admin.nickname,admin.password) != 1);
        }while(sis.opt!=1); 
        cout<<"1-Solicitar aprendizaje"<<endl;
        cout<<"2-Iniciar nuevo aprendizaje"<<endl;
        cin>>sis.opcion;
        if(sis.opcion==2){
            cout<<"Ingrese nombre para nuevo archivo"<<endl;
            cin>>ar.name_new_arch;
        }
        
        //sis.cargar_opcion(ar.name_new_arch);   
    }*/
}


//g++ -o 01 main.cpp Juego.cpp Sistema.h Usuario.h Archivo.cpp Archivo.h Sistema.cpp Juego.h
//./01
