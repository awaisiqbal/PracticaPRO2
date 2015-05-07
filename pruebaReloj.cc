#include <iostream>
#include <string>
#include "reloj.hh"
using namespace std;


int main()
{
    Reloj r1("07.05.15","16:28");
    Reloj r2("07.05.15","16:26");
    Reloj r3("09.05.89","23:28");
    Reloj r4("10.05.16","20:28");
    Reloj r5("16.05.15","01:28");

    if(r1<r2){
        cout << "r1 < r2" << endl;
        cout << "R1: \t" ;
        r1.imprimir_Reloj();
        cout << "R2: \t" ;
        r2.imprimir_Reloj();
        cout << endl << endl << endl;
    }


    if(r2<r3){
        cout << "r2 < r3" << endl;
        cout << "R2: \t" ;
        r2.imprimir_Reloj();
        cout << "R3: \t" ;
        r3.imprimir_Reloj();
        cout << endl << endl << endl;
    }

    if(r3<r4){
        cout << "r3 < r4" << endl;
        cout << "R3: \t" ;
        r3.imprimir_Reloj();
        cout << "R4: \t" ;
        r4.imprimir_Reloj();
        cout << endl << endl << endl;
    }

    if(r4<r5){
        cout << "r4 < r5" << endl;
        cout << "R4: \t" ;
        r4.imprimir_Reloj();
        cout << "R5: \t" ;
        r5.imprimir_Reloj();
        cout << endl << endl << endl;
    }

}
