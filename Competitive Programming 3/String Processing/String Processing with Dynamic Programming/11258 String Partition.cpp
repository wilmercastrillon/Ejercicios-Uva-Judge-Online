#include <bits/stdc++.h>
#define inf 1000000000000000LL

using namespace std;
typedef long long int lli;

lli memo[210];
const lli lim = (1LL<<31LL)-1LL;
string cad;

lli toint(int i, int j){
    lli ans = 0;
    for(int k = i; k<=j; ++k){
        ans *= 10LL;
        ans += cad[k]-'0';
    }
    return ans;
}

lli dp(int i){
    if(i<0 || i >= cad.size()) return 0;
    if(memo[i] != -1) return memo[i];

    lli ans = -1, aux;
    if(cad.size()-i <= 10) ans = toint(i,cad.size()-1);
    if(ans > lim || ans == -1){
        ans = 0;
        for(int k = 0; k < 11; ++k){
            aux = toint(i,i+k);
            if(aux > lim) break;
            ans = max(ans, aux + dp(i+k+1));
        }
    }
    return memo[i] = ans;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> cad;
        memset(memo,-1,sizeof(memo));
        cout << dp(0) << '\n';
    }
    return 0;
}


