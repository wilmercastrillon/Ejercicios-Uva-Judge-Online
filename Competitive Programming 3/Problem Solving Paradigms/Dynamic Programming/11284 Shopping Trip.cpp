#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define inf 1000000000.0
//5436 infinito 32 bits memset

using namespace std;

int n, m, p, lim;
double memo[14][1<<14], grafo[52][52];

void llenar(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grafo[i][j] = inf;
}
void imp(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f   ", grafo[i][j]);
        }
        printf("\n");
    }
}
void llenar2(){
    for(int i = 0; i <= p; i++)
        for(int j = 0; j <= lim; j++)
            memo[i][j] = -1;
}

void floyd(int nodos){
    double aux;
    for(int i = 0; i < nodos; i++) grafo[i][i] = 0;

    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = grafo[i][k] + grafo[k][j];
                if(grafo[i][j] > aux) grafo[i][j] = aux;
            }
}

int tab[13];
double des[13];

double tsp(int pos, int mask){
    if(mask == lim) return -grafo[tab[pos]][0];
    if(memo[pos][mask] != -1) return memo[pos][mask];

    double res = -grafo[tab[pos]][0];//regresar
    for(int i = 1; i < p; i++){
        if(!(mask&(1<<i))){
            res = max(res, des[i] + (-grafo[tab[pos]][tab[i]]) + tsp(i, mask|(1<<i)));
        }
    }
    return memo[pos][mask] = res;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int casos, q, w;
    double x;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d %d", &n, &m);
        n++;
        llenar();
        for(int i = 0; i < m; i++){
            scanf("%d %d %lf", &q, &w, &x);
            grafo[q][w] = min(x, grafo[q][w]);
            grafo[w][q] = min(x, grafo[w][q]);
        }
        floyd(n);
        //imp();

        scanf("%d", &p);
        p++;
        lim = (1<<p)-1;
        tab[0] = 0; des[0] = 0;
        for(int i = 1; i < p; i++){
            scanf("%d %lf", &tab[i], &des[i]);
        }
        llenar2();

        double res = tsp(0,1);
        if((res-(1e-3)) > 0) printf("Daniel can save $%.2f\n", res);
        else printf("Don't leave the house\n");
    }

    return 0;
}


