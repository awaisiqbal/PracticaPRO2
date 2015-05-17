#include <iostream>
#include <string>
using namespace std;

/*	Pre:	Cert[Pre de consulta: conte una expressio correcte]
	Post:	i_search retorna el resultat de la busqueda per la dreta de la part vista i despres l'esquerra.
			si no hi ha cortcirquit.
*/
bool i_search(string s){
	if(s[0]=='#'){
		cout << "buscando... "<< s << endl;
		return true;
	}
	bool reg_expr = false;
	int par = 0;
	int i;
	for(i = s.length()-2; i > 2 and not reg_expr;--i){
		if(s[i]== ')') ++par;
		else if(s[i]== '(') --par;
		if((s[i]== '.' or s[i] == ',') and par == 0) reg_expr = true;
	}
	string s1, s2;
	char op = s[i+1];
	s1 = s.substr(1,i);
	s2 = s.substr(i+2,s.length()-i-3);
	if(op == '.') return (i_search(s2) and i_search(s1));
	else return (i_search(s2) or i_search(s1));
}

int main(){
	string s = "(((#recerca,#docencia).#art).#forum)";
	cout << s << endl;
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "((#tagA.#tagB).(#tagD.#tagE))";
	cout << s << endl;
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "#aloneTag";
	cout << s << endl;
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "(#t1.#t2)";
	cout << s << endl;
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;

	cout << endl << "----- NEXT -----" << endl << endl;
	s = "(#hhhhh.#ffff)";
	cout << s << endl;
	if(i_search(s)) cout << "SI!" << endl;
	else cout << "NO!" << endl;
}
