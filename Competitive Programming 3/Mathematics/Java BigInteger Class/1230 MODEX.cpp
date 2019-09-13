#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;//metodo normal

lli mulmod (lli a, lli b, lli c) {
	lli x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

lli expmod(lli b, lli e, lli m){//O(log b)
	if(!e) return 1LL;
	lli q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

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


