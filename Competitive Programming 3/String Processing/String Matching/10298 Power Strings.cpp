#include <bits/stdc++.h>

using namespace std;
int bordes[1000010], con = 0;

void preCalcular(string subcad){
    int i = 1, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

void kmp(string cad, string subcad){
    int i = 0, j = 0;
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        i++; j++;
        if(j == subcad.size()){
            con++;
            j = bordes[j];
        }
    }
}

int main(){
    string s1, s2;
    bool igual;
    char c;

    while(getline(cin, s2) && s2[0] != '.'){
        c = s2[0]; igual = true;
        for(int i = 1; i < s2.size() && igual; i++) igual = c == s2[i];
        if(igual){
            printf("%d\n", s2.size());
            continue;
        }

        s1 = s2+s2;
        con = 0;
        preCalcular(s2);
        kmp(s1, s2);
        printf("%d\n", con-1);
    }
    return 0;
}


