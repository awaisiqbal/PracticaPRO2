#ifndef TAREA_HH
#define TAREA_HH

#include "tags.hh"
class Tarea {

public:
    //constructores

    Tarea();
    Tarea(const string &titulo);
    Tarea(const string &titulo,const Tags &tags);


    void set_titulo(const string &titulo);
    string get_titulo() const;
    void set_tags(const Tags &tags);
    Tags get_tags() const;
    bool contiene_tag(string tag);
    void anadir_tag(string tag);
    void borar_tag(string tag);


private:
    string titulo;
    Tags tags;

};

#endif // TAREA_HH
