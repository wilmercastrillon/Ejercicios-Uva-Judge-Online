#include <stdio.h>
#include <string.h>

int n;
int ar[20], prime[40], used[20];

void primos(){
    memset(prime, 0, sizeof(prime));
    prime[2] = prime[3] =  prime[5] = prime[37] = 1;
    prime[7] = prime[11] = prime[13] = prime[31] = 1;
    prime[17] = prime[19] =  prime[23] =  prime[29] = 1;
}

void backtraking(int tam){
    int i;
    if(tam == n){
        if(!prime[1 + ar[n-1]]) return;
        printf("%d", ar[0]);
        for(i = 1; i < n; i++) printf(" %d", ar[i]);
        printf("\n");
        return;
    }

    for(i = 1; i <= n; i++){
        if(used[i]) continue;

        if(prime[i + ar[tam - 1]]){
            ar[tam] = i;
            used[i] = 1;
            backtraking(tam + 1);
            used[i] = 0;
        }
    }
}

int main(){
    primos();
    int caso = 0;
    scanf("%d", & n);
    ar[0] = 1;

    do{
        memset(used, 0, sizeof(used));
        used[1] = 1;

        printf("Case %d:\n", ++caso);
        backtraking(1);
        if(scanf("%d", & n) != EOF) printf("\n");
        else break;
    }while(1);

    return 0;
}


