#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef unsigned long long int ulli;

ulli dp[30][200];
bool ok[30][200];

ulli mcd(ulli a,ulli b){return a? mcd(b%a,a): b;}

ulli backt(int nivel, int val){
    if(nivel == 0){
        if(val > 0) return 0;
        return 1;
    }
    if(ok[nivel][val])
        return dp[nivel][val];

    ulli ans = 0;
    forab(i,1,7){
        ans += backt(nivel-1, val-i);
    }
    ok[nivel][val] = true;
    return dp[nivel][val] = ans;
}

int main(){
    int n, x;
    while(scanf("%d %d", &n, &x), n){
        memset(ok, false, sizeof(ok));
        ulli num = backt(n, x);
        ulli den = 1LL;
        forr(i, n) den *= 6LL;

        ulli _gcd = mcd(num, den);
        num /= _gcd;
        den /= _gcd;

        if(den != 1LL) printf("%llu/%llu\n", num, den);
        else printf("%lld\n", num);
    }
    return 0;
}


