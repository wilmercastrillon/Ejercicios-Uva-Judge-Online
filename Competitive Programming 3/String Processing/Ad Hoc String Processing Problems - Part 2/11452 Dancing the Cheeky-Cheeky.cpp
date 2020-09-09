#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

bool val(string &s, int k){
    int l = (s.size() - k) - 1;
    for(int i = l; i >= 0; i--){
        //printf("\t s[%d] = s[%d] ? k=%d\n", i, i+k, i, k);
        if(s[i] != s[i+k]) return false;
    }
    return true;
}

int main(){
    string in, aux, res;
    int n;
    cin >> n;

    while(n--){
        cin >> in;
        int ini = ceil(in.size()/3.0), p;
        forab(i, ini, in.size()){
            //printf("prueba con %d\n", i);
            if(val(in, i)){
                p = i;
                break;
            }
        }

        res = in.substr(in.size() - p);
        while(res.size() < 8){
            res.push_back(res[res.size() - p]);
        }
        if(res.size() > 8){
            res = res.substr(0, 8);
        }
        cout << res << "..." << endl;
    }

    return 0;
}


