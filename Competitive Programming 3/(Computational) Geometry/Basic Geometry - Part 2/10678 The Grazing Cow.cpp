#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    int t;
    double d, l, pi = 2.0*acos(0);
    scanf("%d", &t);

    while(t--){
        scanf("%lf %lf", &d, &l);
        double alt = sqrt((l/2.0)*(l/2.0) - (d/2.0)*(d/2.0) );
        printf("%.3f\n", pi*alt*(l/2.0));
    }
    return 0;
}


