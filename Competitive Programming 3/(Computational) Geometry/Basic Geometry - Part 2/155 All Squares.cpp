#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int check(int x, int k){
    int center = 1024, low, up;
    int mask = 0, level = 0;
    while(k >= 1){
        low = center-k;
        up = center+k;
        if(x >= low && x <= up){
            mask |= (1<<level);
            //printf("esta en el nivel %d, (%d - %d)\n", level, low, up);
        }
        if(x < center)
            center = low;
        else
            center = up;
        k >>= 1;
        level++;
    }
    return mask;
}

int main(){
    int k, x, y;
    while(cin >> k >> x >> y, k){

        int mask1 = check(x, k);
        int mask2 = check(y, k);
        int res =  __builtin_popcount(mask1&mask2);

        printf("%3d\n", res);
    }

    return 0;
}


