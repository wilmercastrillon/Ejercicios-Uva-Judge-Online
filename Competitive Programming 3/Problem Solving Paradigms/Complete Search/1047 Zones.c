#include <stdio.h>
#include <string.h>

int matriz[25][25];
int v[25], umask[20], uvalor[20], res[25];
int n, m, may, comun, maskmax;

void backtraking(int ant, int mask, int can, int acum){
    int i;

    if(can == m){
        for(i = 0; i < comun; i++){
            if(mask & umask[i]){
                acum -= (__builtin_popcount(mask & umask[i]) - 1) * uvalor[i];
            }
        }
        if(acum > may){
            may = acum;
            maskmax = mask;
        }
        return;
    }

    for(i = ant + 1; i <= n; i++){
        backtraking(i, mask | (1<<i), can + 1, acum + v[i]);
    }
}

int main(){
    int i, j, k, q, t, x, caso = 0, aux2;

    while(scanf("%d %d", &n, &m), n || m){
        for(i = 1; i <= n; i++) scanf("%d", &v[i]);
        scanf("%d", &comun);
        int mask;

        for(j = 0; j < comun; j++){
            scanf("%d", &t);
            mask = 0;
            for(k = 0; k < t; k++) scanf("%d", &aux2), mask |= 1<<aux2;
            scanf("%d", &x);
            umask[j] = mask;
            uvalor[j] = x;
        }

        may = 0;
        backtraking(0, 0, 0, 0);
        printf("Case Number  %d\n", ++caso);
        printf("Number of Customers: %d\n", may);
        printf("Locations recommended:");
        for(i = 1; i <= n; i++){
            if(maskmax & (1 << i))
                printf(" %d", i);
        }
        printf("\n\n");
    }

    return 0;
}


