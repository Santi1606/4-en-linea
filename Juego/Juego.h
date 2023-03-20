#include <fstream>
#include <string>

using namespace std;

class Juego{
    public:
        int colu;
        int numeros[100][100];
        int modo_de_juego;
        void jugador_carga_ficha(int jugador,int colu);
        void sistema_carga_ficha();
        void crear_matriz();
        bool hay_jugada_ganadora();
};