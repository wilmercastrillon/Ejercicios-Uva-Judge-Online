#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int n;

int f(int x){
    return ((x*x) % 1000000) / 100;
}

void floydCycleFinding(int x0, int &mu, int &lambda) {
    int tortoise = f(x0), hare = f(f(x0));
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
    while(scanf("%d", &n), n){
        int mu, lambda;
        floydCycleFinding(n, mu, lambda);
        printf("%d\n", mu + lambda);
    }
    return 0;
}


