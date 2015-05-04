#include "reloj.hh"

Reloj::Reloj()
{
    fecha = "20.04.15";
    hora = "00:00";
}

Reloj::Reloj(string fechaHora)
{
    if (fechaHora[2] == '.') {
        fecha = fechaHora;
        hora = "00:00";
    }
    else {
        fecha = "20.04.15";
        hora = fechaHora;
    }
}

Reloj::Reloj(string fecha, string hora)
{
    this->fecha = fecha;
    this->hora = hora;
}


string Reloj::dar_vuelta(string fecha)
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
    if (fecha_menor(fecha)) return false;
    else this->fecha = fecha;
    return true;
}

bool Reloj::modificar_hora(string hora)
{
    if (hora_menor(hora)) return false;
    else this->hora = hora;
    return true;
}

bool Reloj::es_menor(const Reloj &r)
{
    string hora = r.hora,fecha = r.fecha;
    string aux, aux2;
    aux = dar_vuelta(this->fecha);
    aux2 = dar_vuelta(fecha);
    if (aux2 < aux) return true;
    else if (aux2==aux and hora < this->hora) return true;
    else return false;
}

string Reloj::consultar_fecha()
{
  return fecha;
}

string Reloj::consultar_hora()
{
  return hora;
}

bool Reloj::fecha_menor(string fecha)
{
    string aux, aux2;
    aux = dar_vuelta(this->fecha);
    aux2 = dar_vuelta(fecha);

    if (aux2 < aux) return true;
    else return false;
}

bool Reloj::hora_menor(string hora)
{
    if (hora < this->hora) return true;
    else return false;
}
