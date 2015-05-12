#include "reloj.hh"

Reloj::Reloj()
{
    fecha = dar_vuelta("20.04.15");
    hora = "00:00";
}

Reloj::Reloj(string fecha, string hora)
{
    this->fecha = dar_vuelta(fecha);
    this->hora = hora;
}


string Reloj::dar_vuelta(string fecha) const
{
    string aux = fecha;
    aux[0] = fecha[6];
    aux[1] = fecha[7];
    aux[6] = fecha[0];
    aux[7] = fecha[1];

    return aux;
}

bool Reloj::modificar_fecha(string fecha)
{
    this->fecha = dar_vuelta(fecha);
}

bool Reloj::modificar_hora(string hora)
{
    this->hora = hora;
}


string Reloj::consultar_fecha() const
{
  return dar_vuelta(fecha);
}

string Reloj::consultar_hora() const
{
  return hora;
}

bool Reloj::fecha_menor(string fecha)
{
    return this->fecha > dar_vuelta(fecha);
}

bool Reloj::hora_menor(string hora)
{
    return this->hora > hora;
}

void Reloj::imprimir_Reloj() const{
    cout << this->consultar_fecha() << " " << this->consultar_hora() << endl;
}
