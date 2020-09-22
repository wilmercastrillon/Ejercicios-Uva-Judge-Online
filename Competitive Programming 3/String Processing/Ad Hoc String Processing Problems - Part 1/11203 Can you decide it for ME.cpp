#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
string target = "?M?E?";

bool solve(string &cad){
    if(cad[0] != '?') return false;
    bool m = false, e = false;
    int idx = 0, ar[3];
    ar[0] = ar[1] = ar[2] = 0;

    forab(i,0,cad.size()){
        if(cad[i] == '?'){
            ar[idx]++;
        }else if(cad[i] == 'M' && !m){
            m = true;  idx++;
        }else if(cad[i] == 'E' && !e){
            e = true;  idx++;
        }else return false;
    }

    if(!ar[0] || !ar[1] || !ar[2]) return false;
    return (ar[1] == (ar[2]-ar[0]));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int n;
    string cad;
    cin >> n;

    while(n--){
        cin >> cad;

        if(solve(cad)) cout << "theorem\n";
        else cout << "no-theorem\n";
    }
    return 0;
}


