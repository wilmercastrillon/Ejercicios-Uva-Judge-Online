#include <bits/stdc++.h>
#define inf 1000000

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi grafo(5010);
vi dist, ruta;
int n;

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
        //printf("llegamos a %d con peso %d\n", nodo, peso);
        //if(dist[nodo] <= peso) continue;
        //dist[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            aux = grafo[nodo][i];
            //printf("podemos itr a %d con peso %d\n", aux, peso+1);
            if(dist[aux] > peso+1){
                dist[aux] = peso+1;
                cola.push(ii(aux, peso+1));
            }
        }
    }
    return nodo;
}

void cam(int nodo){
    ruta.push_back(nodo);
    for(int i = 0; i < grafo[nodo].size(); i++){
        if(dist[nodo]-1 == dist[grafo[nodo][i]]){
            cam(grafo[nodo][i]);
            return;
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int x, y, k;

    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            grafo[i].clear();
            scanf("%d", &k);
            for(int j = 0; j < k; j++){
                scanf("%d", &x);
                grafo[i].push_back(x);
            }
        }
        ruta.clear();

        int u, v, peor = -1, m[3];
        u = bfs(1);
        v = bfs(u);
        cam(v);
        m[0] = ruta[ruta.size()>>1];
        m[1] = ruta[(ruta.size()>>1)-1];

        //peor = dist[ruta[0]];
        //printf("peor distancia %d\n");
        vi worst;
        bfs(m[0]);
        for(int i = 1; i <= n; i++){
            if(peor < dist[i]){
                peor = dist[i];
                worst.clear();
            }
            if(dist[i] == peor) worst.push_back(i);
        }
        //printf("peor para %d es dist %d\n", m[0], peor);
        if(ruta.size()%2 == 0){
            bfs(m[1]);
            for(int i = 1; i <= n; i++){
                if(peor < dist[i]){
                    peor = dist[i];
                    worst.clear();
                }
                if(dist[i] == peor) worst.push_back(i);
            }
            //printf("peor para %d es dist %d\n", m[1], peor);
        }

        sort(worst.begin(), worst.end());
        if(ruta.size()&1) printf("Best Roots  : %d\n", m[0]);
        else{
            sort(m, m+2);
            printf("Best Roots  : %d %d\n", m[0], m[1]);
        }

        printf("Worst Roots :");
        for(int i = 0; i < worst.size(); i++)
            printf(" %d", worst[i]);
        printf("\n");
    }

    return 0;
}


