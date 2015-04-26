#ifndef TAG_HH
#define TAG_HH

#include "Reloj.hh"
class Tag{

public:
    // Constructores

    Tag();
    Tag(const string &titulo,const vector<Reloj> &list);

    // Consultores

    string get_titulo();
    vector<Reloj> get_list();

    // Modificadores
    void set_list(vector<Reloj> r);
    void anadir_Reloj(Reloj r);
    void eliminar_Reloj(Reloj r);

private:
    string titulo;
    vector<Reloj> lista; // lista de todas las tareas que tienen este tag
    int posicio(Reloj x,const vector<Reloj> &v, int esq, int dre); // buscar un elemento
};

#endif // TAG_HH
