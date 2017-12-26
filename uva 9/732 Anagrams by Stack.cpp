#include <bits/stdc++.h>

using namespace std;
typedef vector<char> vc;

string _inicial, _final;

void backT(string ini, string ult, string aux, string ruta){
    //cout << "ini: " << ini << " ult: " << ult << " pila: " << aux << " ruta: " << ruta << endl;
    if(!ini.size() && ult == _final && !aux.size()){
        printf("%s\n", ruta.substr(1).c_str());
        return;
    }

    if(ult.size())
        if(ult != _final.substr(0, ult.size())) return;

    if(ini.size()){
        char q = ini[0];
        string c = aux;
        c.push_back(q);
        backT(ini.substr(1), ult, c, ruta + " i");
    }

    if(aux.size()){
        string b = ult;
        b.push_back(aux[aux.size() - 1]);
        backT(ini, b, aux.substr(0, aux.size() - 1), ruta + " o");
    }
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    while(getline(cin, _inicial)){
        if(!getline(cin, _final)) break;
        printf("[\n");
        if(_inicial.size() == _final.size())
            backT(_inicial, "", "", "");
        printf("]\n");
    }

    return 0;
}


