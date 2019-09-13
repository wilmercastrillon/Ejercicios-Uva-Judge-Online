#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int m = 1000005, pre[1000010];
int mu[1000005], M[1000005];
bool primo[1000005];
vector<int> p;
int lim = sqrt(m)+1;

void criba(){
    memset(primo, true, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(!primo[i]) continue;
        p.push_back(i);
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = false;
    }
}

void preCalc(){
    memset(pre,0,sizeof(pre));
    pre[1] = 0;
    set<int> s;
    vector<int> next;

    forab(i,0,p.size()){
        int x, aux;
        for(auto it=s.begin(); it!=s.end(); ++it){
            x = *it;
            aux = x*p[i];
            if(aux > m) break;
            pre[aux] = pre[x] + 1;
            next.push_back(aux);
        }
        forr(i,next.size()) s.insert(next[i]);
        next.clear();
        s.insert(p[i]);
        pre[p[i]] = 1;
    }

    mu[1] = M[1] = 1;
    forab(i,2,m){
        if(pre[i] == 0) mu[i] = 0;
        else if(pre[i]&1) mu[i] = -1;
        else mu[i] = 1;
        M[i] = mu[i] + M[i-1];
    }
}

int main(){
    criba();
    preCalc();
    int n;

    while(scanf("%d", &n), n){
        printf("%8d %7d %7d\n", n, mu[n], M[n]);
    }

    return 0;
}


