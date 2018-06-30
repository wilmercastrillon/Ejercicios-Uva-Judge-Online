#include <bits/stdc++.h>

using namespace std;

int k, con;
bool solve;
string snap1[6], snap2[6], iguales[6];

bool buscar(string cad[], int col, char c){
    for(int i = 0; i < 6; i++)
        if(cad[i][col] == c) return true;

    return false;
}

void igual(){
    for(int j = 0; j < 5; j++){
        iguales[j] = "";
        for(int i = 0; i < 26; i++)
            if(buscar(snap1, j, i + 'A') && buscar(snap2, j, i + 'A'))
                iguales[j].push_back(i + 'A');
    }
}

void imp(int f, string cad){
    if(f == 5){
        con++;
        if(con == k){
            cout << cad << "\n";
            solve = true;
        }
        return;
    }

    for(int i = 0; i < iguales[f].size() && !solve; i++){
        string aux = cad;
        aux.push_back(iguales[f][i]);
        imp(f + 1, aux);
    }
}

int main(){
    cin.tie(NULL);
    int casos;
    cin >> casos;

    while(casos--){
        cin >> k;

        for(int i = 0; i < 6; i++) cin >> snap1[i];
        for(int j = 0; j < 6; j++) cin >> snap2[j];
        igual();
        con = 0;
        solve = false;

        string s = "";
        imp(0, s);
        if(!solve) cout << "NO\n";
    }

    return 0;
}


