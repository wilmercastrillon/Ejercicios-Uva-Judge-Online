#include <bits/stdc++.h>

using namespace std;
int bordes[110];

void preCalcular(string subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

int kmp(string cad, string subcad){
    int i = 0, j = 0;
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        i++; j++;
        if(j == subcad.size()){
            return cad.size();
            j = bordes[j];
        }
    }
    //printf("j = %d\n", j);
    return j;
}

int main(){
    cin.tie(NULL);
    string s1, s2;
    int t, k, w;
    cin >> t;

    while(t--){
        cin >> k >> w;
        w--;
        cin >> s1;
        int res = s1.size();
        while(w--){
            cin >> s2;
            res += s2.size();
            preCalcular(s2);
            res -= kmp(s1, s2);
            s1 = s2;
        }
        cout << res << '\n';
    }
    return 0;
}


