#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;//metodo normal

lli mcd(lli a, lli b){
    return  a? mcd(b %a, a): b;
}

struct fraccion {
    lli num, den;

    fraccion(lli x, lli y) {
        num = x; den = y;
        if (num == 0) den = 1;
        else {
            lli dividir = mcd(num, den);
            num /= dividir;
            den /= dividir;
        }
        if (den < 0){ num *= -1;  den *= -1; }
    }

    string toString() {

    }
};

int main(){
    //freopen("salida.txt","w",stdout);
    int t;
    lli x, y, n;
    scanf("%d", &t);

    while(t--){
        scanf("%lld %lld %lld", &x, &y, &n);
        printf("%lld\n", expmod(x,y,n));
    }
    scanf("%d", &t);

    return 0;
}


