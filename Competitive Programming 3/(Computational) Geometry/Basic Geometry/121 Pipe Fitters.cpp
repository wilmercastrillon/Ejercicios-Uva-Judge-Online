#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    double h, w;
    int r1, r2, r3, auxmin, auxmax, res;

    while(cin >> h >> w){
        r1 = ((int) h) * ((int) w);

        auxmin = floor(w-0.5);
        auxmax = (int) w;
        //r2 = (h-1.0)/sqrt(0.75)+1.0;
        r2 = (2.0*h-2.0)/sqrt(3.0)+1.0;
        r2 = (r2>>1)*auxmin + ((r2+1)>>1)*auxmax;

        auxmin = floor(h-0.5);
        auxmax = (int) h;
        //r3 = (w-1.0)/sqrt(0.75)+1.0;
        r3 = (2.0*w-2.0)/sqrt(3.0)+1.0;
        r3 = (r3>>1)*auxmin + ((r3+1)/2)*auxmax;

        res = max(r1, r2);
        res = max(res, r3);
        if(res == r1)
            printf("%d grid\n", res);
        else printf("%d skew\n", res);
    }

    return 0;
}


