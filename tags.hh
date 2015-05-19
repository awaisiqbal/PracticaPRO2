/** @file tags.hh
    @brief Especificación de la clase Tag
*/

#ifndef TAGS_HH
#define TAGS_HH

#include "reloj.hh"
#include "map"
using namespace std;

/** @class Tags

    @brief Representa una colección de etiquetas
 */
class Tags{

private:
    map<string,bool> lista; // lista de todas las tareas que tienen este tag

public:
    // Constructores

    /** @brief Creadora por defecto

        \pre cierto
        \post El resultado es una lista sin etiquetas
     */
    Tags();

    /** @brief Creadora por defecto

        \pre cierto
        \post El resultado es una lista con las etiquetas que se han pasado por parametro
     */
    Tags(map<string,bool> lista_de_tags);

    // Consultores

    /** @brief Devuelve todas las etiquetas

        \pre cierto
        \post devuelve todas las etiquetas que hay en la lista
     */
    map<string,bool> get_tags();

    /** @brief Busca si este tag está en la lista

        \pre cierto
        \post devuelve true si la etiqueta esta en la lista, en caso contratio devuelve falso
     */
    bool search_tag(const string &tag); // true si el el map contiene el tag ;

    // Modificadores

    /** @brief Añade una etiqueta en la lista

        \pre cierto
        \post añade una etiqueta en la lista
     */
    bool add_tag(const string &tag);

    /** @brief Borra la etiqueta de la lista

        \pre cierto
        \post borra la etiqueta de la lista
     */
    bool borrar_tag(const string &tag);

    /** @brief imprime los tags

        \pre cierto
        \post imprime todas las etiquetas
     */
    void imprimir_tags();

};

#endif // TAGS_HH
