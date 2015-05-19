#include "agenda.hh"

Agenda::Agenda()
{}


bool Agenda::buscar_tarea_intervalo(const Reloj &reloj1,const Reloj &reloj2,const string &expr,map<Reloj,Tarea> &mymap,bool excluir_ultimo) {
    bool todo_OK = false;
    mymap.clear(); //se borra el resultado de la consulta anterior
    map<Reloj,Tarea>::const_iterator it1 = horario.lower_bound(reloj1);  //miramos si esta el el reloj1 en el map o algun elemento que sea mayor que eso
    if(it1 != horario.end()){//si no hay ninguno ne se hace nada
        map<Reloj,Tarea>::const_iterator it2 = horario.upper_bound(reloj2); //buscamos el intervalo donde el reloj2 es < que el siguiente elemento
        map<Reloj,Tarea> aux (it1,it2);//creamos un map en el intervalo del map
        if (excluir_ultimo and aux.size() != 0) {//Se exluye el último por el return de upper_bound que incluye el valor de reloj2 para el caso passat?
            map<Reloj,Tarea>::iterator itUltimo = aux.end();
            --itUltimo;
            if(itUltimo->first == reloj2) aux.erase(itUltimo);
        }
        comprobar_expr(aux,expr);//comprobar que cumplan la expresion
        mymap = aux;
        todo_OK = true;
    }
    return todo_OK;
}

void Agenda::comprobar_expr(map<Reloj,Tarea> &mymap,const string &expr){
    if(expr != "*"){ //comprobar si hay alguna expresion
        map<Reloj,Tarea>::iterator it = mymap.begin();
        while(it != mymap.end()){ // si hay tareas en la agenda
            Tarea ta = it->second;
            bool cumple_expr = ta.tratar_expr(expr);//se comprueba cada tarea si cumple la expresion
            if(!cumple_expr){ // si no cumple la expresion  se borra la tarea
                mymap.erase(it++);
            } else {
                ++it;
            }
        }
    }
}

void Agenda::imprimir_menu(const map<Reloj,Tarea> &lista_tareas){
    map<Reloj,Tarea>::const_iterator it(lista_tareas.begin());
    if(it != lista_tareas.end()){
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
}

void Agenda::imprimir_menu_actual()
{
    imprimir_menu(horario);
}

bool Agenda::anadir_tarea(const Reloj &r, const Tarea &t){
    bool todo_ok = tiempo_actual <= r; // comprobamos que si el tiempo para añadir es pasado
    if(todo_ok){// si no es del pasado se añade la tarea
        std::pair<std::map<Reloj,Tarea>::iterator,bool> ret;
        ret = horario.insert(std::pair<Reloj,Tarea>(r,t));
        if(not ret.second){
            todo_ok = false;
        }
    }
    return todo_ok;
}

bool Agenda::modificar_tarea(const Reloj &reloj1, const Reloj &reloj2, const Tarea &t){
    bool todo_ok = false;
    map<Reloj,Tarea>::iterator it1(horario.find(reloj1));
    //comprobamos si para modificar la tarea los intervalos son correctos y que exista en el map
    if(reloj1 < tiempo_actual or reloj2 < tiempo_actual or it1 == horario.end()){
        todo_ok = false;
    }else{
        map<Reloj,Tarea>::iterator it2(horario.find(reloj2)); //iterador para saber si hay alguna tarea en la nueva hora
        if(not( reloj1 == reloj2) and it2 == horario.end()){ //si los dos relojes son diferentes y no hay nada en la nueva hora se modifica
            if(borrar_tarea(reloj1)){//si se ha podido borrar la tarea se añade la nueva tarrea
                todo_ok = anadir_tarea(reloj2,t);
                todo_ok = true;
            }
        } else if (not( reloj1 == reloj2) and it2 != horario.end()) {//casi que se tenga que modificar la hora y que haya una tarea en la nueva hroa
            todo_ok = false;
        } else {//todo correcto para modificar la tarea
            horario[reloj1] = t;
            todo_ok = true;
        }
    }
    return todo_ok;
}

bool Agenda::borrar_tarea(const Reloj &r){
    bool todo_ok = true;
    map<Reloj,Tarea>::iterator it(horario.find(r));
    if(it != horario.end()){ // comprobar si la tarea es del futuro y si se ha encontrado
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
    if(tiempo_actual<=r){
        tiempo_actual = r;
    } else {
        todo_ok = false;
    }
    return todo_ok;
}

