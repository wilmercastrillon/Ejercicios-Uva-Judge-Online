#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
//typedef long long int lli;

int phi(int n) {
    int result = n;
    for(int i=2; i*i<=n; ++i)
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            result -= result / i;
        }
    if(n > 1) result -= result / n;
    return result;
}

int main(){
    int n;

    while(scanf("%d", &n), n){
        printf("%d\n",phi(n));
    }

    return 0;
}


