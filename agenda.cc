#include "agenda.hh"

Agenda::Agenda()
{

}

map<Reloj,Tarea> Agenda::buscar_tarea_intervalo(const Reloj &reloj1,const Reloj &reloj2,const string &expr) const{

}


void Agenda::imprimir_menu(const map<Reloj,Tarea> &lista_tareas){

}

bool Agenda::anadir_tarea(const Reloj &r, const Tarea &t){

}

bool Agenda::modificar_tarea(const Reloj &reloj1, const Reloj &reloj2, const Tarea &t){

}

bool Agenda::borrar_tarea(const Reloj &r, const Tarea &t){

}

Reloj Agenda::consultar_RelojActual(){
    return tiempo_actual;
}

bool Agenda::modificar_RelojActual(Reloj r){
    tiempo_actual = r;
}
