#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ulli;

ulli matriz[61], lim;
int may, n, con;

void backTraking(ulli used, int cant, int pos){
    if(used == lim){
        con++;
        may = max(may, cant);
        //printf("solucion %d %d %d\n", used, cant, pos);
        return;
    }

    for(int i = pos; i < n; i++){
        if(used&((ulli) 1<<i)) continue;
        //printf("llamado con %d\n", i);
        backTraking(used|matriz[i], cant+1, i+1);
    }
}

int main(){
    int m, t, x, y;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        may = con = 0;
        lim = (1LL<<n)-1LL;

        for(int i = 0; i < n; i++)
            matriz[i] = (ulli) 1<<i;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            matriz[x] |= (ulli) 1 << y;
            matriz[y] |= (ulli) 1 << x;
        }

        backTraking(0, 0, 0);
        printf("%d\n%d\n", con, may);
    }

    return 0;
}


