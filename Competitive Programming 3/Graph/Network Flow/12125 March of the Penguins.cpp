#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
#define inf 1000000000
#define forr(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int start, target, MAX=250, mf, f, matriz[250][250], copia[250][250], n;
vi p;  vvi grafo;
double salto;
vector<ii> bloques;

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

bool alcanzable(ii ini, ii dest){
    return (hypot((ini.first-dest.first)*1.0, (ini.second-dest.second)*1.0) <= salto);
}

void bulidGrafo(){
    forr(i, bloques.size()){
        forab(j, i+1, bloques.size()){
            if(!alcanzable(bloques[i], bloques[j])) continue;

            //printf("insertaremos %d a %d con peso %d\n", i+n, j, 1000000);
            grafo[i+n].push_back(j);
            grafo[j].push_back(i+n);
            copia[i+n][j] = 1000000;

            //printf("insertaremos %d a %d con peso %d\n", j+n, i, 1000000);
            grafo[j+n].push_back(i);
            grafo[i].push_back(j+n);
            copia[j+n][i] = 1000000;
        }
    }
}

void copiar(){
    forr(i, MAX) forr(j, MAX) matriz[i][j] = copia[i][j];
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int x, y, cant, cap, t, total;
    scanf("%d", &t);
    while(t--){
        total = 0;
        memset(copia, 0, sizeof(copia));
        bloques.clear();
        cin >> n >> salto;

        MAX = n*2 + 5;
        grafo.assign(MAX, vi(0));
        start = MAX-3;

        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &x, &y, &cant, &cap);
            total += cant;
            bloques.push_back(ii(x,y));

            //printf("conexion %d a %d con peso %d\n", i, i+n, cap);
            grafo[i].push_back(i+n);
            grafo[i+n].push_back(i);
            copia[i][i+n] += cap;

            if(cant == 0) continue;
            //printf("conexion %d a %d con peso %d\n", start, i, cant);
            grafo[start].push_back(i);
            grafo[i].push_back(start);
            copia[start][i] += cant;
        }
        bulidGrafo();

        vi res;
        for(int i = 0; i < bloques.size(); i++){
            copiar();
            target = i;
            if(total == EdmondsKarp()) res.push_back(i);
        }

        if(res.size()){
            printf("%d", res[0]);
            forab(i, 1, res.size()) printf(" %d", res[i]);
            printf("\n");
        }else printf("-1\n");
    }

    return 0;
}


