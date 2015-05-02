#ifndef RELOJ_HH
#define RELOJ_HH


#include <string>
using namespace std;
class Reloj {

public:
    //constructores

    Reloj();

    Reloj(int hora, int min);

    Reloj(int dia, int mes, int ano);

    Reloj(int dia, int mes, int ano, int hora, int min);

    Reloj(string datetime);// formato DD/MM/YY

    Reloj(string datetime,string hora);// formato DD/MM/YY HH:MM

    //Modificadores
    void set_fecha(string fecha);
    void set_fecha(int dia, int mes, int ano);

    void set_hora(int hora, int min);
    void set_hora(string hora);

    //Consultores

    string get_fecha();
    string get_hora();
    bool es_mayor_igual(Reloj r);


private:
    int hora;
    int min;
    int dia;
    int mes;
    int ano;


};

#endif // RELOJ_HH
