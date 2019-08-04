#include <stdio.h>

using namespace std;

double f(double n){
    return (9.0/5.0)*n + 32.0;
}

double c(double n){
    return (5*n-160.0)/9.0;
}

int main(){
    int t, caso = 0;
    double a, b, aux;
    scanf("%d", &t);

    while(t--){
        scanf("%lf %lf", &a, &b);
        aux = f(a) + b;
        printf("Case %d: %.2f\n", ++caso, c(aux));
    }
}


