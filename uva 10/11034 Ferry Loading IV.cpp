#include <bits/stdc++.h>

using namespace std;
typedef pair<int, bool> ib;

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos, l, m;
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d %d", &l, &m);
        l *= 100;
        char cad[10];
        int aux;
        bool izq = true;
        int index = 0, can = 0, con = 0, cargabarco;
        queue<int> colai, colad;

        for(int j = 0; j < m; j++){
            scanf("%d %s", &aux, &cad);
            if(cad[0] == 'l') colai.push(aux);
            else colad.push(aux);
        }

        while(colai.size() || colad.size()){
            if(izq){
                int acum = 0;
                while(colai.size()){
                    if(acum + colai.front() > l) break;
                    acum += colai.front();
                    colai.pop();
                }
            } else {
                int acum = 0;
                while(colad.size()){
                    if(acum + colad.front() > l) break;
                    acum += colad.front();
                    colad.pop();
                }
            }

            izq = !izq;
            con++;
        }

        printf("%d\n", con);
    }

    return 0;
}


