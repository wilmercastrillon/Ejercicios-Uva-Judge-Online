#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int caso = 1;

    while(cin >> s){
        if(s == "end") break;

        vector<char> vc(26, 'a');
        int j, res = 0;
        for(int i = 0; i < s.size(); i++){
            for(j = 0; j < 26; j++){
                res = max(res, j);
                if(vc[j] >= s[i]){
                    vc[j] = s[i];
                    break;
                }
            }
        }

        printf("Case %d: %d\n", caso++, res + 1);
    }

    return 0;
}
