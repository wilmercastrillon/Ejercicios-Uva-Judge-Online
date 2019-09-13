#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

typedef long long int lli;

int m = 1000010, primo[1000020];
vector<lli> p;  int lim = sqrt(m)+1;
map<lli, int> mapa;

void criba(){
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        p.push_back(i);
        primo[i] = i;
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = i;
    }
}

void factCriba(int n){
    int l, pos;
    while(n != 1){
        if(n >= m){//n mayor a logintud del array
            l = sqrt(n) + 1;  pos = -1;
            while(p[++pos] <= l)
                if(n%p[pos]==0){
                    mapa[p[pos]]++;
                    n /= p[pos];
                    break;
                }
            if(p[pos] > l){
                mapa[n]++;
                break;
            }
        }else{
            mapa[primo[n]]++;
            n /= primo[n];
        }
    }
}

lli exp_bin(lli a, lli n) {
	lli res = 1;
	while (n) {
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

lli maxpow(lli n, lli b){
    int exp = 0;
    while(exp_bin(b,exp) <= n) exp++;
    return exp - 1;
}

int solve(lli n){
    lli res = 1, aux;
    int pos = -1;
    while(p[++pos] <= n){
        aux = (lli) maxpow(n, p[pos]);
        res = res*exp_bin(p[pos],aux);
        while(res%10LL==0LL) res /= 10LL;
        res = res % 1000000000LL;
        //printf("en %lld cabe %lld exp %lld | res %lld\n", n, p[pos], aux, res);
    }
    return res % 10;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    criba();
    int n;

    while(scanf("%d", &n),n){
        printf("%d\n", solve(n));
    }

    return 0;
}


