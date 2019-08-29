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

lli expmod (lli b, lli e, lli m){//O(log b)
	if(!e) return 1LL;
	lli q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

lli m = 40000;
bool primo[40010];
vector<lli> p;
int lim = sqrt(m)+1;

void criba(){
    memset(primo, true, sizeof(primo));
    for(int i = 2; i < m; i++){
        if(!primo[i]) continue;
        p.push_back(i);
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = false;
    }
}

bool esPrimo(lli n){
    if(n < m) return primo[n];

    lli may = sqrt(n) + 1;
    int i = 0;
    while(p[i] <= may){
        //printf("no div entre %lld\n", p[i]);
        if(n%p[i++] == 0LL) return false;
    }
    return true;
}

int main(){
    //freopen("salida.txt","w",stdout);
    criba();
    lli n, p;

    while(scanf("%lld %lld", &p, &n), n){
        //printf("exp mod %lld | primo %d\n", expmod(n,p,p), (int) esPrimo(p));
        if(!esPrimo(p) && (expmod(n,p,p) == n))
            printf("yes\n");
        else printf("no\n");
    }

    return 0;
}


