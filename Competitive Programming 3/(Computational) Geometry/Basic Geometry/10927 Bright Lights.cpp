#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct point{
    double x, y;
    point(){x = y = 0.0;}
    point(double _x, double _y) :x(_x), y(_y){}
};

struct vec{
    double x, y;
    vec(double _x, double _y) :x(_x), y(_y){}
};

vec toVec(point a, point b){
    return vec(b.x-a.x, b.y-a.y);
}

double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}

double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}

double angle(point a, point o, point b){
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

typedef vector<point> vp;
typedef long long int lli;

int main(){//no terminado
    int n;
    double x, y, z;
    map<lli, vp> mapa;
    point a = point(-1000000.0, 0);
    point o = point(0.0, 0.0);

    while(scanf("%d", &n), n){
        mapa.clear();
        for(int i = 0; i < n; i++){
            scanf("%lf %lf %lf", &x, &y, &z);
            point b = point(x, y);
            mapa[(lli) (angle(a, o, b)*10000.0)].push_back(b);
            printf("%.5f\n", angle(a, o, b));
        }

        map<lli, vp>::iterator it;
        for(it = mapa.begin(); it != mapa.end(); it++){
            lli t = it->first;
            cout << "conjunto: " << (double) (t/10000.0) << endl;
            vp vec = mapa[it->first];
            for(int i = 0; i < vec.size(); i++){
                printf("[%lf , %lf] ", vec[i].x, vec[i].y);
            }
            printf("\n");
        }
    }

    return 0;
}


