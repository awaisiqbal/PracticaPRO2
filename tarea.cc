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

bool Tarea::tratar_expr(string s){
    if(s[0] == '#'){
        return contiene_tag(s);
    } else {
        bool reg_expr = false;
        int nivel = 0;
        int i= s.length() -2;
        while(i > 2 and not reg_expr){
            if(s[i]== ')') ++nivel;
            else if(s[i]== '(') --nivel;
            if((s[i]== '.' or s[i] == ',') and nivel == 0) reg_expr = true;
            --i;
        }
        string s1, s2;
        char op = s[i+1];
        s1 = s.substr(1,i);
        s2 = s.substr(i+2,s.length()-i-3);
        if(op == '.') return (tratar_expr(s1) and tratar_expr(s2));
        else if(op == ',') return (tratar_expr(s1) or tratar_expr(s2));
    }
}
