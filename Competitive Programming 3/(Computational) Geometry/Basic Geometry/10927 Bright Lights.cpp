#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct point{
    double x, y, z;
    point(){x = y = z = 0.0;}
    point(double _x, double _y) :x(_x), y(_y), z(0){}
    point(double _x, double _y, double _z) :x(_x), y(_y), z(_z){}
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

bool cmp(point a, point b){
    return hypot(a.x, a.y) < hypot(b.x, b.y);
}

bool cmp2(point a, point b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

typedef vector<point> vp;
typedef long long int lli;

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);

    int n, con = 1;
    double x, y, z;
    map<lli, vp> mapa;
    point a = point(-1000000.0, 0);
    point o = point(0.0, 0.0);

    while(scanf("%d", &n), n){
        mapa.clear();
        for(int i = 0; i < n; i++){
            scanf("%lf %lf %lf", &x, &y, &z);
            point b = point(x, y, z);
            mapa[(lli) ceil((angle(a, o, b)*100000000000.0))].push_back(b);
            //printf("%.5f\n", angle(a, o, b));
        }

        map<lli, vp>::iterator it;
        vp ocultos;
        for(it = mapa.begin(); it != mapa.end(); it++){
            lli t = it->first;
            //cout << "conjunto: " << (double) (t/10000.0) << endl;
            vp vec = mapa[it->first];
            sort(vec.begin(), vec.end(), cmp);

            double may = -1;
            for(int i = 0; i < vec.size(); i++){
                //printf("[%lf , %lf] ", vec[i].x, vec[i].y);
                if(may < vec[i].z){
                    may = vec[i].z;
                }else{
                    ocultos.push_back(vec[i]);
                }
            }
            //printf("\n");
        }

        printf("Data set %d:\n", con++);
        if(ocultos.size() == 0){
            printf("All the lights are visible.\n");
            continue;
        }
        sort(ocultos.begin(), ocultos.end(), cmp2);
        printf("Some lights are not visible:\nx = %d, y = %d", (int) ocultos[0].x, (int) ocultos[0].y);
        for(int i = 1; i < ocultos.size(); i++){
            printf(";\nx = %d, y = %d", (int) ocultos[i].x, (int) ocultos[i].y);
        }
        printf(".\n");
    }

    return 0;
}


