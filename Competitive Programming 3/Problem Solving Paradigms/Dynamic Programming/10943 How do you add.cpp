#include <stdio.h>
#include <string.h>
#define mod 1000000

using namespace std;

int memo[110][100], n, k;

int dp(int acum, int can){
    if(acum > n || can > k) return 0;
    if(acum == n && can == k) return 1;
    if(memo[acum][can] != -1) return memo[acum][can];

    int res = 0, lim = n-acum;
    for(int i = 0; i <= lim; i++){
        res = ( res + dp(acum+i, can+1) ) % mod;
    }
    return memo[acum][can] = res;
}

int main(){
    while(scanf("%d %d", &n, &k), n, k){
        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(0, 0));
    }
    return 0;
}


