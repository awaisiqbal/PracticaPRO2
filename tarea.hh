#ifndef TAREA_HH
#define TAREA_HH

#include "Tag.hh"
#include <vector>
class Tarea {

public:
    //constructores

    Tarea();
    Tarea(const string &titulo);
    Tarea(const string &titulo,const vector<Tag> &tags);


    void set_titulo(const string &titulo);
    string get_titulo() const;
    void set_tags(const vector<Tag> &tags);
    vector<Tag> get_tags() const;


private:
    string titulo;
    vector<Tag> lista_tags; // lista ordenada de tags

};

#endif // TAREA_HH
