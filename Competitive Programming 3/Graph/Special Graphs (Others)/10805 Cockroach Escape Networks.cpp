#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define inf 1000000000 //10^9

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int matriz[300][300];

int FloydWarshall(int nodos, int nn){
    int aux, men = inf;
    for(int i = 0; i < nn; i++) matriz[i][i] = 0;

    for(int k = 0; k < nn; k++)
        for(int i = 0; i < nn; i++)
            for(int j = 0; j < nn; j++){
                aux = matriz[i][k] + matriz[k][j];
                if(matriz[i][j] > aux){
                    matriz[i][j] = aux;
                }
            }
    /*for(int i = 0; i < nn; i++){
        for(int j = 0; j < nn; j++){
            printf(" %10d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    for(int i = 0; i < nn; i++){
        int may = 0,m1 = 0, m2 = 0;
        for(int j = 0; j < nodos; j++){
            if(i == j) continue;

            if(m1 < matriz[i][j] && matriz[i][j] < inf){
                m2 = m1;
                m1 = matriz[i][j];
            }else if(m2 < matriz[i][j] && matriz[i][j] < inf){
                m2 = matriz[i][j];
            }
            may = max(may, m1 + m2);
        }
        men = min(men, may);
    }
    return men;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, n, m, x, y, nn;
    scanf("%d", &t);

    for(int k = 1; k <= t; k++){
        scanf("%d %d", &n, &m);
        nn = n;
        memset(matriz, 5436, sizeof(matriz));
        int best = inf;

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            matriz[x][nn] = 1;
            matriz[nn][y] = 1;
            matriz[y][nn] = 1;
            matriz[nn][x] = 1;
            nn++;
        }

        printf("Case #%d:\n%d\n\n", k, FloydWarshall(n, nn)/2);
    }
	return 0;
}


