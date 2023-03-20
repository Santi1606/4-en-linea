#include <fstream>
#include <string>

using namespace std;

class Usuario{    
    public:
        string nickname;
        string password;
        int rol;
};


class Administrador:public Usuario{
    public:
        string mail;
        
};


class Jugador:public Usuario{
    public:
        
};

