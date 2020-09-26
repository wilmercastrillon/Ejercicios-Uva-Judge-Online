#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

int m = 1000010, primo[1000020];
int lim = sqrt(m)+1;
map<lli, int> mapa; vector<lli> p;

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

bool esprimo(int n){
    int l, pos;
    if(n < 2) return false;

    if(n >= m){//n mayor a logintud del array
        l = sqrt(n) + 1;  pos = -1;
        while(p[++pos] <= l){
            if(n % p[pos] == 0){
                return false;
            }
        }
        return true;
    }else{
        return (primo[n] == n);
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    criba();
    lli x1, x2;

    while(cin >> x1 >> x2){
        lli c1, c2, d1, d2, mind = 1000000, maxd = 0, ant = -1;
        while(!esprimo(x1) && x1<=x2) x1++;
        ant = x1;

        for(lli i=x1+1; i <= x2; i++){
            if(esprimo(i)){
                if(mind > i-ant){
                    mind = i-ant;
                    c1 = ant;
                    c2 = i;
                }
                if(maxd < i-ant){
                    maxd = i - ant;
                    d1 = ant;
                    d2 = i;
                }
                ant = i;
            }
        }

        if(maxd == 0){
            printf("There are no adjacent primes.\n");
            continue;
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n", c1,c2,d1,d2);
    }

    return 0;
}


