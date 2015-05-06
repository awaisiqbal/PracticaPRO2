/** @file reloj.hh
    @brief Clase Reloj
*/

#ifndef RELOJ_HH
#define RELOJ_HH
#include <string>

using namespace std;

/** @class Reloj
    @brief Representa el reloj interno.
*/


class Reloj {

private:
    string fecha, hora;
    string dar_vuelta(string fecha);


public:
    /* Constructores */

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un reloj

        \pre cierto
        \post crea el reloj inicial con hora "00:00" y dia "20.04.15".
    */
    Reloj();

    /** @brief Crea un reloj con fecha y hora, uno con valor predeterminado y el otro con valor asignado
        \pre cierto
        \post si el parámetro es un dia, crea un reloj con dia con valor del parámetro y hora "00:00",
              si el parámetro es una hora, crea un reloj con dia "20.04.15" y hora con valor del parámetro
    */
    Reloj(string fechaHora);

    /** @brief Crea un reloj con fecha asignada
        \pre cierto
        \post crea un reloj con el dia y la hora con los valores del parámetro
    */
    Reloj(string datetime,string hora);

    /* Destructora per defecte */

    /* Modificadores */

    /** @brief Modifica el dia del reloj
        \pre el reloj tiene dia
        \post el dia queda modificado
    */
    bool modificar_fecha(string fecha);

        /** @brief Modifica la hora del reloj
        \pre el reloj tiene hora
        \post la hora queda modificada
    */
    bool modificar_hora(string hora);

    //Consultores


    /** @brief consulta si el roloj actual es menor que el reloj introducido
        \pre el reloj tiene hora y dia
        \post falso si la fecha por parametro es mayor, cierto si la fecha por parametro es menor
    */
    bool es_menor(const Reloj &r);

    /** @brief Consulta si una dia es menor al dia del reloj interno
        \pre el reloj tiene dia
        \post falso si el dia por parametro es mayor, cierto si el dia por parametro es menor
    */
    bool fecha_menor(string fecha);

    /** @brief Consulta si una hora es menor a la hora del reloj interno
        \pre el reloj tiene hora
        \post falso si la hora por parametro es mayor, cierto si la hora por parametro es menor
    */
    bool hora_menor(string hora);

    /** @brief Consulta el dia del reloj
       \pre el reloj tiene dia
       \post devuelve el dia del reloj
    */
    string consultar_fecha();

    /** @brief Consulta la hora del reloj
       \pre el reloj tiene hora
       \post devuelve la hora del reloj
    */
    string consultar_hora();


    bool operator<( const Reloj& other) const {
        if(this->fecha < other.fecha){
            return true;
        } else if (this->fecha > other.fecha){
            return false;
        } else {
            return this->hora < other.hora;
        }
    }

    bool operator==(const Reloj &other) const
    {
        return this->fecha == other.fecha and this->hora == other.hora;
    }



};

#endif // RELOJ_HH
