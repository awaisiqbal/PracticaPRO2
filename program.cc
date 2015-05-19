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
    map<Reloj,Tarea> listaMenu;
    map<Reloj,Reloj> relojesModificados;
    while(c.llegir(be)){
        bool todo_OK = true;
        if(be){
            if(c.es_consulta()){
                if(not c.es_rellotge()){
                    Reloj r("00/00/00","00:00");
                    Reloj r2("31/12/99","23:59");
                    string expr = "*";
                    bool excluir_ultimo = false,intervalo_correcto = true;
                    if(c.nombre_dates() != 0 or c.te_expressio() or c.nombre_etiquetes() != 0){
                        // entra cuando hay alguna condicion para la consulta
                        if(c.nombre_dates() > 0 ){
                            r.modificar_fecha(c.data(1));
                            r2.modificar_fecha(c.data(1));
                            if(c.nombre_dates() == 2) r2.modificar_fecha(c.data(2)); //si hay mas de una fecha cambia el reloj2 por la segunda fecha
                            if((r2<a.consultar_RelojActual() and r < a.consultar_RelojActual()) or r2<r  ){ // caso r < hora_actual y
                                                                                                            //r2 > hora_actual -> solo imprimero [hora_actual,r2]
                                intervalo_correcto = false;
                            }

                        }
                        if(r < a.consultar_RelojActual()){//si la fecha menor es del pasado se cambia el reloj al reloj actual
                            r = a.consultar_RelojActual();
                        }
                        if(c.te_expressio()){ // si la consulta tiene una expresion
                            expr = c.expressio();
                        } else if (c.nombre_etiquetes() == 1){ // si solo tiene una etiqueta
                            expr = c.etiqueta(1);
                        }
                    } else if (c.es_passat()){ // 'passat?'
                        r2 = a.consultar_RelojActual();
                        excluir_ultimo = true;//se excluye el ultimo elemento de la busqueda ya que upper_bound incluye el elemento del reloj actual
                    }else { // '?'
                        r = a.consultar_RelojActual();
                    }

                    if(!(r2<r) and intervalo_correcto){ //caso que r2 sea menor que r o el intervalo no sea correcto no se hace nada
                        a.buscar_tarea_intervalo(r,r2,expr,listaMenu,excluir_ultimo);
                        relojesModificados.clear();//borrar todos los relojes modificados
                        a.imprimir_menu(listaMenu);
                    }


                } else { // "RELLOTGE?"
                    Reloj r = a.consultar_RelojActual();
                    r.imprimir_Reloj();
                }
            } else if (c.es_modificacio()){
                int tasca = c.tasca()-1;
                if(tasca < listaMenu.size() and listaMenu.size() != 0){ //se comprueba si la la tasca es correcta y si se ha hecho alguna consulta
                    map<Reloj,Tarea>::iterator it(listaMenu.begin());
                    advance(it,tasca); // selecionamos la tarea
                    Reloj r1 = it->first;
                    Reloj r2 = it->first;
                    Tarea t = it->second;
                    //se modifica la tarea con los datos que pasan por comanda
                    if(c.te_titol()){
                        t.set_titulo(c.titol());
                    }
                    if(c.te_hora()){
                        r2.modificar_hora(c.hora());
                    }
                    if(c.nombre_dates() != 0){
                        r2.modificar_fecha(c.data(1));
                    }
                    for(int i = 1; i <= c.nombre_etiquetes();++i ){
                        t.anadir_tag(c.etiqueta(i));
                    }

                    // buscar si se ha modificado anteriormente
                    map<Reloj,Reloj>::iterator it1(relojesModificados.find(r1));
                    if(it1 != relojesModificados.end() ){ // si se ha modificado anteriormente se elige el segundo reloj
                            r1 = it1->second;
                    }
                    todo_OK = a.modificar_tarea(r1,r2,t);
                    if(todo_OK){
                        it->second = t;
                        relojesModificados.insert(std::pair<Reloj,Reloj>(r1,r2));//se guarda el nuevo reloj
                    }
                } else {
                    todo_OK = false;
                }

            } else if (c.es_insercio()){
                Reloj r = a.consultar_RelojActual(); // un reloj pro defecto
                if(c.nombre_dates() != 0){ // si se ha modificado la fecha se cambia
                    r.modificar_fecha(c.data(1));
                }
                r.modificar_hora(c.hora()); // se modifica la hora
                Tags tags;
                if(c.nombre_etiquetes() != 0){ // se añade todos los tags que entren por la comanda
                    for(int i = 1; i <= c.nombre_etiquetes() ; ++i){
                        tags.add_tag(c.etiqueta(i));
                    }
                }
                Tarea tarea(c.titol(),tags);
                todo_OK = a.anadir_tarea(r,tarea);

            } else if (c.es_rellotge()){
                Reloj r = a.consultar_RelojActual();
                if( c.te_hora() or  c.nombre_dates() != 0){
                    if(c.te_hora()){ // caso donde se modifica la hora
                        r.modificar_hora(c.hora());
                    }
                    if(c.nombre_dates() != 0){ // caso donde se modifica la fecha
                        r.modificar_fecha(c.data(1));
                    }
                    todo_OK = a.modificar_RelojActual(r);
                } else { // caso consulta el reloj actual
                    r = a.consultar_RelojActual();
                    r.imprimir_Reloj();
                }
            } else if (c.es_esborrat()) { //esborrat
                string tipus = c.tipus_esborrat();
                int tasca = c.tasca()-1;
                todo_OK = false; // por defecto no se ha borrado
                if(tasca <= listaMenu.size()-1 and listaMenu.size() != 0){ // comprobar posicion correcta!
                    map<Reloj,Tarea>::iterator it(listaMenu.begin());
                    advance(it,tasca); // selecionamos la tarea
                    Reloj r1 = it->first;// dos relojes para selecionar intervalos
                    Reloj r2 = it->first;

                    map<Reloj,Reloj>::iterator it1(relojesModificados.find(r1));
                    if(it1 != relojesModificados.end()){
                        r1 = it1->second;//cambiar el reloj por si se ha modificado
                    }
                    Tarea t = it->second; // selecionamos la tarea a borrar o modificar
                    if(tipus == "etiquetes"){// Borrar etiquetas
                        Tags tags;
                        t.set_tags(tags);// se borran todas las etiquetas
                        todo_OK = a.modificar_tarea(r1,r2,t);// se modifica la tarea
                        if(todo_OK){
                            it->second = t;//se actualiza el menu con las etiquetas
                        }
                    } else if(tipus == "etiqueta"){ // Borrar etiqueta
                        todo_OK = t.borrar_tag(c.etiqueta(1));//se borra la etiqueta selecionada
                        if(todo_OK){
                            todo_OK = a.modificar_tarea(r1,r2,t);
                            it->second = t;//actualizar los elementos del menu
                        }
                    } else if(tipus == "tasca"){ // Borrar tarea
                        todo_OK = a.borrar_tarea(r1);
                    }
                }
            }
        if(not todo_OK) cout << "No s'ha realitzat" << endl;

        }
    }
}

