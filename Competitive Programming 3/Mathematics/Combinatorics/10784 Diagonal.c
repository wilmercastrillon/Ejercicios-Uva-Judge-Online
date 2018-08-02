#include <stdio.h>
#include <math.h>

int main(){
    long long int n;
    int caso = 1;
    long double h;

    while(scanf("%lld", &n), n){
        h = (long double) n*8;
        long double res = (3+sqrt(9+h))/2;
        printf("Case %d: %.0f\n", caso++, ceil((double)res));
    }

    return 0;
}


