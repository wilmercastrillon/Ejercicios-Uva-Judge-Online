#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
//typedef long long int lli;

int m = 1000010, primo[1000020];
vector<int> p;  int lim = sqrt(m)+1;
map<int, int> mapa;

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

int numdiv(int n){
    mapa.clear();
    factCriba(n);

    int cant = 1;
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        cant *= ((it->second)+1);
    }
    return cant;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    criba();
    int n, l, u, mejor, num, x;
    cin >> n;

    while(n--){
        cin >> l >> u;
        mejor = 0;
        for(int i = l; i <= u; i++){
            x = numdiv(i);
            if(mejor < x){
                mejor = x;
                num = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,num,mejor);
    }

    return 0;
}


