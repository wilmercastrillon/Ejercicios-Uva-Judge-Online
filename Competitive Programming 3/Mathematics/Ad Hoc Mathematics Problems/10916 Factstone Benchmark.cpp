#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    int y, t;

    while(scanf("%d", &y), y){
        t = (y/10)-194;
        //printf("pot = %d\n", t);
        double acum = 0.0, n = 1.0;

        while(1){
            if(log2(acum + log2(n)) > t*1.0) break;
            acum += log2(n);
            n += 1.0;
        }
        printf("%.0f\n", n-1.0);
    }

    return 0;
}


