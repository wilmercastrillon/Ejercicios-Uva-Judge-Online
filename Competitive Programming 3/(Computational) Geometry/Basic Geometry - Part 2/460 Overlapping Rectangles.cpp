#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    int t, ax, ay, bx, by, cx, cy, dx, dy;
    int llx, lly, rux, ruy;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        scanf("%d %d %d %d", &cx, &cy, &dx, &dy);

        llx = max(ax, cx);
        lly = max(ay, cy);
        rux = min(bx, dx);
        ruy = min(by, dy);

        if(llx >= rux || lly >= ruy){
            printf("No Overlap\n");
        }else{
            printf("%d %d %d %d\n", llx, lly, rux, ruy);
        }

        if(t) printf("\n");
    }
    return 0;
}


