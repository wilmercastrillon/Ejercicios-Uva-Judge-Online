#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int start, target, MAX=110;//MAX=numero de nodos
int mf, f, matriz[110][110];
vi p;
vvi grafo;

void augment(int v, int minEdge){
    //printf("v = %d, min = %d , p[v]=%d\n", v, minEdge, p[v]);
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
            if(u == target) break;
            //printf("Estamos en %d\n", u);

            for(int j = 0; j < grafo[u].size(); j++){
                //printf("   Probamos con j=%d ir a %d\n", j, grafo[u][j]);
                int v = grafo[u][j];
                if(matriz[u][v] > 0 && !vis[v]){
                    vis[v] = true;
                    cola.push(v);  p[v] = u;
                }
            }
        }
        //printf("target = %d\n", target);
        augment(target, inf);
        if(f == 0) break;
        mf += f;
    }
    return mf;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, z;
    while(scanf("%d %d", &n, &m), n){
        memset(matriz, 0, sizeof(matriz));
        grafo.assign(MAX, vi(0));

        for(int i = 2; i < n; i++){
            scanf("%d %d", &x, &z);
            //printf("conex %d a %d con peso %d\n", x, x+50, z);
            grafo[x].push_back(x+50);
            grafo[x+50].push_back(x);
            matriz[x][x+50] = z;
        }

        int xarr, yarr;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            xarr = (x!=1 && x!=n)? x+50: x;
            //printf("conex %d a %d con peso %d\n", xarr, y, z);
            grafo[xarr].push_back(y);
            grafo[y].push_back(xarr);
            matriz[xarr][y] = z;

            yarr = (y!=1 && y!=n)? y+50: y;
            //printf("conex %d a %d con peso %d\n", yarr, x, z);
            grafo[yarr].push_back(x);
            grafo[x].push_back(yarr);
            matriz[yarr][x] = z;
        }

        start = 1; target = n;
        printf("%d\n", EdmondsKarp());
    }

    return 0;
}


