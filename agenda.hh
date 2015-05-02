/** @file agenda.hh
    @brief Especificación de la clase Agenda
*/
#ifndef AGENDA_HH
#define AGENDA_HH

#include "reloj.hh"
#include "tarea.hh"
#include "list"
#include "map"
#include <string>
using namespace std;

/** @class Agenda

    @brief Representa una colección de Tareas, ordenadas por la hora de tarea
 */
class Agenda {

private:
    Reloj tiempo_actual;
    map<Reloj,Tarea> horario;

public:
    /* Constructoras */

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar una agenda

        \pre cierto
        \post el resultado es una agenta sin tareas y con el reloj actual a a 20/04/15 00:00
     */
    Agenda();

    /* Modificadoras */

    /** @brief Busca tareas en un intervalos y que cumplan una expresión

        \pre <em>reloj1</em> < <em>reloj2</em> y <em>expr</em> es una string que
             puede ser '*' en caso de que no tenga ninguna condición sobre etiquetas,
             '#<etiqueta>' donde hay una sola etiqueta para buscar o que el strign
             contenga una expresion con condiciones AND y OR.
        \post El resultado es un map<Reloj,Tarea> donde están todas las tareas que hay en ese intervalo y que cumpla la expresión
     */
    map<Reloj,Tarea> buscar_tarea_intervalo(const Reloj &reloj1,const Reloj &reloj2,const string &expr) const;

    /** @brief Imprime las tareas enumeradas

        \pre lista no vacia
        \post cierto
     */
    void imprimir_menu(const map<Reloj,Tarea> &lista_tareas);

    /** @brief añade una tarea en la agenda

      \pre cierto
      \post devuelve true si se ha podido añadir y en caso contrario vuelve false
     */
    bool anadir_tarea(const Reloj &r, const Tarea &t);

    /** @brief modifica una tarea que hay en la agenda

        \pre la tarea ya este en la agenda, si no se cambia la fecha y hora <em>reloj1</em> es igual a <em>reloj2</em>
              y <em>reloj1</em> tienes que ser el reloj original y <em>reloj2</em> el reloj cambiado
        \post devuelve true si se ha podido modificar en caso contrtio se devuelve falso
     */
    bool modificar_tarea(const Reloj &reloj1, const Reloj &reloj2, const Tarea &t);

    /** @brief borra una tarrea de la agenda

        \pre La tarea esta en la agenda
        \post devuelve true si se ha podido borrar la tarea de la agenda
     */
    bool borrar_tarea(const Reloj &r, const Tarea &t);


    Reloj get_RelojActual();


    bool set_Reloj(Reloj r);

};

#endif // AGENDA_HH
