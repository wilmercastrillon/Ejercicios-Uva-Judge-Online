#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

int m= 1000010, primo[1000020];
vector<lli> p;  int lim = sqrt(m)+1;

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

map<lli, int> factCriba(int n){
    map<lli, int> mapa;
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
    return mapa;
}

int exp_bin(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int solve(int a, int c){
    map<lli, int> mapac = factCriba(c);
    map<lli, int> mapaa = factCriba(a);
    int res = 1, b, e;

    for(auto it=mapaa.begin(); it!=mapaa.end(); ++it)
        if(mapac[it->first] < it->second) return -1;

    for(auto it=mapac.begin(); it!=mapac.end(); ++it){
        b = it->first;
        e = it->second;
        if(mapaa[b] < e) res *= exp_bin(b,e);
    }

    return res;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    criba();
    int a, c, t, res;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &a, &c);
        res = solve(a, c);
        if(res >= 0) printf("%d\n", res);
        else printf("NO SOLUTION\n");
    }

    return 0;
}


