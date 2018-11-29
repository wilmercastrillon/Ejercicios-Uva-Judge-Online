#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
#define inf 1000000000
int matriz[10001][10001];
bool cam[10001][10001];

vi dijkstra(vvii &grafo, int nodo, int tam){
    vi dis(tam + 1, inf);
    priority_queue<ii> cola;
    cola.push(ii(-0, nodo));
    int peso, aux;
    ii par, par2;

    while(cola.size()){
        par = cola.top();
        cola.pop();
        peso = -par.first;
        nodo = par.second;

        if(dis[nodo] <= peso) continue;
        dis[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            par2 = grafo[nodo][i];
            aux = dis[nodo] + par2.first;
            if(dis[par2.second] > aux){
                cola.push(ii(-aux, par2.second));
            }
        }
    }

    return dis;
}

int main(){
    int t, n, m, x, y, z, ini, fin, p;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d %d %d", &n, &m, &ini, &fin, &p);
        memset(cam, 0, sizeof(cam));
        vvii grafo(n+1), inv(n+1);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo[x].push_back(ii(z, y));
            inv[y].push_back(ii(z, x));
            matriz[x][y] = z;
            cam[x][y] = true;
        }

        vi dist = dijkstra(grafo, ini, n+1);
        vi distInv = dijkstra(inv, fin, n+1);
        int may = -1;
        for(int i = 1; i <= n; i++){
            if(dist[i] == inf) continue;
            for(int j = 1; j <= n; j++){
                if(!cam[i][j]) continue;
                //printf("probamos de %d a %d = %d | %d a %d = %d | y de %d a %d = %d\n",
                //    ini,i,dist[i],  i,j,matriz[i][j],  j,fin,distInv[j]);
                if(dist[i] + matriz[i][j] + distInv[j] <= p){
                    may = max(may, matriz[i][j]);
                }
            }
        }

        printf("%d\n", may);
    }

    return 0;
}


