#include <stdio.h>
#include <string.h>

int res[10010][10];

void calc(){
    int i, aux, j;
    memset(res, 0, sizeof(res));

    for(i = 1; i < 10001; ++i){
        for(j = 0; j < 10; j++)
            res[i][j] = res[i-1][j];

        aux = i;
        while(aux){
            res[i][aux%10]++;
            aux /= 10;
        }
    }
}

int main(){
    calc();
    int t, n, j;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        for(j = 0; j < 9; j++){
            printf("%d ", res[n][j]);
        }
        printf("%d\n", res[n][9]);
    }

    return 0;
}


