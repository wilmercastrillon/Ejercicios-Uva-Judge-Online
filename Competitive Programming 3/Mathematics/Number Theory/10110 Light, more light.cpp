#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

int m = 1000010, primo[1000020];
vector<int> p;
int lim = sqrt(m)+1;
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
                if(n % p[pos] == 0){
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

lli cantdiv(lli n){
    mapa.clear();
    factCriba(n);
    lli con = 1;
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        con *= ((it->second)+1LL);
    }
    return con;
}

int main(){
    criba();
    lli n;

    while(scanf("%lld", &n), n){
        lli q = cantdiv(n);
        //printf("%lld\n", q);
        if(q % 2LL) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}


