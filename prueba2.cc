#include <iostream>
#include <string>
using namespace std;

bool calcular(string s, int &ini, int end){
    if(s[ini]=='('){
        ++ini;
        cout << "empezando expr... "<< endl;
        return calcular(s,ini,end); // cada vez que empieza una expr
    } else {
        int i = ini;
       // cout << "ini: " << ini << endl;
        bool found = false;
        while(i < end and not found){ // mientras que hayan caracteres y no se encutre ni '.', ','
            if(s[i] == '.' or s[i] == ',' ){
                if(s[i] == '.'){
                    cout << "AND" << endl;
                } else if(s[i] == ',') {
                    cout << "OR" << endl;
                }
                found = true;
            }else {
                ++i;
            }
        }
        //i posicion donde esta '.' o ','


        int lon = i - ini; // longitud para el substring
        cout << "longitud: "<< lon << endl;
        string tag1 = s.substr(ini,lon); // tag encotnrado
        //tag1 con el primer tag
       // if(tag1[lon] == ')' ) tag1 = tag1.substr(0,lon-1); // si
        cout << "tag1 :" << tag1 << endl;
        bool encontrado = true; // aqui va la busqueda del tag
        bool encontrado2 = true;
        string tag2;
        ini = i;
        if(s[ini+1] == '(' ){
            ++ini;
            encontrado2 = calcular(s,ini,end); // cada vez que empieza una expr
        } else {
            cout << "entrando en else != '(' " << endl;
            int j = i;
            while(s[j]!= ')'){
                ++j;
            }
            tag2 = s.substr(ini+1,j-ini-1);
            cout << "tag2 :"<< tag2 << endl;
            encontrado2 = true; // AQUI va la busqueda del tag
        }

        if(s[i] == '.'){
            cout << "entrando: AND"<< endl;
            return encontrado and encontrado2;
        } else {
            cout << "entrando: OR"<< endl;
            return encontrado or encontrado2;
        }

        ini = i+1;
        if(ini >= end) return encontrado;

    }
}
int main()
{
  string s = "((#lleure,#feina).#art)";
  int ini = 1;
  bool cumple = calcular(s,ini,s.size()-1);

}
