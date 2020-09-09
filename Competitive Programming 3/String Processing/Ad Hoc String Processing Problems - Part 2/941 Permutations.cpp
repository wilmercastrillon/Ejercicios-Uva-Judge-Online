#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli fact[21];

void pre(){
    fact[0] = 1;
    forab(i,1,21){
        fact[i] = fact[i-1]*i;
    }
}

int main(){
    int t, l;
    string x;
    lli n, aux;
    pre();
    cin >> t;

    while(t--){
        cin >> x;
        cin >> n;
        sort(x.begin(), x.end());
        l = x.size();
        int idx = l-1;

        string res = "";
        forr(i, l){
            aux = n/fact[idx];
            //cout << "letra en " << aux << " cad: " << x << endl;
            //cout << "agrega a " << x[aux] << '\n';
            res.push_back(x[aux]);
            x.erase(aux,1);
            n = n % fact[idx];
            idx--;
        }
        cout << res << '\n';
    }

    return 0;
}


