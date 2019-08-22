#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
int bordes[400010];

void algoritmoBordes(string subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

int kmp(string cad, string subcad){
    int i = 0, j = 0, con = 0;
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        i++; j++;
        if(j == subcad.size()){
            //printf("%s esta en el indice %d de la cadena: %s\n", subcad.c_str(), i - j, cad.c_str());
            con++;
            j = bordes[j];
        }
    }
    return con;
}

string simplificar(string &s){
    string res = "";
    int ini = 0, fin = s.size();

    forab(i, ini, fin){
        if(s[i] == '(') res.push_back('(');
        else if(s[i] == ')') res.push_back(')');
        else if(isdigit(s[i])){
            res.push_back('x');
            while((i+1)<s.size() && isdigit(s[i+1])) i++;
        }else if(isalpha(s[i])) res.push_back('x');
        else res.push_back('o');
    }
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a, b, cad, subcad;

    while(cin >> a){
        cin >> b;

        subcad = simplificar(a);
        cad = simplificar(b);
        //printf("subcad: %s | cad: %s\n", subcad.c_str(), cad.c_str());

        algoritmoBordes(subcad);
        cout << kmp(cad, subcad) << '\n';

        //algoritmoBordes(a);
        //cout << kmp(b, a) << endl;
    }
    return 0;
}


