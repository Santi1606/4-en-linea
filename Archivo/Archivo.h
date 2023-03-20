#include <fstream>
#include <string>

using namespace std;

class Archivo{
    private:
        void crear_archivo();
        string cargar_partida();
    public:
        string lista_archivos;
        string nuevo_registro;
        string name_new_arch;

        bool guardar_partida();
        void buscar_aprendizaje();
        void crear_registro(string name_new_arch);
};
