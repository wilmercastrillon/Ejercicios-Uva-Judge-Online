#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    int n;
    int H, W, r1, r2, menL, mayR;
    double c1, c2, h;

    while(cin>>H>>W>>r1>>r2, H){
        c1 = H - (r1 + r2);
        c2 = W - (r1 + r2);
        h = sqrt(c1*c1 + c2*c2);
        menL = min(H, W);
        mayR = max(r1, r2);
        //printf("c1 %.5f, c2 %.5f, H %.5f\n", c1, c2, h);
        if(h >= (r1 + r2) && menL >= 2*mayR)
            printf("S\n");
        else{
            printf("N\n");
        }
    }
    return 0;
}


