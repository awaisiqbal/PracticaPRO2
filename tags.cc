#include "tags.hh"
Tags::Tags()
{
}

Tags::Tags(map<string,bool> lista_de_tags)
{
    this->lista = lista_de_tags;
}


map<string,bool> Tags::get_tags()
{
    return this->lista;
}

bool Tags::search_tag(const string &tag)
{
    map<string,bool>::iterator it = lista.find(tag);
    return it != lista.end();
}

void Tags::add_tag(const string &tag)
{
    lista.insert(pair<string,bool>(tag,false));
}

void Tags::borrar_tag(const string &tag)
{
    lista.erase(lista.find(tag));
}

void Tags::imprimir_tags()
{
    map<string,bool>::iterator it(lista.begin());
    while(it != lista.end()){
        cout << " " << it->first ;
    }
}

