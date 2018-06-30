#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;
typedef vector<ulli> vulli;
typedef vector<vulli> vvulli;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define inf 9223372036854775807

void floyd(vvulli &grafo, int nodos, vvi &cam){
    ulli aux;
    for(int i = 1; i <= nodos; i++){
        for(int j = 1; j <= nodos; j++){
            if(i == j) grafo[i][j] = 0;
            if(i != j && grafo[i][j] != inf) cam[i][j] = i;
        }
    }

    for(int k = 1; k <= nodos; k++)
        for(int i = 1; i <= nodos; i++)
            for(int j = 1; j <= nodos; j++){
                aux = grafo[i][k] + grafo[k][j];
                if(grafo[i][j] > aux){
                    grafo[i][j] = aux;
                    cam[i][j] = cam[k][j];
                }
            }
}

void imprimirCamino(int f, int c, vvi &cam){
    if(cam[f][c] == f){
        printf("%d", f);
        return;
    }else{
        imprimirCamino(f, cam[f][c], cam);
        printf(" %d", cam[f][c]);
    }
}

int main(){
    int i = 0, n, m, ini, des;
    ulli x, y, z;

    while(scanf("%d", &n), n){
        vvulli grafo(n + 1, vulli(n + 1, inf));
        vvi camino(n+1, vi(n+1, 0));

        for(int j = 1; j <= n; j++){
            scanf("%d", &m);
            x = j;
            for(int k = 0; k < m; k++){
                scanf("%llu %llu", &y, &z);
                grafo[x][y] = z;
            }
        }
        scanf("%d %d", &ini, &des);
        floyd(grafo, n, camino);
        printf("Case %d: Path = ", ++i);
        imprimirCamino(ini, des, camino);
        printf(" %d; %llu second delay\n", des, grafo[ini][des]);
    }

    return 0;
}


