#include <stdio.h>
#include <string.h>

using namespace std;

int n, e, t, grafo[101][101];

void FloydWarshall(){
    int aux;
    for(int i = 0; i < n; i++) grafo[i][i] = 0;

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                aux = grafo[i][k] + grafo[k][j];
                if(grafo[i][j] > aux) grafo[i][j] = aux;
            }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, m, a, b, c, casos;
    scanf("%d", &casos);

    while(casos--){
        memset(grafo, 5436, sizeof(grafo));
        scanf("%d %d %d %d", &n, &e, &t, &m);
        e--;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            grafo[a-1][b-1] = c;
        }

        FloydWarshall();
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%12d", grafo[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        int con = 0;
        for(int i = 0; i < n; i++){
            if(grafo[i][e] <= t) con++;
        }
        printf("%d\n", con);
        if(casos) printf("\n");
    }

    return 0;
}
