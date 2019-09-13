#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

bool solve(string &s){
    int mod = 0;
    forr(i,s.size()){
        mod = (mod * 2) % 131071;
        mod = (mod + (s[i]-'0')) % 131071;
        //printf("parcial mod %d \n", mod);
    }
    return (mod == 0);
}

int main(){
    string cad, in;

    while(cin >> cad){
        if(cad.back() != '#'){
            do{
                cin >> in;
                cad = cad + in;
            }while(in.back() != '#');
        }
        cad = cad.substr(0,cad.size()-1);

        if(solve(cad)) printf("YES\n");
        else printf("NO\n");
    }
}


