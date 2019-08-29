#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli digitos(lli n, lli k){
    return (lli) floor(log10(n*1.0)*k)+1;
}

int main(){
    lli n, p;
    double t;

    while(scanf("%lld", &p) != EOF){
        n = 3LL;
        do{
            n++;
            t = 1.0*digitos(2,n) - digitos(p,1LL)*2.0;
        }while(t <= 0.0);

        double lp = log2(p), lp1 = log2(p+1LL), l10 = log2(10);
        t = 1.0*digitos(2,n) - digitos(p,1);

        while(1){
            if(ceil(lp+log2(10.0)*t) == floor(lp1+log2(10.0)*t)) break;
            t += 1.0;
        }
        printf("%.0f\n", ceil(lp+log2(10)*t));
    }

    return 0;
}


