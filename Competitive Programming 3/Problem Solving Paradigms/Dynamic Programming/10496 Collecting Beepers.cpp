#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int n, may;
int tab[12][2], memo[12][1<<12];

int dist(int f, int c){
    return abs(tab[f][0]-tab[c][0]) +
            abs(tab[f][1]-tab[c][1]);
}

int tsp(int pos, int mask){
    if(mask == may) return dist(pos, 0);
    if(memo[pos][mask] != -1) return memo[pos][mask];

    int res = 1000000000;
    for(int i = 1; i <= n; i++){
        if(!(mask&(1<<i)))
            res = min(res, dist(i, pos) + tsp(i, mask|(1<<i)));
    }
    return memo[pos][mask] = res;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos, q, w;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d %d", &q, &w);
        scanf("%d %d", &tab[0][0], &tab[0][1]);
        scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            scanf("%d %d", &tab[i][0], &tab[i][1]);
            //cout << "se le " << tab[i][0] << " , " << tab[i][1] << endl;
        }

        may = (1<<(n+1))-1;
        memset(memo, -1, sizeof(memo));
        printf("The shortest path has length %d\n", tsp(0, 1));
    }

    return 0;
}


