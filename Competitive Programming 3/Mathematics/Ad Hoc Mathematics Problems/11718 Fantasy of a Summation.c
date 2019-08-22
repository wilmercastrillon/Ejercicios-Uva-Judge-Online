#include <stdio.h>
#include <math.h>

typedef long long int lli;
lli a[1010];

lli mulmod(lli a, lli b, lli c){//(a*b) % c
    lli x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

lli expmod(lli b, lli e, lli m){//O(log b)
	if(!e) return 1;
	lli q = expmod(b,e/2,m);
	q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    lli t, n, k, mod, aux, i, res, caso = 0;
    scanf("%lld",&t);

    while(t--){
        scanf("%lld %lld %lld", &n,&k,&mod);
        for(i = 0; i < n; ++i) scanf("%lld", &a[i]);

        aux = (expmod(n,k-1LL,mod)*k) % mod;
        res = 0LL;
        for(i = 0; i < n; ++i){
            res = (res + mulmod(aux,a[i],mod)) % mod;
            //printf("aux*ai = %I64d | res = %I64d\n", mulmod(aux,a[i],mod), res);
        }

        printf("Case %I64d: %I64d\n", ++caso, res);
    }
    return 0;
}


