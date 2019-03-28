#include <bits/stdc++.h>
#define inf 1000000

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi grafo;
vi dist, ruta;
int n;
bool matriz[2510][2510];

int bfs(int nodo){//nodo mas alejado
    dist.assign(n+1, inf);
    queue<ii> cola;
    cola.push(ii(nodo, 0));
    ii par;  dist[nodo] = 0;
    int peso, aux;

    while(cola.size()){
        par = cola.front();  cola.pop();
        nodo = par.first;
        peso = par.second;

        for(int i = 0; i < grafo[nodo].size(); i++){
            aux = grafo[nodo][i];
            if(matriz[nodo][aux]){
                if(dist[aux] > peso+1){
                    dist[aux] = peso+1;
                    cola.push(ii(aux, peso+1));
                }
            }
        }
    }
    return nodo;
}

void cam(int nodo, vi &vec){
    vec.push_back(nodo);
    for(int i = 0; i < grafo[nodo].size(); i++){
        if(dist[nodo]-1 == dist[grafo[nodo][i]]){
            cam(grafo[nodo][i], vec);
            return;
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int x, y, k, t, m;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        memset(matriz, false, sizeof(matriz));
        grafo.assign(n+1, vi(0));
        for(int i = 1; i < n; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
            grafo[y].push_back(x);
            matriz[x][y] = true;
            matriz[y][x] = true;
        }
        ruta.clear();

        int u, v, men = inf, d1, d2, q1, q2, n1, n2, aux;
        u = bfs(1);
        v = bfs(u);
        cam(v, ruta);

        for(int i = 1; i < ruta.size(); i++){
            matriz[ruta[i]][ruta[i-1]] = false;
            matriz[ruta[i-1]][ruta[i]] = false;

            vi r1, r2;
            u = bfs(ruta[i]);  v = bfs(u);  d1 = dist[v] + 1;
            cam(v, r1);
            u = bfs(ruta[i-1]);  v = bfs(u);  d2 = dist[v] + 1;
            cam(v, r2);

            aux = max((d1>>1) + (d2>>1) + 1, max(d1-1, d2-1));
            if(aux < men){
                men = aux;
                q1 = ruta[i];  q2 = ruta[i-1];
                n1 = r1[r1.size()>>1];  n2 = r2[r2.size()>>1];
            }
            /*printf("rompiendo %d con %d tendriamos %d\n", ruta[i], ruta[i-1], aux);
            for(int i = 0; i < r1.size(); i++){
                printf(" %d", r1[i]);
            }
            printf("\n");
            for(int i = 0; i < r2.size(); i++){
                printf(" %d", r2[i]);
            }
            printf("\n");*/

            matriz[ruta[i]][ruta[i-1]] = true;
            matriz[ruta[i-1]][ruta[i]] = true;
        }

        printf("%d\n%d %d\n%d %d\n", men, q1, q2, n1, n2);
    }

    return 0;
}


