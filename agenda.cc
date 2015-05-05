#include "agenda.hh"

Agenda::Agenda()
{

}

map<Reloj,Tarea> Agenda::buscar_tarea_intervalo(const Reloj &reloj1,const Reloj &reloj2,const string &expr) const{

}


void Agenda::imprimir_menu(const map<Reloj,Tarea> &lista_tareas){
    map<Reloj,Tarea>::const_iterator it(lista_tareas.begin());
    int pos = 1;
    while(it != lista_tareas.end()){
        Reloj r = it->first;
        Tarea ta = it->second;
        cout << pos << " " << ta.get_titulo() << " " << r.consultar_fecha() << " " << r.consultar_hora();
        ta.get_tags().imprimir_tags();
        cout << endl;
        ++it;
    }
}

void Agenda::imprimir_menu_actual()
{
    imprimir_menu(horario);
}

bool Agenda::anadir_tarea(const Reloj &r, const Tarea &t){
    std::pair<std::map<Reloj,Tarea>::iterator,bool> ret;
    ret = horario.insert(std::pair<Reloj,Tarea>(r,t));
    bool todo_ok = true;
    if(not ret.second){
        todo_ok = false;
    }
    return todo_ok;

}

bool Agenda::modificar_tarea(const Reloj &reloj1, const Reloj &reloj2, const Tarea &t){
    //TODO comprobar si es pasado -> error , tarea borrada -> error y realizar modificación
}

bool Agenda::borrar_tarea(const Reloj &r, const Tarea &t){
    horario.erase(r);
    return true;
}

Reloj Agenda::consultar_RelojActual(){
    return tiempo_actual;
}

bool Agenda::modificar_RelojActual(Reloj r){
    tiempo_actual = r;
}
