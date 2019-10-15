#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int m = 1010, primo[1020], pre[1010];
vector<int> p;
int lim = sqrt(m)+1;
map<int, int> mapa;

void criba(){
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        primo[i] = i;
        p.push_back(i);
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

int exp_bin(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) res *= a;
		a *= a;  n >>= 1;
	}
	return res;
}


void preCalc(){
    memset(pre,-1,sizeof(pre));
    pre[1] = 1;

    forab(i,2,1001){
        mapa.clear();
        factCriba(i);

        int acum = 1, p, a;
        for(auto it=mapa.begin(); it!=mapa.end(); ++it){
            p = it->first;  a = it->second;
            acum *= (exp_bin(p,a+1)-1)/(p-1);
        }

        //printf("suma div %d = %d\n", i, acum);
        if(acum <= 1000) pre[acum] = i;
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    criba();
    preCalc();
    int n, t = 0;

    while(scanf("%d", &n), n){
        printf("Case %d: %d\n", ++t, pre[n]);
    }

    return 0;
}


