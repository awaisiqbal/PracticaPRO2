#ifndef AGENDA_HH
#define AGENDA_HH

#include "Reloj.hh"
#include "Tarea.hh"
#include "list"
#include "map"
class Agenda {

public:

    Agenda();

    list<Tarea> buscar_tarea_intervalo(const Reloj &r1,const Reloj &r2,const string &expr) const;
    list<Tarea> buscar_por_tags(const string &expr) const;
    void imprimir_menu(const list<Tarea> &lista);
    bool anadir_tarea(const Tarea &t);
    bool modificar_tarea(const Reloj &r, const Tarea &t);
    bool borrar_tarea(const Tarea &t);
    bool mostrar_y_modificar(); // muestra todas las tareas y deja opcion de modificar


private:
    Reloj tiempo_actual;
    map<Reloj,Tarea> horario;

};

#endif // AGENDA_HH
