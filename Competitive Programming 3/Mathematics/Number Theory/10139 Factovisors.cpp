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

int getexp(lli n, lli p){//exp de p en n!
    int con = 0;
    for(lli i = p; i <= n; i*=p)
        con += n/i;
    return con;
}

int main(){
    //freopen("salida.txt","w",stdout);
    criba();
    lli n, m;

    while(scanf("%lld %lld", &n, &m) != EOF){
        mapa.clear();
        factCriba(m);

        bool res = true;
        for(auto it=mapa.begin(); it!=mapa.end(); ++it){
            if(getexp(n,it->first) < it->second){
                res = false;
                break;
            }
        }

        if(res) printf("%lld divides %lld!\n", m, n);
        else printf("%lld does not divide %lld!\n", m,n);
    }

    return 0;
}


