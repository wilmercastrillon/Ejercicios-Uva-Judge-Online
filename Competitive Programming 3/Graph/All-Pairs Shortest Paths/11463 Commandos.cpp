#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int matriz[105][105];

void FloydWarshall(int nodos){
    int aux;
    for(int i = 0; i < nodos; i++) matriz[i][i] = 0;//sin caminos

    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = matriz[i][k] + matriz[k][j];
                if(matriz[i][j] > aux){
                    matriz[i][j] = aux;
                }
            }
}

int main(){
    int t, n, m, x, y, ini, fin;
    scanf("%d", &t);

    for(int k = 1; k <= t; k++){
        memset(matriz, 5436, sizeof(matriz));
        scanf("%d", &n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            matriz[x][y] = 1;
            matriz[y][x] = 1;
        }
        scanf("%d %d", &ini, &fin);
        FloydWarshall(n);

        int may = 0;
        for(int i = 0; i < n; i++){
            may = max(may, matriz[ini][i] + matriz[i][fin]);
        }
        printf("Case %d: %d\n", k, may);
    }

	return 0;
}


