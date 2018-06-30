#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int FloydWarshall(vector<vector<int>> &grafo, int nodos){
    int aux;
    if(nodos == 1) return 0;
    //hacemos las diagonales cero
    for(int i = 0; i < nodos; i++) grafo[i][i] = 0;
    int may = 0;

    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = grafo[i][k] + grafo[k][j];
                if(grafo[i][j] > aux) grafo[i][j] = aux;

                if(k + 1 == nodos){
                    may = max(may, grafo[i][j]);
                }
            }
    return may;
}

int main(){
    int n, m, x, y, z, a;

    while(scanf("%d %d", &n, &m) != EOF){

        vvi grafo(n, vi(n, inf));
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            grafo[x][y] = z;
            grafo[y][x] = z;
        }
        int men = 1000000000;
        for(int i = 0; i < 3; i++){
            scanf("%d", &a);
            men = min(men, a);
        }

        int res = FloydWarshall(grafo, n);

        double aux = ((double) res) / ((double) men);
        res = res / men;
        if(aux > res) res++;
        printf("%d\n", res);
    }

    return 0;
}


