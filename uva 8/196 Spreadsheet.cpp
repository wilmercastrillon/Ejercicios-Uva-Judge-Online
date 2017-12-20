#include <bits/stdc++.h>

using namespace std;

int casos, fil, col;
string hojaIni[1000][19000];
bool solve[1000][19000];
map<string, int> mapa;

void llenarMapa(){
    int con = 0;
    for(int i = 0; i < 26; i++){
        string h = "";
        h.push_back(i + 'A');
        mapa[h] = con++;
    }
    for(int j = 0; j < 26; j++)
        for(int i = 0; i < 26; i++){
            string h = "";
            h.push_back(j + 'A');
            h.push_back(i + 'A');
            mapa[h] = con++;
        }
    for(int k = 0; k < 26; k++)
        for(int j = 0; j < 26; j++)
            for(int i = 0; i < 26; i++){
                string h = "";
                h.push_back(k + 'A');
                h.push_back(j + 'A');
                h.push_back(i + 'A');
                mapa[h] = con++;
            }
}

void posicion(int &f, int &c, string h){
    int i, aux;
    for(i = 0; i < h.length(); i++)
        if(!(h[i] >= 'A' && h[i] <= 'Z')) break;

    c = mapa[h.substr(0, i)];
    f = atoi(h.substr(i).c_str());
    f--;
}

int llenar(int fi, int co){
    if(solve[fi][co]) return atoi(hojaIni[fi][co].c_str());
    string aux = hojaIni[fi][co];
    //cout << "se va a resolver " << aux << endl;
    int pos = 0, acum = 0, q, w;
    if(hojaIni[fi][co][0] == '=') pos = 1;

    for(int i = 1; i < aux.length(); i++){
        if(aux[i] == '+'){
            posicion(q, w, aux.substr(pos, i - pos));
            //cout << "se intenta casilla " << aux.substr(pos, i - pos) << " en pos " << q << " , " << w << endl;
            int x = llenar(q, w);
            //cout <<"resultado " << x << endl;
            acum += x;
            pos = i + 1;
        }
    }
    //cout << "se intenta casilla " << aux.substr(pos) << endl;
    posicion(q, w, aux.substr(pos));
    acum += llenar(q, w);
    hojaIni[fi][co] = to_string(acum);
    solve[fi][co] = true;
    //cout << "resultado final " <<  hojaIni[fi][co] << endl;
    return acum;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> casos;
    llenarMapa();

    while(casos--){
        memset(solve, false, sizeof(solve));
        cin >> col >> fil;
        for(int i = 0; i < fil; i++)
            for(int j = 0; j < col; j++){
                cin >> hojaIni[i][j];
                int q, w;
                posicion(q, w, hojaIni[i][j]);
                if(hojaIni[i][j][0] != '='){
                    solve[i][j] = true;
                }
            }
        for(int i = 0; i < fil; i++){
            for(int j = 0; j < col - 1; j++){
                cout << llenar(i, j) << " ";
            }
            cout << llenar(i, col - 1) << endl;
        }
    }

    return 0;
}
