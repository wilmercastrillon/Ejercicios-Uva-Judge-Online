#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

struct punto{
    double x, y;
    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }
};

double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    double x, y, res, n;
    int a, m;

    while(cin >> n >> a, a>0){
        m = 0;
        punto p1(0,0), p2(a,0), p3(a,a), p4(0,a), px;

        forr(i, n){
            cin >> x >> y;
            px = punto(x,y);
            if(dist(p1,px)<=a && dist(p2,px)<=a && dist(p3,px)<=a && dist(p4,px)<=a)
                m++;
        }

        res = m*a*a/n;
        printf("%.5f\n", res);
    }

    return 0;
}


