#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<int, int> dd;
typedef pair<dd, dd> rec;
vector<rec> poly;

int main(){
    int t, n;
    int x1, y1, x2, y2;
    cin >> t;

    forr(cases, t){
        int minx = -20000, miny = -20000, maxx = 20000, maxy = 20000;
        cin >> n;
        forr(i, n){
            cin >> x1 >> y1 >> x2 >> y2;
            poly.pb(rec(dd(x1,y1), dd(x2,y2)));
        }

        forr(i, n){
            dd lowf = poly[i].first;//min x , min y
            dd upr = poly[i].second;//max x, max y

            minx = max(minx, lowf.first);
            miny = max(miny, lowf.second);
            maxx = min(maxx, upr.first);
            maxy = min(maxy, upr.second);
        }
        //printf("rectangle X(%d to %d) Y(%d to %d)\n", minx, maxx, miny, maxy);
        int area = (maxx - minx) * (maxy - miny);
        if(maxx < minx || maxy < miny) area = 0;
        printf("Case %d: %d\n", (cases+1), area);

        poly.clear();
    }
    return 0;
}


