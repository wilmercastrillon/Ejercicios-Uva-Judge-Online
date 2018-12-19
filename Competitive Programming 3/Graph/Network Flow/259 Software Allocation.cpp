#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <map>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int start, target, MAX=45;//MAX=numero de nodos
int mf, f, total = 0, matriz[45][45];//aplicaciones, computadores
vi p;
vvii grafo;
map<char, int> mapa;

void llenar(){
    int con = 10;
    for(char c='A'; c<='Z'; c++) mapa[c] = con++;
}

void augment(int v, int minEdge){
    if(v == start){ f = minEdge; return; }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, matriz[p[v]][v]));
        matriz[p[v]][v] -= f;  matriz[v][p[v]] += f;
    }
}

int EdmondsKarp(){
    mf = 0;
    while(true){
        f = 0;
        vector<bool> vis(MAX, false);  vis[start] = true;
        queue<int> cola;  cola.push(start);
        p.assign(MAX, -1);
        ii par;
        while(cola.size()){
            int u = cola.front();  cola.pop();
            if(u == target) break;

            for(int j = 0; j < grafo[u].size(); j++){
                par = grafo[u][j];
                int v = par.second;
                if(matriz[u][v] > 0 && !vis[v]){
                    vis[v] = true;
                    cola.push(v);  p[v] = u;
                }
            }
        }
        augment(target, inf);
        if(f == 0) break;
        mf += f;
    }
    return mf;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    llenar();
    int n, m, x, y, z, con = 1, l;
    string s1, s2;
    char cad1[100], cad2[100];
    bool sig;

    while(gets(cad1)){
        sig = false;
        memset(matriz, 0, sizeof(matriz));
        grafo.assign(MAX, vii(0));
        start = 40;  target = 41;  total = 0;

        do{
            //printf("ciclo para %s\n", cad1);
            l = strlen(cad1);
            if(l == 0){
                sig = true;
                break;
            }
            l--;
            x = mapa[cad1[0]];//app
            z = cad1[1] - '0';
            grafo[start].push_back(ii(z, x));
            grafo[x].push_back(ii(z, start));
            matriz[start][x] = z;
            total += z;

            for(int i = 3; i < l; i++){
                y = cad1[i] - '0';
                grafo[x].push_back(ii(1, y));
                grafo[y].push_back(ii(1, x));
                matriz[x][y]++;
                //printf("de %d a %d con capacidad %d\n", x, y, 1);
            }
        }while(gets(cad1));

        for(int i = 0; i < 10; i++){
            grafo[i].push_back(ii(1, target));
            grafo[target].push_back(ii(1, i));
            matriz[i][target] = 1;
        }

        int w = EdmondsKarp();
        if(total == w){
            for(int i = 0; i < 10; i++){
                bool used = false;
                for(int j = 10; j < 36 && !used; j++){
                    if(matriz[i][j]){
                        printf("%c", j + 'A' - 10);
                        used = true;
                    }
                }
                if(!used) printf("_");
            }
            printf("\n");
        }else printf("!\n");
        if(!sig) break;
    }

    return 0;
}


