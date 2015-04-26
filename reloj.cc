#include "reloj.hh"

Reloj::Reloj(){
    set_hora(00,00);
    set_fecha(20,04,15);
}

Reloj::Reloj(int hora, int min){
    set_hora(hora,min);
    set_fecha(20,04,15);
}

Reloj::Reloj(int dia, int mes, int ano){
    set_hora(00,00);
    set_fecha(dia,mes,ano);
}

Reloj::Reloj(int dia, int mes, int ano, int hora, int min){
    set_hora(hora,min);
    set_fecha(dia,mes,ano);
}

void Reloj::set_fecha(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

void Reloj::set_hora(int hora, int min){
    this->hora = hora;
    this->min = min;
}
/**
 * @brief es_mayor_igual
 * @param r
 * @return true cuando reloj es mayor o igual que el reloj que se pasa por parametro
 */
bool Reloj::es_mayor_igual(Reloj r){
    if(this->ano > r.ano){
        return true;
    } else if (this->ano == r.ano){
        if(this->mes > r.mes){
            return true;
        } else if (this->mes == r.mes){
            if(this->dia > r.dia){
                return true;
            } else if (this->dia == r.dia){
                if(this->hora > r.hora){
                    return true;
                } else if (this->hora == r.hora){
                    if(this->min >= r.min){
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
       return false;
    }
}

