#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef long long int lli;
typedef pair<int, int> ii;//peso - destino
typedef vector<ii> vii;
typedef vector<vii> vvii;

priority_queue<ii> cola;
vector<bool> vis;

void vecinos(vvii &lista, int nodo){
    vis[nodo] = true;
    for(int i = 0; i < lista[nodo].size(); i++){
        ii par = lista[nodo][i];//peso - destino
        if(!vis[par.second])
            cola.push(ii(-par.first, -par.second));
    }
}

lli prim(vvii &lista, int n){
    vis.assign(n + 1, false);
    vecinos(lista, 1);
    lli acum = 0; ii par;

    while(cola.size()){
        par = cola.top(); cola.pop();
        if(vis[-par.second]) continue;
        acum += (lli) -par.first;
        vecinos(lista, -par.second);
    }
    return acum;
}

int n, m;

int main(){
    int x, y, z;

    while(scanf("%d %d", &n, &m), n, m){
        vvii grafo(n);
        lli total = 0;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo[x].push_back(ii(z, y));
            grafo[y].push_back(ii(z, x));
            total += (lli) z;
        }

        printf("%lld\n", total - prim(grafo, n));
    }

    return 0;
}


