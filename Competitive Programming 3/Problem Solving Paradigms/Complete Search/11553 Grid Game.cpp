#include <stdio.h>
#include <algorithm>
#define infN -1000000000
#define inf 1000000000

using namespace std;

int memo[1<<8][1<<8];
int m[9][9];
int l, n;

int dp(int maskf, int maskc){
    if(memo[maskf][maskc] != inf) return memo[maskf][maskc];
    if(maskf == l && maskc == l) return memo[maskf][maskc] = 0;

    int i, j, men = inf;
    for(i = 0; i < n; i++)
        if(!(maskf & (1 << i))) break;

    for(j = 0; j < n; j++)
        if(!(maskc & (1 << j)))
            men = min(men, m[i][j] + dp(maskf | (1<<i), maskc | (1<<j)));

    return memo[maskf][maskc] = men;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, l2;
    int ar1[9], ar2[9];
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        l2 = 1<<n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &m[i][j]);

        for(int i = 0; i < l2; i++)
            for(int j = 0; j < l2; j++)
                memo[i][j] = inf;

        l = (1 << n) - 1;
        printf("%d\n", dp(0, 0));
    }

    return 0;
}


