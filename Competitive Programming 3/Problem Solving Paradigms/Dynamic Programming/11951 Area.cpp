#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;
typedef long long ll;

int n, m;
ll k;
ll tab[102][102];

void build(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            tab[i][j] += tab[i-1][j] + tab[i][j-1];
            tab[i][j] -= tab[i-1][j-1];
        }
}

ll solve(ll &area, ll &costo){
    ll auxC, auxA;
    costo = 0;
    area = 0;
    for(int i1 = 1; i1 <= n; i1++)
    for(int j1 = 1; j1 <= m; j1++)
        for(int i2 = i1; i2 <= n; i2++)
        for(int j2 = j1; j2 <= m; j2++){
            auxC = tab[i2][j2] - tab[i1-1][j2] - tab[i2][j1-1];
            auxC += tab[i1-1][j1-1];
            auxA = (i2-i1+1)*(j2-j1+1);
            //printf("auxA %d\n", auxA);
            if(k >= auxC){
                //printf("k = %d | auxc = %d\n", k, auxC);
                if(auxA > area || (auxA == area && costo > auxC)){
                    area = auxA;
                    costo = auxC;
                }
            }
        }
}

int main(){
    int casos;
    ll area, costo;
    scanf("%d", &casos);

    for(int l = 1; l <= casos; l++){
        scanf("%d %d %lld", &n, &m, &k);
        memset(tab, 0, sizeof(tab));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%lld", &tab[i+1][j+1]);

        build();
        solve(area, costo);
        printf("Case #%d: %lld %lld\n", l, area, costo);
    }

    return 0;
}


