#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 1000000000

using namespace std;

int memo[610][310], n, k;
int dis[610];

int dp(int camp, int noche){
    //printf("camp %d con noche %d\n", camp, noche);
    if(camp > n){
        //printf("  #camp > n: 0\n");
        return 0;
    }
    if(noche > k){
        //printf("  #noche > k: inf\n");
        return inf;
    }
    if(memo[camp][noche] != -1){
        //printf("  #ya calculado era %d\n", memo[camp][noche]);
        return memo[camp][noche];
    }

    int ans = inf, acum = 0, aux, q;
    for(int i = camp; i <= n; i++){
        acum += dis[i];
        //printf("  acum: %d, dis[%d] = %d\n", acum, i, dis[i]);
        q = dp(i+1, noche+1);
        aux = max(q, acum);
        ans = min(ans, aux);
        //printf("  aux es max(%d, %d): %d | ans= %d\n", q, acum, aux, ans);
    }

    //printf(" #memo[%d][%d] = %d\n", camp, noche, ans);
    return memo[camp][noche] = ans;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    while(scanf("%d %d", &n, &k) != EOF){
        for(int i = 0; i <= n; i++){
            scanf("%d", &dis[i]);
        }

        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(0, 0));
    }

    return 0;
}


