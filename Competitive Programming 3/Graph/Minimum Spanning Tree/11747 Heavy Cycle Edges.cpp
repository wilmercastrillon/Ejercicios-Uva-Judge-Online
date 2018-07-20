#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;//peso - destino
typedef vector<ii> vii;
typedef vector<vii> vvii;

priority_queue<ii> cola;
vector<bool> vis;
vector<int> res;
int canVis;

void vecinos(vvii &lista, int nodo){
    vis[nodo] = true;
    canVis++;
    for(int i = 0; i < lista[nodo].size(); i++){
        ii par = lista[nodo][i];//peso - destino
        if(!vis[par.second])
            cola.push(ii(-par.first, -par.second));
    }
}

int prim(vvii &lista, int n){
    canVis = 0; res.clear();
    vis.assign(n + 1, false);
    int acum = 0; ii par;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vecinos(lista, i);
            while(cola.size()){
                par = cola.top(); cola.pop();
                if(vis[-par.second]){
                    res.push_back(-par.first);
                    continue;
                }
                acum += -par.first;
                vecinos(lista, -par.second);
            }
        }
    }
    return acum;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, z;

    while(scanf("%d %d", &n, &m), n || m){
        vvii lista(n+1);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            lista[x].push_back(ii(z, y));
            lista[y].push_back(ii(z, x));
        }

        prim(lista, n);
        sort(res.begin(), res.end());
        if(res.size()){
            printf("%d", res[0]);
            for(int i = 1; i < res.size(); i++)
                printf(" %d", res[i]);
            printf("\n");
        }else
            printf("forest\n");
    }

    return 0;
}


