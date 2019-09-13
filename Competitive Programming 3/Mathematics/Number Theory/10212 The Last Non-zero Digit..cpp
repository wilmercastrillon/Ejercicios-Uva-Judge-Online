#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef __int128 lli;

int lastDigit(int n, int m){
    lli mod = (lli) 1000000000000, last = (lli) 1, d = (lli) 10;

    forab(i,n,m){
        last = (lli) last * i;
        while(last%d==0) last /= (lli) 10;
        last = last % mod;
    }
    return (last % 10);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF){
        printf("%d\n", lastDigit((n-m)+1, n+1));
    }
}



