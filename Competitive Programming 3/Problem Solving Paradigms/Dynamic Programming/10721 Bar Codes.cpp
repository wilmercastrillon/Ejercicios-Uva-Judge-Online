#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long int lli;

lli memo[51][51][51], n, k, m;

lli dp(int acum, int can, int tam){
    if(acum > n || tam > m || can > k) return 0;
    if(can == k && acum == n) return 1;
    if(memo[acum][can][tam] != -1) return memo[acum][can][tam];

    lli res = dp(acum, can, tam+1) + dp(acum+tam, can+1, 1);
    return memo[acum][can][tam] = res;
}

int main(){
    while(scanf("%d %d %d", &n, &k, &m) != EOF){
        memset(memo, -1, sizeof(memo));
        printf("%lld\n", dp(0, 0, 1));
    }
    return 0;
}


