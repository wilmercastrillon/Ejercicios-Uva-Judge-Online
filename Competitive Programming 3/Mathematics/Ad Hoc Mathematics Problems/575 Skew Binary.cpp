#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli solve(string cad){
    lli n = 0LL, aux;
    reverse(cad.begin(),cad.end());

    forab(i,1,cad.size()+1){
        aux = (lli) (cad[i-1]-'0');
        n += aux*((1LL<<i)-1LL);
        //printf("n = %lld\n", n);
    }
    return n;
}

int main(){
    string n;

    while(cin >> n){
        if(n=="0") break;
        printf("%lld\n", solve(n));
    }

    return 0;
}


