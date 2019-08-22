#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)
#define MAX 10000010LL

using namespace std;
typedef long long int lli;
vector<lli> f, c;

void llenar(){
    f.push_back(-1LL);
    f.push_back(1LL);
    lli n = 2LL;
    while(f.back() < MAX){
        if(n&1LL) f.push_back(f.back()+1LL);
        else f.push_back((n*(n+1LL))/2LL);
        n++;
    }

    c.push_back(-1LL);
    c.push_back(1LL);
    n = 2LL;
    while(c.back() < MAX){
        if(n&1LL) c.push_back((n*(n+1LL))/2LL);
        else c.push_back(c.back()+1LL);
        n++;
    }
}

int main(){
    llenar();
    lli n, diag, posf, posc, fila, col;

    while(scanf("%lld", &n) != EOF){
        posf = lower_bound(f.begin(),f.end(),n) - f.begin();
        posc = lower_bound(c.begin(),c.end(),n) - c.begin();
        diag = min(posf, posc);

        fila = diag - abs(f[diag] - n);
        col = diag - abs(c[diag] - n);
        printf("TERM %lld IS %lld/%lld\n", n,fila,col);
    }

    return 0;
}


