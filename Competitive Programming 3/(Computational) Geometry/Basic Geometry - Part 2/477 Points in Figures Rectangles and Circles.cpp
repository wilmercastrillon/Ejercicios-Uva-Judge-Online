#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<double, double> dd;
typedef pair<dd, dd> rec;
typedef pair<dd, double> cir;
vector<rec> poly;
vector<cir> circles;
vector<int> indexP, indexC;

int main(){
    char cad[2];
    double x1, y1, x2, y2, x, y, r, idx = 1;

    while(scanf("%s", &cad)!= EOF){
        if(cad[0] != '*'){
            if(cad[0] == 'r'){
                scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
                poly.pb(rec(dd(x1,y1), dd(x2,y2)));
                indexP.pb(idx++);
            }
            if(cad[0] == 'c'){
                scanf("%lf %lf %lf",&x1,&y1,&r);
                circles.pb(cir(dd(x1,y1), r));
                indexC.pb(idx++);
            }
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
                    printf("Point %d is contained in figure %d\n", point, indexP[i]);
                }
            }

            forr(i, circles.size()){
                dd center = circles[i].first;
                r = circles[i].second;
                if(hypot(center.first-x, center.second-y) < r){
                    any = true;
                    printf("Point %d is contained in figure %d\n", point, indexC[i]);
                }
            }
            if(!any) printf("Point %d is not contained in any figure\n", point);
            point++;
        }

        indexP.clear();
        indexC.clear();
        idx = 1;
        poly.clear();
        circles.clear();
    }
    return 0;
}


