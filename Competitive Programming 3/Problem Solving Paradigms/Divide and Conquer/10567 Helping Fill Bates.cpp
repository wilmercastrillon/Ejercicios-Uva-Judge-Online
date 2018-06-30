#include <bits/stdc++.h>//no terminado
#define pb(x) push_back(x)

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

char cad[1000010];
vii letras[53];

int poschar(char c){
    if(c < 'a') return c - 'A';
    else return (c - 'a') + 26;
}

int main(){
    int q;

    while(scanf("%s", &cad) != EOF){

        for(int i = 0; i < 53; i++) letras[i].clear();
        int l = strlen(cad), ant = 0;

        for(int i = 1; i < l; i++){
            if(cad[i] != cad[i-1]){
                letras[poschar(cad[i-1])].pb(ii(ant, i - ant));
                //cout << "insertamos en " << poschar(cad[i-1]) << endl;
                ant = i;
            }
        }
        letras[poschar(cad[l-1])].pb(ii(ant, l - ant));

        char c = 'a';
        for(int i = 26; i < 52; i++){
            cout << c << ": ";
            for(int j = 0; j < letras[i].size(); j++){
                cout << "[" << letras[i][j].first << ", " << letras[i][j].second << "]\n";
            }
            c++;
            cout << "\n";
        }

        for(int i = 0; i < q; i++){

        }
    }
}


