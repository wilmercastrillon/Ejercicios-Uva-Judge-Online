#include <stdio.h>
#include <math.h>

typedef unsigned long long int ulli;

int main(){
    int n, m, suma, caso = 1;
    while(scanf("%d", &n), n){
         m = n - 1;
         suma = (m*(m+1)) >> 1;

        printf("Case %d: %d\n", caso++, suma/m);
    }

    return 0;
}


