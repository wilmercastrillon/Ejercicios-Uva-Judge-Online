#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    double a, b, c;
    int t;
    cin >> t;

    while(t--){
        cin >> a >> b >> c;
        if(a<b+c && b<a+c && c<a+b){
            printf("OK\n");
        }else{
            printf("Wrong!!\n");
        }
    }

    return 0;
}


