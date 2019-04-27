#include <stdio.h>

int calc(int i){
    int lim, sum = 0, j;
    lim = i/2 + 1;

    for(j = 1; j < lim; ++j){
        if(i % j == 0){
            sum += j;
        }
    }

    return sum;
}

int main(){
    int n, aux;

    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n), n){
        aux = calc(n);
        if(aux == n) printf("%5d  PERFECT\n", n);
        else if(aux < n) printf("%5d  DEFICIENT\n", n);
        else printf("%5d  ABUNDANT\n", n);
    }
    printf("END OF OUTPUT\n");

    return 0;
}


