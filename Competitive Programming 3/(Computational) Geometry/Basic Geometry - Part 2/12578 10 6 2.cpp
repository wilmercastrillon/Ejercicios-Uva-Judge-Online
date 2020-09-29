#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    int t;
    double l, h, r, areaT, pi = acos(-1.0);
    scanf("%d", &t);

    while(t--){
        scanf("%lf", &l);
        r = 2.0*l/10.0;
        h = 6.0*l/10.0;
        areaT = l*h;
        printf("%.2f %.2f\n", pi*r*r, areaT-pi*r*r);
    }
    return 0;
}


