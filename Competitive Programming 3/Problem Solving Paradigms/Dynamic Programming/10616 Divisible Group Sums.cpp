#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long int lli;

lli ar[201], d;
lli memo[210][12][22];//elemento n, restantes, modulo
int n, mIni;

lli dp(int pos, int m, lli acum){
    if(m < 0) return 0;
    if(pos == n){
        return (acum==0 && m==0);
    }
    if(memo[pos][m][acum] != -1) return memo[pos][m][acum];

    lli res = dp(pos+1, m, acum) + dp(pos+1, m-1, ((acum+ar[pos])%d+d)%d);
    return memo[pos][m][acum] = res;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int q, caso = 1;

    while(scanf("%d %d", &n, &q), n, q){
        for(int i = 0; i < n; i++){
            scanf("%lld", &ar[i]);
        }
        printf("SET %d:\n", caso++);
        for(int j = 1; j <= q; j++){
            scanf("%lld %d", &d, &mIni);
            memset(memo, -1, sizeof(memo));
            printf("QUERY %d: %lld\n", j, dp(0, mIni, 0));
        }
    }

    return 0;
}


