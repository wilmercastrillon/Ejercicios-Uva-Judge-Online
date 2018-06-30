#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;
typedef long long int lli;

int m = 1000010, m2 = 1000000;
int primo[1000020];
vector<lli> p;

void criba(){
    memset(primo, 0, sizeof(primo));
    primo[1] = 1;

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        p.push_back(i);
        primo[i] = i;
        if(i > 1000) continue;

        for(int j = i*i; j < m; j += i){
            primo[j] = i;
        }
    }
}

map<lli, int> mapa;

void fact(lli n){
    int l;
    bool s;

    while(n != 1){
        if(n > m2){
            l = sqrt(n) + 1;
            s = false;
            for(int i = 0; p[i] <= l; i++){
                if(n % p[i] == 0){
                    mapa[p[i]]++;
                    s = true;
                    n /= p[i];
                    break;
                }
            }
            if(!s){
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
    criba();
    lli n;
    int casos;
    scanf("%d", &casos);

    while(casos--){
        scanf("%lld", &n);
        mapa.clear();
        fact(n);
        map<lli, int>::iterator it;
        lli p, a, acum = 1;

        for(it = mapa.begin(); it != mapa.end(); it++){
            p = it->first;
            a = it->second;

            acum *= ((pow(p, a + 1) - 1) / (p - 1));
            //printf("%d\n", pow(p, a + 1));
        }
        acum -= n;

        if(acum == n) printf("perfect\n");
        else if(acum > n) printf("abundant\n");
        else printf("deficient\n");
    }

    return 0;
}


