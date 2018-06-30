#include<bits/stdc++.h>
#define c(x) for(int k = 0; k < x; k++)

using namespace std;

map<string, int> mapa;
vector<string> n[4];

void llenar(){
    int con = 0;
    string h1 = "CDSH", h2 = "23456789TJQKA";
    for(int i = 0; i < 4; i++)
        c(13){
            char h[] = {h1[i], h2[k], '\0'};
            string t = (string) h;
            mapa[h] = con++;
        }
}

void clear_all(){
    c(4)
        n[k].clear();
}

bool cmp(string a, string b){
    return mapa[a] < mapa[b];
}

int main(){
    llenar();
    char dir, aux1, aux2;
    int index_ini;
    string c1, c2;

    while(cin >> dir && dir != '#'){
        clear_all();
        switch(dir){
            case 'N':
                index_ini = 1;
                break;

            case 'E':
                index_ini = 2;
                break;

            case 'S':
                index_ini = 3;
                break;

            case 'W':
                index_ini = 0;
                break;

        }

        cin >> c1;
        cin >> c2;
        c1 += c2;
        int pos = 0;
        for(int j = 0; j < 13; j++){
            c(4){
                n[index_ini % 4].push_back(c1.substr(pos ,2));
                index_ini++;
                pos += 2;
            }
        }

        c(4)
            sort(n[k].begin(), n[k].end(), cmp);

            printf("S: ");
            for(int j = 0; j < 12; j++){
                cout << n[2][j] << " ";
            }
            cout << n[2][12] << '\n';
            printf("W: ");
            for(int j = 0; j < 12; j++){
                cout << n[3][j] << " ";
            }
            cout << n[3][12] << '\n';
            printf("N: ");
            for(int j = 0; j < 12; j++){
                cout << n[0][j] << " ";
            }
            cout << n[0][12] << '\n';
            printf("E: ");
            for(int j = 0; j < 12; j++){
                cout << n[1][j] << " ";
            }
            cout << n[1][12] << '\n';
    }

    return 0;
}
