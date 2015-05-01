#include "agenda.hh"
#include "comanda0.hh"
#include "reloj.hh"
#include "tarea.hh"
#include "tags.hh"
#include "utils.PRO2"

int main()
{
    Comanda c;
    Agenda a;
    bool be = false;
    map<Reloj,Tarea> v;
    while(c.llegir(be)){
        bool todo_OK = true;
        if(not be){
            if(c.es_consulta()){
                Reloj r("00/00/00");
                r.set_hora("00:00");
                Reloj r2("31/12/99");
                r.set_hora("23:59");
                string expr = '*';
                if(c.nombre_dates()!=0 or c.te_expressio() or c.te_hora() or c.nombre_etiquetes() != 0){
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
                    }
                    if(c.te_expressio()) expr = c.expressio();
                    else if (c.nombre_etiquetes() == 1){ //TODO comprobar si se puede poner mas etiquetas
                        expr = c.etiqueta(1);
                    }
                }
                v = a.buscar_tarea_intervalo(r,r2,expr);
                a.imprimir_menu(v);
            } else if (c.es_modificacio()){
                // Pre: se ha realizado una consulta anteriormente
                int tasca = c.tasca();

                map<Reloj,Tarea>::iterator it(v.begin());
                advance(i1,tasca); // selecionamos la tarea
                Reloj r1 = it->first;
                Reloj r2 = it->first;
                Tarea t = it->second;
                if(c.te_titol()){
                    t.set_titulo(c.titol());
                }
                if(c.te_hora()){
                    r2.set_hora(c.hora());
                }
                if(c.nombre_dates() != 0){
                    r2.set_fecha(c.data(1));
                }
                todo_OK = a.modificar_tarea(r1,r2,t);


            } else if (c.es_insercio()){
                Reloj r;
                if(c.nombre_dates() == 1){
                    r.set_fecha(c.data(1));
                } else {
                    r = a.get_RelojActual();
                }
                r.set_hora(c.hora());
                Tags tags;
                if(c.nombre_etiquetes() != 0){
                    for(int i = 1; i <= c.nombre_etiquetes() ; ++i){
                        tags.add_tag(c.etiqueta(i));
                    }
                }

                Tarea tarea(c.titol(),tags);
                todo_OK = a.anadir_tarea(r,tarea);


            } else if (c.es_rellotge()){
                Reloj r;
                if(not c.te_hora() and not c.nombre_dates() != 0){
                    if(c.te_hora()) r.set_hora(c.hora());
                    if(c.nombre_dates() != 0) r.set_fecha(c.data(1));
                    todo_OK = a.set_Reloj(r);
                } else { // caso consulta
                    r = a.get_RelojActual();
                    cout << r.get_fecha() << "   " << r.get_hora() << endl;
                }
            } else if (c.es_passat()){
                Reloj reloj1("00.00.00","00:00");
                Reloj reloj2 = a.get_RelojActual();
                string expr = '*';
                v = a.buscar_tarea_intervalo(reloj1,reloj2,expr);
                a.imprimir_menu(v);
            } else { //esborrat

            }

        if(not todo_OK) cout << "No s'ha realitzat" << endl;

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

