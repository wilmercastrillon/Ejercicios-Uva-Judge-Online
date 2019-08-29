#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli H(int n){
    lli res = 0;
    for(int i = 1; i <= n; i=i+1 ){
        res = (res + n/i);
    }
    return res;
}

lli solve(lli n){
    if(n <= 0LL) return 0LL;
    vector<lli> v(1,0);
    int lim = sqrt(n);
    lli res = 0;

    forab(i,1,lim+1){
        res += (n/i);
        v.push_back(n/i);
        //printf("suma %d\n", n/i);
    }

    forab(i,1,v.size()-1){
        res += (v[i]-v[i+1])*i;
        //printf("suma %d * %d\n",(int)(v[i]-v[i+1]),i);
    }

    if(lim == v.back()) return res;
    //printf("+ %d\n", lim*abs(lim-v.back()));
    return res + lim*abs(lim-v.back());
}

int main(){
    //freopen("salida.txt","w",stdout);
    lli n;
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%lld", &n);
        printf("%lld\n",solve(n));
    }

    return 0;
}



