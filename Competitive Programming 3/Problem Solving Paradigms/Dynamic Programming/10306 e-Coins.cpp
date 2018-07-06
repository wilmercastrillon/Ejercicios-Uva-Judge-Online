#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int inf = 1000000000;
int con[42], tec[10], m, s;
int memo[42][310][310];

int dp(int pos, int vcon, int vtec){//posicion, convencional, tecnologia
    int aux = vcon*vcon + vtec*vtec;
    if(aux == s) return 0;
    if(pos == m || aux > s) return inf;
    if(memo[pos][vcon][vtec] != -1) return memo[pos][vcon][vtec];

    memo[pos][vcon][vtec] = min(dp(pos+1,vcon,vtec),
                                1+dp(pos,vcon+con[pos],vtec+tec[pos]));
    return memo[pos][vcon][vtec];
}

int main(){
    int n, res;
    scanf("%d", &n);

    while(n--){
        scanf("%d %d", &m, &s);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &con[i], &tec[i]);
        }

        s = s*s;
        memset(memo, -1, sizeof(memo));
        res = dp(0, 0, 0);
        if(res < inf) printf("%d\n", res);
        else printf("not possible\n");
    }

    return 0;
}


