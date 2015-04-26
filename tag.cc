#include "tag.hh"
#include <algorithm>
Tag::Tag(){}

Tag::Tag(const string &titulo, const vector<Reloj> &list){
    this->titulo = titulo;
    this->lista = list;
}

string Tag::get_titulo(){
    return titulo;
}

vector<Reloj> Tag::get_list(){
    return lista;
}

void Tag::set_list(vector<Reloj> r){
    this->lista = r;
}

void Tag::anadir_Reloj(Reloj r){
    lista.push_back(r);
    sort(lista.begin(),lista.end(),es_mayor_igual);
}

void Tag::eliminar_Reloj(Reloj r){
    //TODO temporalmente busqueda linial
    int pos = this->posicio(r,this->lista,0,lista.size());
    if(pos != -1){
        lista.erase(&lista[pos]);
        //lista.erase(lista.begin() + pos);
    }
}

// Pre: (0 <= esq) and (dre < v.size()) and (v esta ordenat creixentment)
// Post: retorna i tal que, o be esq<=i<=dre i v[i]==x, o be i==-1 i x no es a v[esq..dre]
int Tag::posicio(Reloj x, const vector<Reloj>& v, int esq, int dre) {
    if (esq > dre) return -1;
    int pos = (esq + dre)/2; // posicio central de v[esq..dre]
    if (x < v[pos]) return posicio(x, v, esq, pos - 1);
    if (x > v[pos]) return posicio(x, v, pos + 1, dre);
    return pos;
}
