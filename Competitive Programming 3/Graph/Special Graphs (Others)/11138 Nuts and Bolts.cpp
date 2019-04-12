#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 1010;
int bolts, nuts, matriz[MAX][MAX];
int start, target, mf, f;
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

void addEdge(int x, int y, int z){
    grafo[x].push_back(y);  grafo[y].push_back(x);
    matriz[x][y] = z;  matriz[y][x] = 0;
}

void read_and_buid_data(){
    int n,b, aux;
    for(b=0;b<bolts;b++){
        for(n=0;n<nuts;n++){
            scanf("%d",&aux);
            if(aux){
                addEdge(b, bolts+n, 1);
            }
        }
    }
    for(b=0;b<bolts;b++) addEdge(start, b, 1);
    for(n=0;n<nuts;n++) addEdge(bolts+n, target, 1);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int cases,caseno;
    scanf("%d",&cases);

    for(caseno=1;caseno<=cases;caseno++){
        scanf("%d%d",&bolts,&nuts);
        memset(matriz, 0, sizeof(matriz));
        grafo.assign(bolts+nuts+10, vi(0));
        start = bolts+nuts+2;
        target = bolts+nuts+3;

        read_and_buid_data();
        int bestmatched = EdmondsKarp();
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}


