#include "agenda.hh"

Agenda::Agenda()
{

}

void Agenda::comprobar_expr(map<Reloj,Tarea> &map,const string &expr){
    if(expr != "*"){
        //TODO comprobar las demas condiciones
    }
}

bool Agenda::buscar_tarea_intervalo(const Reloj &reloj1,const Reloj &reloj2,const string &expr,map<Reloj,Tarea> &mymap,bool excluir_ultimo) {
    map<Reloj,Tarea>::const_iterator it1 = horario.lower_bound(reloj1);
    if(it1 != horario.end()){
        map<Reloj,Tarea>::const_iterator it2 = horario.upper_bound(reloj2);
        map<Reloj,Tarea> aux (it1,it2);
        if (excluir_ultimo and aux.size() != 0) {
            map<Reloj,Tarea>::iterator itUltimo = aux.end();
            --itUltimo;
            if(itUltimo->first == reloj2) aux.erase(itUltimo);
        }
        comprobar_expr(aux,expr);
        mymap = aux;
        return true;
    }
    return false;
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
        ++pos;
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
    bool todo_ok = false;
    if(tiempo_actual<reloj1){
        map<Reloj,Tarea>::iterator it(horario.find(reloj2));
        if(not( reloj1 == reloj2) and it == horario.end()){
            cout << "modificación de reloj!" << endl;
            if(borrar_tarea(reloj1,t)){
                todo_ok = anadir_tarea(reloj2,t);
                todo_ok = true;
            }

        } else {
                cout << "Modificacion de tarea!" << endl;
                horario[reloj1] = t;
                todo_ok = true;
        }

    }


    return todo_ok;
}

bool Agenda::borrar_tarea(const Reloj &r, const Tarea &t){
    bool todo_ok = true;
    map<Reloj,Tarea>::iterator it(horario.find(r));
    if(tiempo_actual<r and it != horario.end()){ // comprobar si la tarea es del futuro y si se ha encontrado
        horario.erase(r);
    } else {
        todo_ok = false;
    }

    return todo_ok;
}

Reloj Agenda::consultar_RelojActual(){
    return tiempo_actual;
}

bool Agenda::modificar_RelojActual(Reloj r){
    bool todo_ok = true;
    if(tiempo_actual<r){
        tiempo_actual = r;
    } else {
        todo_ok = false;
    }
    return todo_ok;
}
