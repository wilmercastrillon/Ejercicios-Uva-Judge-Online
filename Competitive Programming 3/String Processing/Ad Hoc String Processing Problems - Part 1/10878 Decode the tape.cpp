#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

string n;

int main(){
    //freopen("salida.txt", "w", stdout);
    getline(cin, n);
    while(getline(cin, n)){
        if(n[0] != '|'){
            break;
        }

        char ascii = 0;
        for(int x=0, i=n.size()-2; i > 0; i--,x++){
            if(n[i] == 'o') ascii |= (1<<x);
            if(n[i] == '.') x--;
        }
        printf("%c", ascii);
    }
    return 0;
}


