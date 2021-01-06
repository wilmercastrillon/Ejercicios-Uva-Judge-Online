#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

const double pi = acos(-1.0);

int main(){
    double D, d, v, r, R, x;


    while(cin >> D >> v, D){
        R = D/2.0;

        x = (pow(R,3.0)*(4.0/3.0*pi)-v)/(4.0/3.0*pi);
        //printf("num %.5f\n", pow(R,3.0)*(4.0/3.0*pi)-v);
        //printf("den %.5f\n", (4.0/3.0*pi));
        r = pow(x, 1.0/3.0);

        printf("%.3f\n", r*2.0);
    }

    return 0;
}


