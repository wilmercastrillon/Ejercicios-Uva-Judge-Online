#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 400;
int start, target, _mf, f, matriz[400][400];
int num[400][400];
vvi grafo;
vi p;

void augment(int v, int minEdge){
    if(v == start){ f = minEdge; return; }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, matriz[p[v]][v]));
        matriz[p[v]][v] -= f;  matriz[v][p[v]] += f;
} }

int EdmondsKarp(){
    _mf = 0;
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
        _mf += f;
    }
    return _mf;
}

int fil, col;
int mf[4] = {-1, 0, 1, 0}, mc[4] = {0, 1, 0, -1};
char tab[400][400];

void addEdge(int x, int y, int p){
    //printf("%d %d %d\n", x, y, p);
    grafo[x].push_back(y);
    grafo[y].push_back(x);
    matriz[x][y] = p;
    matriz[y][x] = 0;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, auxf, auxc, z, con, t, x, y;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &fil, &col);
        memset(matriz, 0, sizeof(matriz));
        grafo.assign(400, vi(0));
        start = 398;  target = 399;

        con = 0;
        for(int i = 0; i < fil; i++){
            scanf("%s", &tab[i]);
            for(int j = 0; j < col; j++){
                if(tab[i][j]=='*') num[i][j] = con++;
            }
        }

        for(int i = 0; i < fil; i++){
            for(int j = 0; j < col; j++){
                if(tab[i][j]=='o') continue;

                for(int k = 0; k < 4; k++){
                    auxf = i+mf[k];
                    auxc = j+mc[k];
                    if(auxf>=0&&auxf<fil && auxc>=0&&auxc<col && tab[auxf][auxc]=='*'){
                        if((j+i)&1) addEdge(num[auxf][auxc], num[i][j], 1);
                        else addEdge(num[i][j], num[auxf][auxc], 1);
                    }
                }

                if((j+i)&1) addEdge(num[i][j], target, 1);
                else addEdge(start, num[i][j], 1);
            }
        }

        printf("%d\n", con-EdmondsKarp());
    }

    return 0;
}


