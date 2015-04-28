#include "agenda.hh"
#include "comanda0.hh"
#include "reloj.hh"
#include "utils.PRO2"

int main()
{
    Comanda c;
    Agenda a;
    bool be = false;
    list<Tarea> v;
    while(c.llegir(be)){
        if(not be){
            if(c.es_consulta()){
                if(c.nombre_dates()==0 and not c.te_expressio() and not c.te_titol() and not c.te_hora()){ // caso '?'
                    Reloj r("00/00/00");
                    r.set_hora("00:00");
                    Reloj r2("31/12/99");
                    r.set_hora("23:59");
                    v = a.buscar_tarea_intervalo(r,r2,"*");
                } else {
                    if(c.nombre_dates() > 0 ){
                        Reloj r(c.data(1));
                        Reloj r2(c.data(1));
                        if(c.nombre_dates() == 2) r2.set_fecha(c.data(2));
                        if(c.te_hora()){
                            r.set_hora(c.hora());
                            r2.set_hora(c.hora());
                        } else {
                            r.set_hora("00:00");
                            r2.set_hora("23:59");
                        }

                        v = a.buscar_tarea_intervalo(r,r2,'*');
                    }
                }
                 a.imprimir_menu(v);
            } else if (c.es_modificacio()){

            } else if (c.es_insercio()){

            } else if (c.es_rellotge()){

            } else if (c.es_passat()){

            } else { //esborrat

            }



        }
    }





  int N = readint();
  int M = readint();
  Ranking R(M,N);
  Sistema S(M);
  S.leer_sistema(N);
  int op;
  op = readint();
  bool fin_anticipado = false;
  while (op > -6 and op < 0 and not fin_anticipado) {
    if (op == -1 ) {
      int ncrecen = readint();
      for (int i=0; i<ncrecen; ++i) S.crecimiento(readint());
    }
    else if (op == -2) {
      int nmueren = readint();
      for (int i=0; i<nmueren; ++i) S.muerte(readint(),R);
    }
    else if (op == -3) {
      cout << endl << "EMPAREJAMIENTO" << endl;
      int p1 = readint();
      int p2 = readint();
      int p3;
      S.reproduccion(p1,p2,p3,R);
      if (p3!=0)
    cout << p1 <<" y " << p2 << " han producido " << p3 << endl;
      else
    cout << p1 <<" y " << p2 << " no han producido nada"<< endl;
    }
    else if (op == -4) {
      cout << endl << "RANKING" << endl;
      R.escribir_ranking();
    }
    else if (op == -5) {
      cout  << endl << "ORGANISMOS" << endl;
      int nconsultables = readint();
      for (int i=0; i<nconsultables; ++i) S.escribir_un_organismo(readint());
    }
    fin_anticipado = S.vivos()==0 or S.tamano()==M;
    if (not fin_anticipado) op = readint();
  }
  cout <<  endl << "FIN" << endl;
  cout <<  endl;
  cout  << endl << "ORGANISMOS" << endl;
  S.escribir_organismos();
  cout << endl << "RANKING" << endl;
  R.escribir_ranking();
}

