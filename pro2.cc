#include "agenda.hh"
#include "comanda.hh"
#include "comanda.cc"
#include "token.hh"
#include "token.cc"
#include "reloj.hh"
#include "tarea.hh"
#include "tags.hh"

int main()
{
    Comanda c;
    Agenda a;
    bool be = false;
    map<Reloj,Tarea> v;
    while(c.llegir(be)){
        bool todo_OK = true;
        if(be){
            if(c.es_consulta()){
                Reloj r("00/00/00","00:00");
                Reloj r2("31/12/99","23:59");
                string expr = "*";
                if(c.nombre_dates()!=0 or c.te_expressio() or c.te_hora() or c.nombre_etiquetes() != 0){
                    if(c.nombre_dates() > 0 ){
                        Reloj r(c.data(1));
                        Reloj r2(c.data(1));
                        if(c.nombre_dates() == 2) r2.modificar_fecha(c.data(2));
                        if(c.te_hora()){
                            r.modificar_hora(c.hora());
                            r2.modificar_hora(c.hora());
                        } else {
                            r.modificar_hora("00:00");
                            r2.modificar_hora("23:59");
                        }
                    }
                    if(c.te_expressio()) expr = c.expressio();
                    else if (c.nombre_etiquetes() == 1){ //TODO comprobar si se puede poner mas etiquetas
                        expr = c.etiqueta(1);
                    }
                }
                v = a.buscar_tarea_intervalo(r,r2,expr);
                a.imprimir_menu(v);
            } else if (c.es_modificacio()){
                // Pre: se ha realizado una consulta anteriormente
                int tasca = c.tasca();
                if(tasca < v.size()){
                    map<Reloj,Tarea>::iterator it(v.begin());
                    advance(it,tasca); // selecionamos la tarea
                    Reloj r1 = it->first;
                    Reloj r2 = it->first;
                    Tarea t = it->second;
                    if(c.te_titol()){
                        t.set_titulo(c.titol());
                    }
                    if(c.te_hora()){
                        r2.modificar_hora(c.hora());
                    }
                    if(c.nombre_dates() != 0){
                        r2.modificar_fecha(c.data(1));
                    }
                    if(c.nombre_etiquetes() != 0){
                        t.anadir_tag(c.etiqueta(1));
                    }
                    todo_OK = a.modificar_tarea(r1,r2,t);
                } else {
                    todo_OK = false;
                }

            } else if (c.es_insercio()){
                cout << "ES INSERCIO! " << endl;
                Reloj r;
                if(c.nombre_dates() == 1){
                    r.modificar_fecha(c.data(1));
                } else {
                    r = a.consultar_RelojActual();
                }
                r.modificar_hora(c.hora());
                Tags tags;
                if(c.nombre_etiquetes() != 0){
                    for(int i = 1; i <= c.nombre_etiquetes() ; ++i){
                        tags.add_tag(c.etiqueta(i));
                    }
                }

                Tarea tarea(c.titol(),tags);

                todo_OK = a.anadir_tarea(r,tarea);
                //TODO borrar la siguiente linia despues de pruebas
            a.imprimir_menu_actual();
                //TODO

            } else if (c.es_rellotge()){
                Reloj r;
                if(not c.te_hora() and not c.nombre_dates() != 0){
                    if(c.te_hora()) r.modificar_hora(c.hora());
                    if(c.nombre_dates() != 0) r.modificar_fecha(c.data(1));
                    todo_OK = a.modificar_RelojActual(r);
                } else { // caso consulta
                    r = a.consultar_RelojActual();
                    cout << r.consultar_fecha() << "   " << r.consultar_hora() << endl;
                }
            } else if (c.es_passat()){
                Reloj reloj1("00.00.00","00:00");
                Reloj reloj2 = a.consultar_RelojActual();
                string expr = "*";
                v = a.buscar_tarea_intervalo(reloj1,reloj2,expr);
                a.imprimir_menu(v);
            } else { //esborrat
                string tipus = c.tipus_esborrat();
                // Pre: se ha realizado una consulta anteriormente
                int tasca = c.tasca();

                map<Reloj,Tarea>::iterator it(v.begin());
                advance(it,tasca); // selecionamos la tarea
                Reloj r1 = it->first;
                Reloj r2 = it->first;
                Tarea t = it->second;

                if(tipus == "etiquetes"){
                    Tags tags;
                    t.set_tags(tags);
                    todo_OK = a.modificar_tarea(r1,r2,t);
                } else if(tipus == "etiqueta"){
                    t.borar_tag(c.etiqueta(1));
                    todo_OK = a.modificar_tarea(r1,r2,t);
                } else { // Borrar tarea
                    todo_OK = a.borrar_tarea(r1,t);
                }

            }

        if(not todo_OK) cout << "No s'ha realitzat" << endl;

        }
    }
}

