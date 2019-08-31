#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    //freopen("salida.txt","w",stdout);
    int n, x1, x2;

    while(scanf("%d", &x1),x1){
        int res = 0;

        while(scanf("%d", &x2),x2){
            res = __gcd(x2-x1,res);
            x1 = x2;
        }

        printf("%d\n", abs(res));
    }

    return 0;
}


