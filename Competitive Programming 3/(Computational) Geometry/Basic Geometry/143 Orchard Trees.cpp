#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
//typedef long long int lli;
const double eps = 1e-7;
double area;

struct punto{
    double x, y;

    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }

    bool operator == (punto p) const{
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }
};

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
    vec operator - (const vec& q) const{
        return vec(x-q.x, y-q.y);
    }
    double operator ^ (const vec& q) const{
        return x*q.y - y*q.x;
    }
};

double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double areaT2(punto &pa, punto &pb, punto &pc){
    vec a(pa.x,pa.y), b(pb.x,pb.y), c(pc.x,pc.y);
    return ((c-a)^(b-a))/2.0;
}
bool enTriangulo(punto pt, vector<punto> &t) {
    double sum = 0, aux;
    int conn = 0, conp = 0;

    for (int i = 0; i < t.size()-1; i++) {
        if(t[i] == pt) return true;
        aux = fabs(areaT2(t[i],pt,t[i+1]));
        //if(aux2 < eps) conn++;
        //if(aux2 > -1.0*eps) conp++;
        //printf("\t\t aux1 %.5f\n", aux);
        sum += aux;
    }
    //printf("\t suman1 %.9f | suman2 %.9f\n", sum, sum2);
    return fabs(area - sum) < eps;
    //return conn > 3 || conp < 3;
}

double toDouble(string &s){
    string res;
    int punto = -1;
    bool p = false;
    forr(i, s.size()){
        if(i != punto){
            if(s[i] != '.') res.pb(s[i]);
            else{
                p = true;
                punto = i+2;
            }
        }else{
            res.pb('.');
            res.pb(s[i]);
            punto = -1;
        }
    }
    if(punto != -1){
        forab(i, s.size(), punto)
            res.pb('0');
    }
    if(!p){
        res.pb('0');
    }
    return atof(res.c_str());
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    double x, y;
    string s1, s2;
    punto origen(0,0);

    while(1){
        vector<punto> t;
        int minx = 100, maxx = 0, miny = 100, maxy = 0, auxx, auxy;
        forr(i, 3){
            cin >> x >> y;
            //x = toDouble(s1);
            //y = toDouble(s2);
            //printf("%.5f %.5f\n", toDouble(s1), toDouble(s2));
            t.pb(punto(x, y));

            minx = min(minx, (int) ceil(x));
            miny = min(miny, (int) ceil(y));
            maxx = max(maxx, (int) x);
            maxy = max(maxy, (int) y);
        }
        t.pb(punto(t[0].x, t[0].y));

        bool salir = true;
        forr(i, 3)
            salir = salir && (origen == t[i]);
        if(salir) break;

        area = fabs(areaT2(t[0], t[1], t[2]));
        //printf("area total = %.10f\n", area);
        int con = 0;
        minx = max(minx, 1);
        miny = max(miny, 1);
        maxx = min(maxx+1, 100);
        maxy = min(maxy+1, 100);
        //printf("rango (%d %d), (%d, %d)\n", minx, miny, maxx, maxy);

        for(int i = minx; i< maxx; ++i)
        for(int j = miny; j< maxy; ++j){
            punto p(i, j);
            if(enTriangulo(p, t)){
                //printf("adentro %d %d\n", i, j);
                con++;
            }else{
                //printf("afuera %d %d\n", i, j);
            }
        }

        printf("%4d\n", con);
    }

    return 0;
}
//1 3 1.2 1 0.69 1
//out 3

