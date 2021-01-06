#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

//XXXX
double large(double x, double y){
    y /= 4.0;
    return min(x, y);
}

//XX
//XX
double grouped(double x, double y){
    return min(x/2, y/2);
}

int main(){
    int n;
    double x, y;

    while(cin >> n, n){
        double best = 0, auxbest;
        int idx = -1;

        forr(i, n){
            cin >> x >> y;
            auxbest = 0;
            auxbest = max(auxbest, large(x, y));
            auxbest = max(auxbest, large(y, x));
            auxbest = max(auxbest, grouped(x, y));
            if(best < auxbest){
                best = auxbest;
                idx = i+1;
            }
        }
        printf("%d\n", idx);
    }
    return 0;
}


