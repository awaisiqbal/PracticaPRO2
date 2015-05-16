#include "agenda.hh"
#include "comanda.hh"
#include "comanda.cc"
#include "token.hh"
#include "token.cc"
#include "reloj.hh"
#include "tarea.hh"
#include "tags.hh"
#include <vector>

int main()
{
    Comanda c;
    Agenda a;
    bool be = false;
    map<Reloj,Tarea> v;
    vector<Reloj> vectorModificado;
    while(c.llegir(be)){
        bool todo_OK = true;
        if(be){
            if(c.es_consulta()){
                //cout << "ES CONSULTA! " << endl;
                if(not c.es_rellotge()){
                    Reloj r("00/00/00","00:00");
                    Reloj r2("31/12/99","23:59");
                    string expr = "*";
                    bool excluir_ultimo = false,intervalo_correcto = true;
                    if(c.nombre_dates()!=0 or c.te_expressio() or c.te_hora() or c.nombre_etiquetes() != 0){
                        if(c.nombre_dates() > 0 ){
                            r.modificar_fecha(c.data(1));
                            r2.modificar_fecha(c.data(1));
                            if(c.nombre_dates() == 2) r2.modificar_fecha(c.data(2));
                            if(c.te_hora()){
                                r.modificar_hora(c.hora());
                                r2.modificar_hora(c.hora());
                            }

                            if((r2<a.consultar_RelojActual() and r < a.consultar_RelojActual()) or r2<r  ){ // caso r < hora_actual y r2 > hora_actual -> solo imprimero [hora_actual,r2]
                                intervalo_correcto = false;
                            }

                        }
                        if(r < a.consultar_RelojActual()){
                            r = a.consultar_RelojActual();
                        }
                        if(c.te_expressio()){
                            expr = c.expressio();
                        } else if (c.nombre_etiquetes() == 1){ //TODO comprobar si se puede poner mas etiquetas
                            expr = c.etiqueta(1);
                        }
                    } else if (c.es_passat()){ // 'passat?'
                        //cout << "passat?" << endl;
                        r2 = a.consultar_RelojActual();
                        excluir_ultimo = true;
                    }else { // '?'
                        //cout << "?" << endl;
                        r = a.consultar_RelojActual();
                    }

                    if(!(r2<r) and intervalo_correcto){ //caso que r2 sea menor que r no se hace nada
                        a.buscar_tarea_intervalo(r,r2,expr,v,excluir_ultimo);
                        a.imprimir_menu(v);
                    }


                } else { // "RELLOTGE?"
                    Reloj r = a.consultar_RelojActual();
                    r.imprimir_Reloj();
                }
            } else if (c.es_modificacio()){
                //cout << "ES MODIFICACIO! " << endl;
                // Pre: se ha realizado una consulta anteriormente
                int tasca = c.tasca()-1;
                //cout << "tasca: " << tasca << "\tsize: " << v.size() << endl;
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
                        t.anadir_tag(c.etiqueta(1));//TODO solo se puede añadir mas de 1 ?
                    }
                    todo_OK = a.modificar_tarea(r1,r2,t);
                } else {
                    todo_OK = false;
                }

            } else if (c.es_insercio()){
                //cout << "ES INSERCIO! " << endl;
                Reloj r = a.consultar_RelojActual();
                if(c.nombre_dates() != 0){
                    r.modificar_fecha(c.data(1));
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
                //a.imprimir_menu_actual();
                //TODO

            } else if (c.es_rellotge()){
                //cout << "ES RELLOTGE! " << endl;
                Reloj r = a.consultar_RelojActual();
                if( c.te_hora() or  c.nombre_dates() != 0){
                    if(c.te_hora()){
                        //cout << "\t modificar hora..." << endl;
                        r.modificar_hora(c.hora());
                    }
                    if(c.nombre_dates() != 0){
                        //cout << "\t modificar fecha..." << endl;
                        r.modificar_fecha(c.data(1));
                    }
                    todo_OK = a.modificar_RelojActual(r);
                    //if(todo_OK) cout << "\tTodo OK!" << endl;
                } else { // caso consulta
                    r = a.consultar_RelojActual();
                    r.imprimir_Reloj();
                }
            } else if (c.es_esborrat()) { //esborrat
                //cout << "ES ESBORRAT! " << endl;
                string tipus = c.tipus_esborrat();
                // Pre: se ha realizado una consulta anteriormente
                int tasca = c.tasca()-1;
                //cout << "tasca:   " << endl;
                if(tasca <= v.size()-1){ // comprobar posicion correcta!
                    map<Reloj,Tarea>::iterator it(v.begin());
                    advance(it,tasca); // selecionamos la tarea
                    Reloj r1 = it->first;
                    Reloj r2 = it->first;
                    Tarea t = it->second;

                    if(tipus == "etiquetes"){
                        //cout << "\t etiquetes..." << endl;
                        Tags tags;
                        t.set_tags(tags);
                        todo_OK = a.modificar_tarea(r1,r2,t);
                    } else if(tipus == "etiqueta"){
                        //cout << "\t etiqueta..." << endl;
                        todo_OK = t.borrar_tag(c.etiqueta(1));
                        if(todo_OK) todo_OK = a.modificar_tarea(r1,r2,t);
                    } else if(tipus == "tasca"){ // Borrar tarea
                        //cout << "\t tasca..." << endl;
                        //cout << "imprimendo Reloj...     " ; r1.imprimir_Reloj();
                        todo_OK = a.borrar_tarea(r1,t);

                    }
                } else {
                    todo_OK = false;
                }

            }
        //if(todo_OK) cout << "Si s'ha realitzat" << endl;
        if(not todo_OK) cout << "No s'ha realitzat" << endl;

        }
    }
}

