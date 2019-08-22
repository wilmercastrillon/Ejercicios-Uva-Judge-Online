#include <bits/stdc++.h>

using namespace std;

int memo[1010][1010];
string cad;

int dp(int l, int r){
    if(l == r) return 1;
    if(l+1 == r){
        if(cad[l] == cad[r]) return 2;
        else return 1;
    }
    if(memo[l][r] != -1) return memo[l][r];

    if(cad[l] == cad[r])
        return memo[l][r] =  2 + dp(l+1,r-1);
    else
        return memo[l][r] =  max(dp(l,r-1),dp(l+1,r));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    getchar();

    while(t--){
        getline(cin,cad);
        if(cad.size() == 0){
            printf("0\n");
            continue;
        }
        memset(memo,-1,sizeof(memo));
        printf("%d\n", dp(0,cad.size()-1));
    }
    return 0;
}


