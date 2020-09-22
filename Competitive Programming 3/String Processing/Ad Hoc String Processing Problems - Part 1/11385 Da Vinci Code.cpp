#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int fibo[110], inp[110];
map<int, int> mapa;

void pre(){
    mapa.clear();
    fibo[0] = 0; fibo[1] = 1; fibo[2] = 2;
    mapa[1] = 1; mapa[2] = 2;
    forab(i,3,110){
        fibo[i] = fibo[i-1] + fibo[i-2];
        mapa[fibo[i]] = i;
    }
}

int main(){
    pre();
    int n, t, pos;
    string cad, cad2, res, trim;
    cin >> t;

    while(t--){
        cin >> n;
        forr(i, n){
            cin >> inp[i];
        }

        //cout << "leyo in\n";
        getchar();
        getline(cin, cad);
        //cout << cad << endl;
        res = "", cad2 = "";
        res.insert(res.end(),110,' ');

        forr(i, cad.size()){
            if(cad[i] >= 'A' && cad[i] <= 'Z')
                cad2.push_back(cad[i]);
        }
        forr(i, n){
            pos = mapa[inp[i]];
            res[pos] = cad2[i];
        }

        int conl = 0;
        for(int i = res.size()-1; i >= 0; i--)
            if(res[i] == ' ') conl++;
            else break;
        if(conl > 0) res.erase(res.size()-conl, conl);
        res.erase(0, 1);

        cout << res << '\n';
    }
    return 0;
}


