#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int m = 10010, acum[33330];
bool primo[10015];
vector<int> p;
int lim = sqrt(m)+1;

void criba(){
    memset(primo, true, sizeof(primo));
    acum[0] = 0;

    for(int i = 2; i < m; i++){
        if(!primo[i]) continue;
        p.push_back(i);
        acum[p.size()] = acum[p.size()-1] + i;
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = false;
    }
}

int contar(int n){
    int acum = 0, res = 0, posl=0, posf=0;
    //printf("p.size() %u\n", p.size());

    while(posl < p.size() && p[posl] <= n){
        //printf("acum ini = %d\n", acum);
        while(acum > n && posl < p.size()){
            acum -= p[posl++];
        }

        //printf("acum resta = %d\n", acum);
        while(acum < n && posf < p.size()){
            acum += p[posf++];
        }

        if(acum == n){
            res++;
            acum -= p[posl++];
        }
        //printf("##### acum final = %d [%d | %d]\n", acum, p[max(0,posl-1)],p[posf-1]);
    }
    return res;
}

int main(){
    //freopen("salida.txt","w",stdout);
    criba();
    int n;

    while(scanf("%d", &n),n){
        printf("%d\n", contar(n));
    }

    return 0;
}


