#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;
typedef long long int tdato;
tdato base = 1000000000;

struct biginteger{
    vector<tdato> num;
    bool signo;

    void iniciar(int n){
        num.clear();
        signo = n >= 0; n = abs(n);
        while(n){
            num.push_back((n >= base)? n % base: n);
            n /= base;
        }
    }

    void quitar_zeros_izq(){
        while(num.size() && !num.back()) num.pop_back();
    }

    void imprimir(){
        printf("%d", ((num.size())? num.back(): 0));
        for(int i = num.size() - 2; i >= 0; i--)
            printf("%09d", num[i]);
        printf("\n");
    }

    biginteger suma(biginteger b){
        ulli carry = 0, aux;
        int l = max(b.num.size(), num.size());
        biginteger c;

        for(int i = 0; i < l || carry; i++){
            aux = carry;
            if(i < b.num.size()) aux += b.num[i];
            if(i < num.size()) aux += num[i];

            if(aux >= base){
                c.num.push_back(aux % base);
                carry = aux / base;
            }else{
                c.num.push_back(aux);
                carry = 0;
            }
        }
        return c;
    }

    int comparar(biginteger b){//este es: 1 mayor, 0 igual, -1 menor
        if(num.size() > b.num.size()) return 1;
        else if(num.size() < b.num.size()) return -1;
        else{
            for(int i = num.size() - 1; i >= 0; i--){
                if(num[i] > b.num[i]) return 1;
                else if(num[i] < b.num[i]) return -1;
            }
            return 0;
        }
    }
};

typedef biginteger bigint;
/*bigint operator<<(bigint &a, bigint &b){
    bigint c;
    c.signo = b.signo;
    c.num.assign(b.num.begin(), b.num.end());
    return c;
}*/
bigint operator<<(bigint &a, int b){
    a.iniciar(b);
    return a;
}
bigint operator+(bigint &a, bigint&b){
    bigint c;
    c.signo = true;
    c = a.suma(b);
    return c;
}

bigint fibo[1010f];

void pre(){
    fibo[0] << 1;
    fibo[1] << 2;
    for(int i = 2; i < 1001; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main(){
    pre();
    int n;

    while(scanf("%d", &n) != EOF){
        fibo[n].imprimir();
    }

    return 0;
}


