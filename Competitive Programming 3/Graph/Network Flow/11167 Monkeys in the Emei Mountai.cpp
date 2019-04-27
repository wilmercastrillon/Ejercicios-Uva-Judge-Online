#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <set>
#include <algorithm>
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

int start, target, MAX=500;//MAX=numero de nodos
int mf, f, matriz[500][500], inicio[500][5];//aplicaciones, computadores
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

int main(){
    start = 0, target = 499;
    int n, m, a, b, z, total, caso = 1;

    while(scanf("%d", &n), n){
        scanf("%d", &m);
        intervalos.clear();
        vmonos.clear();
        rango.clear();
        total = 0;
        memset(matriz, 0, sizeof(matriz));

        for(int i = 1; i <= n; i++){
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
            inicio[rango.size()][0] = last;  inicio[rango.size()][1] = last;
            inicio[rango.size()][2] = last;  inicio[rango.size()][3] = last;
            inicio[rango.size()][4] = last;
            rango.push_back(ii(last, current));
            //printf("rango(%d, %d) -> inicia con %d\n", last, current, inicio[rango.size()][0]);
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
                    //printf("conexion de %d a %d con peso %d\n", i+1, 1+n+j, rango[j].second - rango[j].first);
                    grafo[i+1].push_back(1 + n + j);
                    grafo[1 + n + j].push_back(i+1);
                    matriz[i+1][1 + n + j] = rango[j].second - rango[j].first;
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
        int lim = rango.size() + n + 1, cant, idx;

        forab(i, n+1, lim){
            forr(j, lim){
                if(matriz[i][j]){
                    idx = i-(n+1);
                    //printf("rango (%d, %d) es usado por el nodo %d, peso: %d | inicia en %d\n", rango[idx].first, rango[idx].second,
                    //            j, matriz[i][j], inicio[idx][3]);
                    forr(k, m){
                        if(matriz[i][j] == 0) break;
                        cant = min(rango[idx].second-inicio[idx][k], matriz[i][j]);
                        //printf("\t min(%d - %d, %d) intentar usar (%d, %d) , cant %d\n", rango[idx].second, inicio[idx][k], matriz[i][j],
                        //       inicio[idx][k], inicio[idx][k] + cant, cant);
                        if(cant == 0) continue;

                        ii add(inicio[idx][k], inicio[idx][k] + cant);
                        ii actual = rango[idx];
                        inicio[idx][k] += cant;
                        matriz[i][j] -= cant;
                        //printf("\tagregamos (%d %d) con peso %d\n", inicio[j][k], inicio[j][k] + cant, cant);
                        sol[j].push_back(add);
                    }
                }
            }
        }

        printf("Case %d: Yes", caso++);
        forr(i, sol.size()){
            if(!sol[i].size()) continue;
            sort(sol[i].begin(), sol[i].end());
            //printf("ordena con tam %d\n", sol[i].size());
            vector<ii> imp;
            ii ant, act;
            //printf("insertamos (%d, %d)\n", sol[i][0].first, sol[i][0].second);
            imp.push_back(ii(sol[i][0].first, sol[i][0].second));

            for(int j = 1; j < sol[i].size(); j++){
                ant = imp.back();
                act = sol[i][j];
                //printf("insertamos (%d, %d)\n", act.first, act.second);
                if(ant.second == act.first){
                    imp.pop_back();
                    imp.push_back(ii(ant.first, act.second));
                }else imp.push_back(act);
            }

            printf("\n%d (%d,%d)", imp.size(), imp[0].first, imp[0].second);
            for(int j = 1; j < imp.size(); j++) printf(" (%d,%d)", imp[j].first, imp[j].second);
        }
        printf("\n");
    }

    return 0;
}


