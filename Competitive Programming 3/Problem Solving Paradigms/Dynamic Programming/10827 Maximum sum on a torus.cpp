#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
int tab[160][160];

void build(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            tab[i][j] += tab[i-1][j] + tab[i][j-1];
            tab[i][j] -= tab[i-1][j-1];
        }
}

int solve(){
    int may = -1000000000, aux;
    for(int i1 = 1; i1 <= m; i1++)
    for(int j1 = 1; j1 <= m; j1++)
        for(int i2 = i1; i2 - i1 < m; i2++)
        for(int j2 = j1; j2 - j1 < m; j2++){
            aux = tab[i2][j2] - tab[i1-1][j2] - tab[i2][j1-1];
            aux += tab[i1-1][j1-1];
            may = max(may, aux);
        }

    return may;
}

int main(){
    int casos;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &m);
        memset(tab, 0, sizeof(tab));

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++){
                scanf("%d", &tab[i][j]);
                tab[m+i][m+j] = tab[i][j];
                tab[m+i][j] = tab[i][j];
                tab[i][m+j] = tab[i][j];
            }

        n = m*2;
        build();
        printf("%d\n", solve());
    }

    return 0;
}


