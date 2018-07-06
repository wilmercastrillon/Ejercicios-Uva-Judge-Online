#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 1000000000

using namespace std;

int x, tab[11][1010], memo[11][1010];

int dp(int alt, int pos){
    if(alt > 9 || alt < 0 || pos > x) return inf;
    if(pos == x && alt == 0) return 0;
    if(memo[alt][pos] != -1) return memo[alt][pos];

    int res = min((60-tab[alt][pos]) + dp(alt+1, pos+1),
                  (30-tab[alt][pos]) + dp(alt, pos+1));
    res = min(res, (20-tab[alt][pos]) + dp(alt-1, pos+1));
    return memo[alt][pos] = res;
}

int main(){
    int casos;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &x);
        x /= 100;

        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < x; j++)
                scanf("%d", &tab[i][j]);

        memset(memo, -1, sizeof(memo));
        printf("%d\n\n", dp(0, 0));
    }
    return 0;
}


