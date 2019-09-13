#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;
//int pi[2000010],
lli res[2000010], tab[2000010];

int phi(int n) {
	int result = n;
	for(int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

void precalc(){
    //forab(i,2,2000005){
    //    pi[i] = phi(i);
    //}

    res[0] = res[1] = 0LL;
    tab[0] = tab[1] = 0LL;
    forab(i,2,2000005){
        res[i] = res[phi(i)] + 1LL;
        tab[i] = tab[i-1] + res[i];
    }
}

int main(){
    int m, n, t;
    precalc();
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &m, &n);
        printf("%lld\n", tab[n] - tab[m-1]);
    }
}


