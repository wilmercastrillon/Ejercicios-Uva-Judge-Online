#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
typedef long long int lli;

lli memo[(1<<21)+1];
int lim, n, d, g[30];

lli dp(int mask){
    if(mask == lim) return 1LL;
    if(memo[mask] != -1) return memo[mask];

    lli ans = 0;

    int i;
    for(i = 0; i < n; i++)
        if(!(mask&(1<<i))) break;

    forab(j,i+1,n){
        if(mask&(1<<j) || g[j]-g[i]>d) continue;

        forab(k,j+1,n){
            if(mask&(1<<k) || g[k]-g[i]>d) continue;
            ans += dp(mask|(1<<i)|(1<<j)|(1<<k));
        }
    }

    return memo[mask] = ans;
}

int main(){
    int fact[8];
    fact[0] = 1;
    forab(i,1,8){
        fact[i] = fact[i-1]*i;
    }
    //freopen("salida.txt", "w", stdout);

    while(scanf("%d %d", &n, &d), n){
        memset(memo, -1, sizeof(memo));
        lim = (1<<n) - 1;
        forr(i, n)
            scanf("%d", &g[i]);
        sort(g, g+n);

        printf("%lld\n", dp(0));
    }
    return 0;
}


