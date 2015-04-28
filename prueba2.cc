#include <iostream>
#include <string>
using namespace std;

bool calcular(string s, int ini, int end){
    if(s[ini]=='('){
        return calcular(s,ini+1,end); // cada vez que empieza una expr
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
        int lon = i - ini; // longitud para el substring
        cout << "longitud: "<< lon << endl;
        string tag1 = s.substr(ini,lon); // tag encotnrado
        cout << "tag1 :" << tag1 << endl;
        bool encontrado = true; // aqui va la busqueda del tag
        ini = i+1;
        if(ini >= end) return encontrado;
        return calcular(s,ini,end);

    }
}
int main()
{
  string s = "((#lleure,#feina).#art)";
  bool cumple = calcular(s,1,s.size()-1);

}
