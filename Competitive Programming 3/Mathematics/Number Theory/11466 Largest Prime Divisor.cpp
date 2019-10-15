#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

int m = 10000010, primo[10000020];
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

void factCriba(lli n){
    int l, pos;
    while(n != 1LL){
        if(n >= m){//n mayor a logintud del array
            l = sqrt(n) + 1;  pos = -1;
            while(p[++pos] <= l)
                if(n%p[pos]==0LL){
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

int main(){
    //freopen("salida.txt", "w", stdout);
    criba();
    lli n;

    while(scanf("%lld", &n),n){
        if(n < 0LL) n*= -1LL;
        mapa.clear();
        factCriba(n);
        if(mapa.size() < 2) printf("-1\n");
        else printf("%lld\n", mapa.rbegin()->first);
    }

    return 0;
}


