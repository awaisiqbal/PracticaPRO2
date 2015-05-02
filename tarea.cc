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

/*
void Tarea::set_titulo(const string &titulo){

}

string Tarea::get_titulo() const{
    return "";
}
void Tarea::set_tags(const Tags &tags){

}

Tags Tarea::get_tags() const{

}
bool Tarea::contiene_tag(string tag);
void Tarea::anadir_tag(string tag);
void Tarea::borar_tag(string tag);
*/
