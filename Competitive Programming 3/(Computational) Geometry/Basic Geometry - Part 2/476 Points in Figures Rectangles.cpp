#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<double, double> dd;
typedef pair<dd, dd> rec;
vector<rec> poly;

int main(){
    char cad[2];
    double x1, y1, x2, y2, x, y;
    while(scanf("%s", &cad)!= EOF){
        if(cad[0] != '*'){
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            //printf("leyo %d %d %d %d", x1, y1, x2, y2);
            poly.pb(rec(dd(x1,y1), dd(x2,y2)));
            continue;
        }

        int point = 1;
        while(cin >> x >> y){
            if(x == 9999.9 && y == 9999.9) break;
            bool any = false;
            forr(i, poly.size()){
                dd up = poly[i].first;
                dd low = poly[i].second;

                if(up.first < x && x < low.first)
                if(up.second > y && y > low.second){
                    any = true;
                    printf("Point %d is contained in figure %d\n", point, (i+1));
                }
            }
            if(!any) printf("Point %d is not contained in any figure\n", point);
            point++;
        }
        poly.clear();
    }
    return 0;
}


