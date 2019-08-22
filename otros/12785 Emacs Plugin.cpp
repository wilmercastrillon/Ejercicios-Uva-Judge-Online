#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)

using namespace std;
int bordes[100010];

void algoritmoBordes(string &subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

int i, j;
bool kmp(string &cad, string &subcad){
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        i++; j++;
        if(j == subcad.size()){
            return true;
            //j = bordes[j];
        }
    }
    return false;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string t, p, x;

    while(cin >> n){
        cin >> t;
        bool res;

        forr(k, n){
            i = 0;
            res = true;
            cin >> p;
            //cout << "### llega " << p << endl;
            stringstream ss(p);
            while(getline(ss, x, '*') && res){
                if(!x.size()) continue;
                //cout << "probamos " << x << endl;
                algoritmoBordes(x);
                j = 0;
                res = res && kmp(t,x);
            }
            if(res) cout << "yes\n";
            else cout << "no\n";
        }

    }

    return 0;
}


