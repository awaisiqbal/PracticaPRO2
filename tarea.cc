#include "tarea.hh"

Tarea::Tarea(){}


Tarea::Tarea(const string &titulo){
    this->titulo = titulo;
    this->lista_tags;
}

Tarea::Tarea(const string &titulo,const vector<Tag> &tags){
    this->titulo = titulo;
    this->lista_tags = tags;
}

void Tarea::set_titulo(const string &titulo){
    this->titulo = titulo;
}

string Tarea::get_titulo(){
    return titulo;
}

void Tarea::set_tags(const vector<Tag> &tags){
    this->lista_tags = tags;
}

vector<Tag> Tarea::get_tags(){
    return lista_tags;
}
