#include <bits/stdc++.h>
#define inf 1000000000
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
typedef unsigned long long int ulli;

double l, n, d;

ulli mcd(ulli a, ulli b){
    return a? mcd(b %a, a): b;
}

void simp(ulli &num, ulli &den){
    ulli dividir = mcd(num, den);
    num /= dividir;
    den /= dividir;
}

int main(){
    while(scanf("%lf %lf %lf", &l, &n, &d) != EOF){
        if(d < 1.0) break;

        double a, best = 1e10, aux;
        ulli num, den;

        forab(b,1,n+1){
            a = ceil((d*b)/l);
            aux = a*l/b - d;
            if(aux < best){
                best = aux;
                num = a*l;
                den = b;
            }
        }

        simp(num, den);
        printf("%llu/%llu\n", num, den);
    }

    return 0;
}


