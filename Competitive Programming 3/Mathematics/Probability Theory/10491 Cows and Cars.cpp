#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    double nv, nc, m, t, r1, r2;
    while(scanf("%lf %lf %lf", &nv, &nc, &m) != EOF){
        t = nv+nc;
        r1 = ((nc-1.0)/(t-m-1.0))*(nc/t);
        r2 = (nc/(t-m-1.0))*(nv/t);
        printf("%.5f\n", r1+r2);
    }

    return 0;
}

/*
    uva judge 10491
    Cows and Cars
    Probability Theory
*/
