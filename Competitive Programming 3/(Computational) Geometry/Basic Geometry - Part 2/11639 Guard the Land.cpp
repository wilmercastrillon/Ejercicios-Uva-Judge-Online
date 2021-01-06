#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<int, int> ii;

int main(){
    int n, x1, y1, x2, y2;
    ii p1, p2, p3, p4;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> x1>>y1>>x2>>y2;
        p1 = ii(x1, y1);
        p2 = ii(x2, y2);
        cin >> x1>>y1>>x2>>y2;
        p3 = ii(x1, y1);
        p4 = ii(x2, y2);

        int minx=0, miny=0, maxx=1000, maxy=1000;
        minx = max(minx, p1.first);
        minx = max(minx, p3.first);
        maxx = min(maxx, p2.first);
        maxx = min(maxx, p4.first);

        miny = max(miny, p1.second);
        miny = max(miny, p3.second);
        maxy = min(maxy, p2.second);
        maxy = min(maxy, p4.second);

        int ssecure = (maxx-minx)*(maxy-miny);
        if(maxx < minx || maxy < miny)
            ssecure = 0;

        int secure = (p2.first-p1.first)*(p2.second-p1.second);
        secure += (p4.first-p3.first)*(p4.second-p3.second);
        secure -= ssecure*2;

        printf("Night %d: %d %d %d\n", i, ssecure, secure, 10000-(secure+ssecure));
    }

    return 0;
}


