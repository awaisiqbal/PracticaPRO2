#include <iostream>
#include <string>
using namespace std;
bool busqueda(string s){
    cout << "\t\tbuscando... " << s << endl;
    return true;
}


bool calcular(string s, int &ini, int end){
    bool tag1 = false;
    char condicion ;
    if(s[ini] == '('){
        cout << "(" << " ";
        //cout << "entrando if1  " << endl;
        ++ini;
        tag1 = calcular(s,ini,end);
        ++ini;
        condicion = s[ini];
        cout << ")" << endl;
    } else {
        cout << "entrando else1  " << endl;
        int i = ini;
        while(s[i]!= '.' and s[i] != ',' ) {
            ++i;
        }
        int loncount = i - ini;
        tag1 = busqueda(s.substr(ini,loncount));
        ini = i;

        condicion = s[ini];
        ++ini;
    }

    if(condicion == '.'){
         cout << "AND" << endl;
    } else if(condicion == ',') {
        cout << "OR" << endl;
    }

    bool tag2 = false;
    if(s[ini] == '('){
        cout << "(" << " ";
        //cout << "entrando if2  " << endl;
        ++ini;
        tag2 = calcular(s,ini,end);
        cout << ")" << endl;
    } else {
        cout << "entrando else2  " << endl;
        int i = ini;
        while(s[i]!=')') {
            ++i;
        }
        int loncount = i - ini;
        tag1 = busqueda(s.substr(ini,loncount));
        ini = i;
    }
    if(condicion == '.'){
        // cout << "AND" << endl;
        return tag1 and tag2 ;
    } else if(condicion == ',') {
       // cout << "OR" << endl;
        return tag1 or tag2 ;
    }





}
int main()
{
  string s = "((#lleure,#feina).#art)";
  int ini = 1;
  bool cumple = calcular(s,ini,s.size()-1);

}


/*
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

        ini = i+1;
        if(s[i] == '.'){
            return busqueda(tag1) and busqueda(tag2) ;
            cout << "AND" << endl;
        } else if(s[i] == ',') {
            return busqueda(tag1) or busqueda(tag2) ;
            cout << "OR" << endl;
        }
        if(ini >= end) return encontrado;

    }*/
