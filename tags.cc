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

bool Tags::add_tag(const string &tag)
{
    std::pair<std::map<string,bool>::iterator,bool> ret;//creamos un pair para recibir el iterador de
                                                        //la posicion donde se ha guardado y si se ha añadido
    ret = lista.insert(pair<string,bool>(tag,false));

    return ret.second;
}

bool Tags::borrar_tag(const string &tag)
{
    bool todo_ok = false;
    map<string,bool>::iterator it (lista.find(tag));
    if(it != lista.end()){
        todo_ok = true;
        lista.erase(it);
    }
    return todo_ok;
}

void Tags::imprimir_tags()
{
    map<string,bool>::iterator it(lista.begin());
    while(it != lista.end()){
        cout << " ";
        cout << it->first ;
        ++it;
    }
}

