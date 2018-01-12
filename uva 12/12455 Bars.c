#include <stdio.h>

int ar[25];
int tam, n;

int solve(){
    int i, j, l = 1 << tam, acum;

    for(i = 0; i < l; i++){
        acum = 0;
        for(j = 0; j < tam; j++){
            if(i & (1 << j)){
                acum += ar[j];
            }
        }
        if(acum == n) return 1;
    }
    return 0;
}

int main(){
    int casos, i;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        scanf("%d", &tam);
        for(i = 0; i < tam; i++)
            scanf("%d", &ar[i]);

        if(solve()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

