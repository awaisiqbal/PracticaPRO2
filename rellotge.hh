#ifndef RELLOTGE_HH
#define RELLOTGE_HH

class Rellotge {

public:
    //Constructores

    Rellotge();

    Rellotge(int dia,int mes,int any);

    Rellotge(int hora,int min);

    Rellotge(int hora, int min, int dia, int mes, int any);

    //Modificadores

    void set_fecha(int dia, int mes, int any);

    void set_hora(int hora, int min);

    //Consultores

    bool es_mayor_que(Rellotge r);


};

#endif // RELLOTGE_HH
