#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int start, target, MAX=40;//MAX=numero de nodos
int mf, f, matriz[110][110];
vi p;
vvii grafo;

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
    int n, m, x, y, z, con = 1;
    while(scanf("%d", &n), n){
        memset(matriz, 0, sizeof(matriz));
        grafo.assign(n+1, vii(0));

        MAX = n;
        scanf("%d %d %d", &start, &target, &m);
        start--;  target--;

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo[x-1].push_back(ii(z, y-1));
            grafo[y-1].push_back(ii(z, x-1));
            matriz[x-1][y-1] += z;
            matriz[y-1][x-1] += z;
        }

        printf("Network %d\nThe bandwidth is %d.\n\n", con++, EdmondsKarp());
    }

    return 0;
}


