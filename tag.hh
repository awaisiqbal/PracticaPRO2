#ifndef TAG_HH
#define TAG_HH

#include "Reloj.hh"
#include "map"
class Tags{

public:
    // Constructores

    Tags();
    Tags(map<string,bool> lista_de_tags);

    // Consultores

    map<string,bool> get_tags();
    bool search_tag(const string &tag); // true si el el map contiene el tag y esta en true;

    // Modificadores
    void add_tag(string tag);
    void change_tag(string tag,bool estado);


private:
    map<string,bool> lista; // lista de todas las tareas que tienen este tag
    int posicio(Reloj x,const vector<Reloj> &v, int esq, int dre); // buscar un elemento
};

#endif // TAG_HH
