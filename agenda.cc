#include "agenda.hh"

Agenda::Agenda()
{

}

void Agenda::comprobar_expr(map<Reloj,Tarea> &mymap,const string &expr){
    if(expr != "*"){
        map<Reloj,Tarea>::iterator it = mymap.begin();
        while(it != mymap.end()){
            Tarea ta = it->second;
            bool cumple_expr = tratar_expr(expr,ta);
            if(!cumple_expr){
                mymap.erase(it++);
            } else {
                ++it;
            }
        }
    }
}

bool Agenda::buscar_tarea_intervalo(const Reloj &reloj1,const Reloj &reloj2,const string &expr,map<Reloj,Tarea> &mymap,bool excluir_ultimo) {
    mymap.clear();
    map<Reloj,Tarea>::const_iterator it1 = horario.lower_bound(reloj1);
    if(it1 != horario.end()){
        map<Reloj,Tarea>::const_iterator it2 = horario.upper_bound(reloj2);
        map<Reloj,Tarea> aux (it1,it2);
        if (excluir_ultimo and aux.size() != 0) {//Se exluye el último por el return de upper_bound que incluye el valor de reloj2
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
            //cout << "modificación de reloj!" << endl;
            if(borrar_tarea(reloj1,t)){
                todo_ok = anadir_tarea(reloj2,t);
                todo_ok = true;
            }

        } else {
                //cout << "Modificacion de tarea!" << endl;
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
    if(tiempo_actual<=r){
        tiempo_actual = r;
    } else {
        todo_ok = false;
    }
    return todo_ok;
}


bool Agenda::tratar_expr(string s, Tarea &t){
    if(s[0] == '#'){
        return t.contiene_tag(s);
    } else {
        bool reg_expr = false;
        int nivel = 0;
        int i= s.length() -2;
        while(i >= 0 and not reg_expr){
            if(s[i]== ')') ++nivel;
            else if(s[i]== '(') --nivel;
            if((s[i]== '.' or s[i] == ',') and nivel == 0) reg_expr = true;
            --i;
        }
        string s1, s2;
        char op = s[i+1];
        s1 = s.substr(1,i);
        s2 = s.substr(i+2,s.length()-i-3);
        if(op == '.') return (tratar_expr(s1,t) and tratar_expr(s2,t));
        else return (tratar_expr(s1,t) or tratar_expr(s2,t));
    }
}
