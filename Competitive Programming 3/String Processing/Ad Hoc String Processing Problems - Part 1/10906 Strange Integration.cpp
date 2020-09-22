#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
string var[60], op1[60], opb[60], op2[60];
map<string, string> mapa;
map<string, int> idx;

string solve(string var){
    int i = idx[var];
    string a = op1[i], op = opb[i], b = op2[i];

    string res = "";
    bool n1 = isdigit(a[0]), n2 = isdigit(b[0]), p1 = false, p2 = false;

    if(n1){
        p2 = !n2;
    }else{
        if(!n2){
            p2 = true;
            if(op[0] == '*') p1 = true;
        } else if(op[0] == '*'){
            p1 = true;
        }
    }

    //omitir parentesis si es posible
    if(op[0] == '+' && p2){
        if(!n2){
            int ib = idx[b];
            p2 = (opb[ib][0] == '+');
        }
    }else if(op[0] == '*' && !n1 && n2 && p1){
        int ia = idx[a];
        p1 = (opb[ia][0] == '+');
    }else if(op[0] == '*' && !n1 && !n2 && p1){
        int ia = idx[a];
        p1 = (opb[ia][0] == '+');
    }

    if(n1){
        if(p1) res = res + "(" + a + ")";
        else res = res + a;
    }else{
        string ra;
        if(mapa.find(a)!=mapa.end()) ra = mapa[a];
        else ra = solve(a);

        if(p1) res = res + "(" + ra + ")";
        else res = res + ra;
    }
    if(n2){
        if(p2) res = res + op + "(" + b + ")";
        else res = res + op + b;
    }else{
        string rb;
        if(mapa.find(b)!=mapa.end()) rb = mapa[b];
        else rb = solve(b);

        if(p2) res = res + op + "(" + rb + ")";
        else res = res + op + rb;
    }
    mapa[var] = res;
    return res;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int t, n, caso = 1;
    string cad;
    cin >> t;

    while(t--){
        cin >> n;
        mapa.clear();
        idx.clear();

        string str, v, igual;
        getchar();
        forr(i, n){
            getline(cin, str);
            stringstream ss(str);
            ss>>var[i];  ss>>igual;
            ss>>op1[i];  ss>>opb[i];  ss>>op2[i];
            idx[var[i]] = i;
        }

        string res = solve(var[n-1]);
        cout << "Expression #" << caso++ << ": " << res << '\n';
    }
    return 0;
}


