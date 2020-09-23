#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    //cin.tie(NULL);
    string cad1, cad2, res;

    while(getline(cin, cad1)){
        getline(cin, cad2);
        sort(cad1.begin(), cad1.end());
        sort(cad2.begin(), cad2.end());

        res = "";
        int idx1 = 0, idx2 = 0;
        while(idx1 < cad1.size() && idx2 < cad2.size()){
            if(cad1[idx1] == cad2[idx2]){
                res.push_back(cad1[idx1]);
                idx1++;  idx2++;
            }else if(cad1[idx1] > cad2[idx2]){
                idx2++;
            }else{
                idx1++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}


