#include <stdio.h>
#include <string.h>

typedef long long int lli;

lli memo[30010][6];
int n;
int ar[] = {1, 5, 10, 25, 50};

lli dp(int res, int pos){
    if(pos == 5) return 0;
    if(res == 0) return 1;
    if(res < 0) return 0;

    if(memo[res][pos] != -1) return memo[res][pos];
    memo[res][pos] = dp(res, pos+1) + dp(res-ar[pos], pos);
    return memo[res][pos];
}

int main(){
    lli sol;
    memset(memo, -1, sizeof(memo));

    while(scanf("%d", &n) != EOF){
        sol = dp(n, 0);
        if(sol == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", sol, n);
    }

    return 0;
}


