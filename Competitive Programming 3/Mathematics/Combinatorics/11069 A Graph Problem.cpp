#include <stdio.h>
#include <string.h>

using namespace std;

int memo[80], n;

int dp(int pos){
    if(pos > n) return 0;
    if(pos >= n-1) return 1;
    if(memo[pos] != -1) return memo[pos];
    return memo[pos] = dp(pos+2) + dp(pos+3);
}

int main(){

    while(scanf("%d", &n) != EOF){
        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(1)+dp(2));
    }

    return 0;
}
