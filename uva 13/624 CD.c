#include <stdio.h>

int ar[25];
int may, mask;

void solve(int n, int lim){
    int i, j, l = 1 << n, acum;
    may = 0;

    for(i = 0; i < l; i++){
        acum = 0;
        for(j = 0; j < n; j++){
            if(i & (1 << j)){
                acum += ar[j];
                if(acum > lim) j = n;
            }
        }
        if(acum > may && acum <= lim){
            may = acum;
            mask = i;
        }
    }
}

int main(){
    int n, i, c;

    while(scanf("%d", &n) != EOF){
        scanf("%d", &c);

        for(i = 0; i < c; i++) scanf("%d", &ar[i]);
        solve(c, n);

        for(i = 0; i < c; i++)
            if(mask & (1 << i)) printf("%d ", ar[i]);

        printf("sum:%d\n", may);
    }

    return 0;
}


