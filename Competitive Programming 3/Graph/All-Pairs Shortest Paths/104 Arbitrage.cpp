#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int cam[25][25][25];
double matriz[25][25][25];

void camino(int f, int c, int m){
    //printf("llegamos %d %d con %d aristas sigue %d\n", f, c, m, (m)? cam[f][c][m]:-1);
    if(m==0){
        printf(" %d", c+1);
        return;
    }else{
        camino(f, cam[f][c][m], m-1);
        printf(" %d", c+1);
    }
}

void imp(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d", cam[i][j][m]+1);
        }
        printf("\n");
    }
    printf("\n");
}

bool FloydWarshall(int nodos){
    double aux;
    for(int i = 0; i < nodos; i++){
        for(int j = 0; j < nodos; j++){
            cam[i][j][0] = i;
        }
    }

    for(int m = 1; m < nodos; m++)
    for(int k = 0; k < nodos; k++){
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = matriz[i][k][m-1] * matriz[k][j][0];
                if(matriz[i][j][m] < aux){
                    matriz[i][j][m] = aux;
                    cam[i][j][m] = k;
                }
            }
    }

    for(int m = 1; m < nodos; m++)
        for(int i = 0; i < nodos; i++){
            if(matriz[i][i][m] > 1.01){
                //("mejoramos a %d hasta %.5f usando %d aristas\n", i + 1, matriz[i][i][m], m);
                printf("%d", i+1);
                camino(i,cam[i][i][m],m-1);
                printf(" %d\n", i+1);
                return true;
            }
        }

    return false;
}

int main(){
    int n;

    while(scanf("%d", &n) != EOF){
        memset(matriz, 0, sizeof(matriz));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(i == j) matriz[i][j][0] = 1.0;
                else{
                    scanf("%lf", &matriz[i][j][0]);
                }
            }

        if(!FloydWarshall(n)) printf("no arbitrage sequence exists\n");
    }

    return 0;
}


