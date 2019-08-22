#include <bits/stdc++.h>
#define inf 1000000000
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

string cad;
int memo[90][90];

bool igual(int i1, int i2, int l){
    forab(k,0,l)
        if(cad[i1+k] != cad[i2+k])
            return false;
    return true;
}

int dp(int i, int j){
    if(i == j) return 1;
    if(i<0 || i>=cad.size() || i>j) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    //printf("Para (%d %d) %s\n",i,j,cad.substr(i,(j-i)+1).c_str());

    int ans = (j-i)+1, con, lim = (j-i), k;
    for(int l = 1; l <= lim; ++l){
        con = 0;
        for(k = i; k+l <= (j+1); k+=l){
            if(igual(i,k,l)) con++;
            else break;
        }
        //printf("\t l=%s aparece %d\n",cad.substr(i,l).c_str(),con);
        ans = min(ans, min(l,dp(i,i+l-1)) + dp(i+l*con,j));
    }
    //printf("res para(%d %d) %s = %d\n",i,j,cad.substr(i,(j-i)+1).c_str(),ans);
    return memo[i][j] = ans;
}

int main(){
    while(getline(cin,cad)){
        if(cad == "*") break;
        memset(memo,-1,sizeof(memo));
        printf("%d\n", dp(0,cad.size()-1));
    }
    return 0;
}


