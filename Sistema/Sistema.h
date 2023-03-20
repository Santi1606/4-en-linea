#include <fstream>
#include <string>

using namespace std;

class Sistema{
    private:
        bool cargar_archivo();
        bool validar_datos(string nickname,string password);
        int registrar(string nickname,string password);
        int loguear(string nickname,string password);
    
    public:
        int estado;
        int opcion;
        string muestra_archivo;
        int opt;

        string seleccionar_archivo();
        //void cargar_opcion(string name_new_arch);
        int ingresar_datos(string nickname,string password);

};
