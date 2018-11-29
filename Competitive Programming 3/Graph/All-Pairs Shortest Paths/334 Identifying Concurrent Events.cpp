#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int matriz[210][210];
map<string, int> mapa;
map<int, string> inv;

void FloydWarshall(int nodos){
    int aux;
    for(int i = 0; i < nodos; i++) matriz[i][i] = 0;

    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = matriz[i][k] + matriz[k][j];
                if(matriz[i][j] > aux){
                    matriz[i][j] = aux;
                }
            }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int p, e, caso = 1;
    char cad[10], cad2[10];
    string s, ant;

    while(scanf("%d", &p), p){
        int n = 0, aux;
        mapa.clear();  inv.clear();
        memset(matriz, 5436, sizeof(matriz));

        for(int j = 0; j < p; j++){
            scanf("%d", &e);

            if(e == 0) continue;
            scanf("%s", &cad);
            ant = (string) cad;
            if(!mapa[ant]){
                mapa[ant] = ++n;
                inv[n] = ant;
            }

            for(int i = 1; i < e; i++){
                scanf("%s", &cad);
                s = (string) cad;
                if(!mapa[s]){
                    mapa[s] = ++n;
                    inv[n] = s;
                }
                matriz[mapa[ant]][mapa[s]] = 1;
                ant = s;
            }
        }

        scanf("%d", &e);
        for(int i = 0; i < e; i++){
            scanf("%s %s", &cad, &cad2);
            matriz[mapa[(string)cad]][mapa[(string)cad2]] = 1;
        }

        FloydWarshall(n + 1);

        ii p1, p2;
        int con = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(matriz[i][j] > 100000000 && matriz[j][i] > 100000000){
                    con++;
                    if(con == 1){
                        p1.first = i;  p1.second = j;
                    }else if(con == 2){
                        p2.first = i;  p2.second = j;
                    }
                }
            }
        }

        if(con > 1){
            printf("Case %d, %d concurrent events:\n(%s,%s) (%s,%s) \n", caso++, con,
                inv[p1.first].c_str(),inv[p1.second].c_str(),inv[p2.first].c_str(),inv[p2.second].c_str());
        }else if(con == 1) printf("Case %d, %d concurrent events:\n(%s,%s) \n",
                            caso++, con, inv[p1.first].c_str(),inv[p1.second].c_str());
        else printf("Case %d, no concurrent events.\n",caso++, con);
    }

    return 0;
}


