#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int v[110], costo[110], n, m, m2;
int memo[10300][105];

int dp(int obj, int acum){
    if(obj == n){
        if(m != m2){
            if(acum > 2000 || acum < m) return 0;
            else return -1000000000;
        }else return 0;
    }

    if(memo[acum][obj] != -1) return memo[acum][obj];

    if(acum + costo[obj] > m2) return memo[acum][obj] = dp(obj+1, acum);
    return memo[acum][obj] = max(dp(obj+1, acum),
                            v[obj] + dp(obj+1, acum + costo[obj]));
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    while(scanf("%d %d", &m, &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &costo[i], &v[i]);
        }
        m2 = (m > 1800)? m + 200 : m;
        memset(memo, -1, sizeof(memo));
        //printf("#####################\n");
        printf("%d\n", dp(0, 0));
    }

    return 0;
}


