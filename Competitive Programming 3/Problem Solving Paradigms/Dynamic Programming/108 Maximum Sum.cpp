#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int tab[102][102];

void build(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            tab[i][j] += tab[i-1][j] + tab[i][j-1];
            tab[i][j] -= tab[i-1][j-1];
        }
}

int solve(){
    int may = -1000000000, aux;
    for(int i1 = 1; i1 <= n; i1++)
    for(int j1 = 1; j1 <= n; j1++)
        for(int i2 = i1; i2 <= n; i2++)
        for(int j2 = j1; j2 <= n; j2++){
            aux = tab[i2][j2] - tab[i1-1][j2] - tab[i2][j1-1];
            aux += tab[i1-1][j1-1];
            may = max(may, aux);
        }

    return may;
}

int main(){

    while(scanf("%d", &n) != EOF){
        memset(tab, 0, sizeof(tab));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &tab[i+1][j+1]);

        build();
        printf("%d\n", solve());
    }

    return 0;
}


