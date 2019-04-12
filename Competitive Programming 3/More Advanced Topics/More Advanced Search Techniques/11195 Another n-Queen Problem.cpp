#include <stdio.h>
#include <string.h>

using namespace std;

char tab[20][20];
int val[20];
int lim, con = 0, n;

void backTraking(int up, int down, int right, int col){
    //printf("%d %d %d\n", up, down, right);
    if(right == 0){
        con++;
        return;
    }

    int aux = right, lsb;
    //printf("para numero %d\n", right);
    while(aux){
        lsb = aux&(-aux);
        //printf("pos %d con aux = %d\n", lsb, aux);
        aux ^= lsb;
        if(lsb&(up|down|val[col])) continue;
        backTraking((up|lsb)<<1, (down|lsb)>>1, right^lsb, col+1);
    }
}

int main(){
    int caso = 0;
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++)
            scanf("%s", &tab[i]);

        memset(val, 0, sizeof(val));
        for(int j = 0; j < n; j++)
            for(int i = 0; i < n; i++){
                if(tab[i][j]=='*') val[j] |= (1<<i);
            }

        lim = (1<<n)-1;
        con = 0;
        backTraking(0, 0, lim, 0);
        printf("Case %d: %d\n", ++caso, con);
    }


    return 0;
}


