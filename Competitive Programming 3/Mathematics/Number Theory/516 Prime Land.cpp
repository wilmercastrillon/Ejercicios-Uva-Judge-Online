#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli mcd(lli a, lli b){//algoritmo de euclides
    return  a? mcd(b %a, a): b;
}

lli mulmod(lli a, lli b, lli c) {
	lli x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

lli expmod (lli b, lli e, lli m){//O(log b)
	if(!e) return 1;
	lli q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

bool es_primo_prob(lli n, int a) {
	if (n == a) return true;
	lli s = 0,d = n-1;
	while (d % 2 == 0) s++,d/=2;

	lli x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;

	for(int i = 0; i < s-1; i++){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}

bool rabin (lli n){ //devuelve true si n es primo
	if (n == 1)	return false;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	for(int j = 0; j < 9; j++)
		if (!es_primo_prob(n,ar[j]))
			return false;
	return true;
}

lli rho(lli n){
    if( (n & 1) == 0 ) return 2;
    lli x = 2 , y = 2 , d = 1;
    lli c = rand() % n + 1;
    while( d == 1 ){
        x = (mulmod( x , x , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        if( x - y >= 0 ) d = mcd( x - y , n );
        else d = mcd( y - x , n );
    }
    return d==n? rho(n):d;
}

map<lli, lli> mapa;

void factRho(lli n){ //O (lg n)^3. un solo numero
	if (n == 1) return;
	if (rabin(n)){
		mapa[n]++;
		return;
	}
	lli factor = rho(n);
	factRho(factor);
	factRho(n/factor);
}

lli expbin(lli a, lli n) {
	lli res = 1;
	while (n) {
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main(){
    lli n, k, p;
    string str;

    while(getline(cin, str)){
        istringstream ss(str);

        ss >> p;
        if(p == 0) break;
        ss >> k;
        n = expbin(p,k);
        while(ss >> p){
            ss >> k;
            n *= expbin(p,k);
        }

        //printf("leyo %lld\n", n);
        mapa.clear();
        factRho(n-1LL);
        bool l = false;
        for(auto it=mapa.rbegin(); it!=mapa.rend(); ++it){
            if(l) printf(" %lld %d", it->first, it->second);
            else{
                printf("%lld %d", it->first, it->second);
                l = true;
            }
        }
        printf("\n");
    }

    return 0;
}


