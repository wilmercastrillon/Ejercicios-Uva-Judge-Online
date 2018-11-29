#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int matriz[105][105], inf;

double FloydWarshall(int nodos){
    int aux, can = 0, ant = nodos-1, con = 0;
    for(int i = 0; i < nodos; i++) matriz[i][i] = 0;//sin caminos

    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = matriz[i][k] + matriz[k][j];
                if(matriz[i][j] > aux){
                    matriz[i][j] = aux;
                }
                if(k == ant && i != j && matriz[i][j] != inf){
                    //printf("de %d a %d suma %d\n", i, j, matriz[i][j]);
                    can += matriz[i][j];
                    con++;
                }
            }

    //printf("%d %d\n", can, con);
    return (double) can/con;
}

int main(){
    int n, x, y, caso = 1;

    while(scanf("%d %d", &x, &y), x){
        memset(matriz, 5436, sizeof(matriz));
        inf = matriz[0][0];
        matriz[x][y] = 1;
        n = max(x, y);

        while(scanf("%d %d", &x, &y), x){
            matriz[x][y] = 1;
            n = max(n, max(x, y));
        }

        printf("Case %d: average length between pages = %.3f clicks\n", caso++, FloydWarshall(n+1));
    }

	return 0;
}


