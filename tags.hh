/** @file Tag.hh
    @brief Especificación de la clase Tag
*/

#ifndef TAGS_HH
#define TAGS_HH

#include "Reloj.hh"
#include "map"

/** @class Tags

    @brief Representa una colección de etiquetas
 */
class Tags{

private:
    map<string,bool> lista; // lista de todas las tareas que tienen este tag
    int posicio(Reloj x,const vector<Reloj> &v, int esq, int dre); // buscar un elemento

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
    bool search_tag(const string &tag); // true si el el map contiene el tag y esta en true;

    // Modificadores

    /** @brief Añade una etiqueta en la lista

        \pre cierto
        \post añade una etiqueta en la lista
     */
    void add_tag(const string &tag);

    /** @brief Borra la etiqueta de la lista

        \pre la etiqueta esta en la lista
        \post cierto
     */
    void borrar_tag(const string &tag);

};

#endif // TAGS_HH
