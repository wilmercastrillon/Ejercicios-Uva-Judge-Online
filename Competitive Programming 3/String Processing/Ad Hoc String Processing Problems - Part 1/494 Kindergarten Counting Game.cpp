#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    string cad, expresion = "[a-zA-Z]+";
    regex reg("[a-zA-Z]+");

    while(getline(cin,cad)){
        int con = 0;
        smatch matches;
        while(regex_search(cad, matches, reg)){
            cad = matches.suffix();
            con++;
        }
        printf("%d\n", con);
    }

    return 0;
}


