#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli n, a, b;

lli f(lli x){
    return (a*((x*x) % n) + b) % n;
}

void floydCycleFinding(lli x0, int &mu, int &lambda) {
    lli tortoise = f(x0), hare = f(f(x0));
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    mu = 0; hare = x0;
    while (tortoise != hare){
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    lambda = 1;  hare = f(tortoise);
    while (tortoise != hare){
        hare = f(hare);
        lambda++;
    }
}

int main(){
    while(scanf("%lld", &n), n){
        scanf("%lld %lld", &a, &b);
        int mu, lambda;

        floydCycleFinding(0, mu, lambda);
        printf("%d\n", n - lambda);
    }
    return 0;
}


