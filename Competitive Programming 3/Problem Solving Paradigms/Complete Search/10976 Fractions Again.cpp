#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

struct fraccion {
    lli num, den;

    void iniciar(lli x, lli y) {
        num = x;
        den = y;
    }

    fraccion restar(fraccion b) {
        fraccion c;
        c.num = num * b.den - b.num * den;
        c.den = den * b.den;
        return c.simplificar();
    }

    lli mcd(lli a, lli b){
        return  a? mcd(b %a, a): b;
    }

    fraccion simplificar() {
        fraccion c;
        c.num = num;
        c.den = den;
        if (c.den < 0) {
            c.num *= -1;
            c.den *= -1;
        }
        if (c.num == 0) {
            c.den = 1;
        } else {
            lli dividir = mcd(c.num, c.den);
            c.num /= dividir;
            c.den /= dividir;
        }
        return c;
    }

    bool negativo(){
        return num < 0 || den < 0;
    }
};

typedef pair<fraccion, fraccion> ff;

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int k, l;
    while(scanf("%d", &k) != EOF){
        fraccion c;
        c.iniciar(1, k);
        vector<ff> res;
        l = k << 1;

       for(lli i = k + 1; i <= l; i++){
            fraccion q;
            q.iniciar(1, i);
            fraccion w = c.restar(q);
            if(w.num != 1) continue;
            if(q.restar(w).negativo()) break;
            res.push_back(ff(w, q));
        }

        printf("%d\n", res.size());
        for(int i = 0; i < res.size(); i++){
            printf("1/%d = 1/%lld + 1/%lld\n", k, res[i].first.den, res[i].second.den);
        }
    }

    return 0;
}


