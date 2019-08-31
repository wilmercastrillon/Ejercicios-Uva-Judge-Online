#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli mcd(lli a, lli b){//algoritmo de euclides
    return a? mcd(b % a, a): b;
}

lli mcm(lli a, lli b) {
    return a*(b/mcd(a,b));
}

int main(){
    //freopen("salida.txt","w",stdout);
    lli n, res;

    while(scanf("%lld",&n), n){
        lli m = 1LL, lim = (lli) floor(sqrt(n));
        res = 0LL;
        if(n == 1LL){
            printf("1 1\n");
            continue;
        }

        vector<lli> v;
        while(m < lim){
            if(n%m == 0LL){
                v.push_back(m);
                v.push_back(n/m);
            }
            m++;
        }
        if(lim*lim == n) v.push_back(lim);
        else{
            v.push_back(lim);
            v.push_back(n/lim);
        }

        forr(i,v.size()){
            //printf("%d -> %lld\n", i, v[i]);
            forab(j,i,v.size()){
                if(mcm(v[i],v[j])==n) res++;
            }
        }

        printf("%lld %lld\n",n,res);
    }

    return 0;
}


