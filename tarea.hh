/** @file Tarea.hh
    @brief Especificación de la clase Tarea
*/
#ifndef TAREA_HH
#define TAREA_HH

#include "tags.hh"
#include <string>
using namespace std;

/** @class Tarea
    @brief Representa una tarea, con título y 0 o más etiquetas.
*/
class Tarea {

private:
    string titulo;
    Tags tags;

public:
    //constructores

    /** @brief Crea una tarea vacía
        \pre cierto
        \post crea una tarea sin título ni etiquetas
    */
    Tarea();

    /** @brief Crea una tarea con título
        \pre cierto
        \post crea una tarea con un título pero sin etiquetas
    */
    Tarea(const string &titulo);

    /** @brief Crea una tarea con título y etiquetas
        \pre cierto
        \post crea una tarea con un título y una o más etiquetas
    */
    Tarea(const string &titulo, const Tags &tags);

    /** @brief Asigna un título a una tarea
        \pre cierto
        \post asigna un título a una tarea. Si ya tenía, queda modificado
    */
    void set_titulo(const string &titulo);

    /** @brief Consulta el título de una tarea.
        \pre la tarea tiene título
        \post devuelve el título de la tarea
    */
    string get_titulo() const;

    /** @brief Asigna etiquetas a una tarea.
        \pre la tarea tiene título
        \post asigna etiquetas a una tarea. Si ya tenía, se añaden
    */
    void set_tags(const Tags &tags);

    /** @brief Consulta las etiquetas de una tarea.
        \pre la tarea tiene etiquetas
        \post devuelve las etiquetas de la tarea
    */
    Tags get_tags() const;

    /** @brief Consulta si una tarea tiene una etiqueta.
        \pre cierto
        \post devuelve cierto si la tarea tiene la etiqueta, falso si no la tiene
    */
    bool contiene_tag(const string &tag);

    /** @brief Añade una etiqueta a una tarea.
        \pre cierto
        \post añade una etiqueta a una tarea.
    */
    bool anadir_tag(const string &tag);

    /** @brief Borra una etiqueta de una tarea.
        \pre la tarea tiene la etiqueta
        \post borra la etiqueta de una tarea.
    */
    bool borrar_tag(const string &tag);

};

#endif // TAREA_HH
