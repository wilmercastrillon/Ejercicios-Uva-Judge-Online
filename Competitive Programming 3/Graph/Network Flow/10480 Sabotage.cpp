#include <bits/stdc++.h>
#define inf 1000000000
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
//typedef long long int lli

int start, target, MAX=110, mf, f, matriz[110][110];
vi p;  vvi grafo;

void augment(int v, int minEdge){
    if(v == start){ f = minEdge; return; }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, matriz[p[v]][v]));
        matriz[p[v]][v] -= f;  matriz[v][p[v]] += f;
} }

int EdmondsKarp(){
    mf = 0;
    while(true){
        f = 0;
        vector<bool> vis(MAX, false); vis[start] = true;
        queue<int> cola;  cola.push(start);
        p.assign(MAX, -1);
        while(cola.size()){
            int u = cola.front();  cola.pop();
            if(u == target) break;

            for(int j = 0; j < grafo[u].size(); j++){
                int v = grafo[u][j];
                if(matriz[u][v] > 0 && !vis[v]){
                    vis[v] = true;
                    cola.push(v);  p[v] = u;
        }}}
        augment(target, inf);
        if(f == 0) break;
        mf += f;
    }
    return mf;
}

void addEdgeUndirected(int x, int y, int z){
    grafo[x].push_back(y);  grafo[y].push_back(x);
    matriz[x][y] += z;  matriz[y][x] += z;
}
void addEdgeDirected(int x, int y, int z){
    grafo[x].push_back(y);  grafo[y].push_back(x);
    matriz[x][y] += z;  matriz[y][x] += 0;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, z;

    while(scanf("%d %d", &n, &m), n){
        grafo.assign(n+1,vi(0));
        memset(matriz, 0, sizeof(matriz));

        forr(i,m){
            scanf("%d %d %d", &x, &y, &z);
            addEdgeUndirected(x, y, z);
        }

        start = 1;
        target = 2;
        int costo = EdmondsKarp();
        printf("maximo flujo %d\n", costo);

        forab(i,1,n+1){
            forab(j,1,n+1){
                printf("%3d ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        //printf("Case %d: %d\n", ++caso, res);
    }

    return 0;
}


