#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <set>
#define inf 1000000000
#define forr(a, n) for(int a = 0; a < n; a++)
#define forab(i, a, b) for(int i = a; i <= b; i++)

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct monos{
    int v, a, b;
    monos(int _v, int _a, int _b){
        v=_v; a=_a; b=_b;
    }
};

int start, target, MAX=45;//MAX=numero de nodos
int mf, f, matriz[250][250];//aplicaciones, computadores
vi p;
vvi grafo;
set<int> intervalos;
vector<monos> vmonos;
vector<ii> rango;

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
        while(cola.size()){
            int u = cola.front();  cola.pop();
            //printf("Estamos en el nodo %d\n", u);
            if(u == target) break;

            for(int j = 0; j < grafo[u].size(); j++){
                int v = grafo[u][j];
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

int main(){//   ###Sin terminar
//freopen("salida.txt", "w", stdout);
    start = 0, target = 15;
    int n, m, a, b, z, total, caso = 1;

    while(scanf("%d", &n), n){
        scanf("%d", &m);
        intervalos.clear();
        vmonos.clear();
        rango.clear();
        total = 0;
        memset(matriz, 0, sizeof(matriz));

        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &z, &a, &b);
            intervalos.insert(a);
            intervalos.insert(b);
            vmonos.push_back(monos(z, a, b));
        }

        set<int>::iterator it = intervalos.begin();
        int last = *it, current;
        it++;
        for(; it != intervalos.end(); it++){
            current = *it;
            rango.push_back(ii(last, current));
            //printf("intervalo-nodo %d es (%d, %d)\n", rango.size() + n, last, current);
            last = current;
        }

        grafo.assign(MAX, vi(0));//vmonos.size() + rango.size() + 5
        for(int i = 0; i < n; i++){
            monos k = vmonos[i];
            grafo[start].push_back(i+1);
            grafo[i+1].push_back(start);
            matriz[start][i+1] = k.v;
            total += k.v;
            //printf("conexion de %d a %d con peso %d\n", start, i+1, k.v);

            for(int j = 0; rango[j].second <= k.b && j < rango.size(); j++){
                if(rango[j].first >= k.a){
                    grafo[i+1].push_back(1 + n + j);
                    grafo[1 + n + j].push_back(i+1);
                    matriz[i+1][1 + n + j] = rango[j].second - rango[j].first;
                    //printf("conexion de %d a %d con peso %d\n", i+1, 1+n+j, rango[j].second - rango[j].first);
                }
            }
        }

        forr(i, rango.size()){
            grafo[1 + n + i].push_back(target);
            grafo[target].push_back(1 + n + i);
            matriz[1 + n + i][target] = m*(rango[i].second-rango[i].first);
            //printf("conexion de %d a %d con peso %d\n", 1+n+i, target, m*(rango[i].second-rango[i].first));
        }

        int w = EdmondsKarp();
        if(w != total){
            printf("Case %d: No\n", caso++);
            continue;
        }
        vector<vii> sol(n+1);
        forab(i, n+1, 11){
            forr(j, 11){
                if(matriz[i][j]){
                    //printf("rango %d es usado por el nodo %d, peso: %d ", i, j, matriz[i][j]);
                    //printf("val: (%d, %d)", rango[i].first, rango[j].second);
                    sol[j].push_back(rango[i-(n+1)]);
                }
            }
        }

        printf("Case %d: Yes", caso++);
        forab(i, 1, n){
            printf("\n%d (%d,%d)", sol[i].size(), sol[i][0].first, sol[i][0].second);
            for(int j = 1; j < sol[i].size(); j++) printf(" (%d,%d)", sol[i][j].first, sol[i][j].second);
        }
        printf("\n");
    }

    return 0;
}


