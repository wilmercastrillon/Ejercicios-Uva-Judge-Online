#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    double d, v, u, vt, r1, r2;
    int t, caso = 0;
    scanf("%d", &t);

    while(t--){
        scanf("%lf %lf %lf", &d, &v, &u);
        r2 = u*u - v*v;
        if(r2 <= 0.0 || u == 0.0 || v == 0.0){
            printf("Case %d: can't determine\n", ++caso);
        }else{
            r1 = d/u;
            r2 = d/sqrt(r2);
            printf("Case %d: %.3f\n", ++caso, fabs(r2-r1));
        }
    }

    return 0;
}


