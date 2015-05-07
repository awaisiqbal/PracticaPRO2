#include "tarea.hh"
//#include <string>

Tarea::Tarea(){}


Tarea::Tarea(const string &titulo){
    this->titulo = titulo;
    this->tags;
}

Tarea::Tarea(const string &titulo,const Tags &tags){
    this->titulo = titulo;
    this->tags = tags;
}

void Tarea::set_titulo(const string &titulo){
    this->titulo = titulo;
}

string Tarea::get_titulo() const{
    return titulo;
}

void Tarea::set_tags(const Tags &tags){
    this->tags = tags;
}

Tags Tarea::get_tags() const{
    return tags;
}

bool Tarea::contiene_tag( const string &tag){
    return tags.search_tag(tag);
}

bool Tarea::anadir_tag(const string &tag){
   return tags.add_tag(tag);
}

bool Tarea::borrar_tag(const string &tag){
   return tags.borrar_tag(tag);
}

