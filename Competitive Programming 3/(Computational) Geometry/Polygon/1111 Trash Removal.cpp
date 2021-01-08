#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)

using namespace std;
double eps = 1e-7;

struct punto{
    double x, y;

    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }

    bool operator < (punto p) const{//para poder usar sort
        if(fabs(x - p.x) > eps) return x < p.x;
        return y < p.y;
    }
    bool operator == (punto p) const{
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }
};

struct linea{
    double a, b, c;
    punto p1, p2;

    linea(double _a, double _b, double _c){
        a = _a;  b = _b;  c = _c;
    }
    linea(punto _p1, punto _p2){
        p1 = punto(_p1.x, _p1.y);
        p2 = punto(_p2.x, _p2.y);
        if(fabs(p1.x - p2.x) < eps){
            a = 1.0;  b = 0.0;  c = -p1.x;
        }else{
            a = -((p1.y-p2.y) / (p1.x-p2.x));
            b = 1.0;
            c = -a*p1.x-p1.y;
        }
    }
};

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};
double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
vec toVec(punto a, punto b){return vec(b.x-a.x, b.y-a.y);}
double DEG_TO_RAD(double n){ return n*3.1416/180.0; }

punto rotar(punto p, double grados){
    double rad = DEG_TO_RAD(grados);
    return punto(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}
punto transladar(punto p, vec v){
    return punto(p.x+v.x, p.y+v.y);
}
vec escalar(vec v, double s){
    return vec(v.x*s, v.y*s);
}
bool colineal(punto p, punto q, punto r){
    return fabs(cross(toVec(p,q),toVec(p,r))) < eps;
}
double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool ccw(punto p, punto q, punto r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}
double distLinea(punto p, linea l, punto &c){
    punto a = l.p1, b = l.p2;
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = transladar(a, escalar(ab, u));//punto mas cercano
    return dist(p, c);
}

punto pivote;

bool angleCmp(punto a, punto b){
    if(colineal(pivote,a,b))
        return dist(pivote,a) < dist(pivote,b);
    double d1x = a.x-pivote.x, d1y = a.y-pivote.y;
    double d2x = b.x-pivote.x, d2y = b.y-pivote.y;
    return (atan2(d1y,d1x) - atan2(d2y,d2x)) < 0;
}

vector<punto> ConvexHull(vector<punto> p){
    pivote = punto(0,0);
    int i, j, n = p.size(), k = 0;
    if(n <= 3){
        if(!(p[0]==p[n-1])) p.push_back(p[0]);
        return p;
    }

    sort(p.begin(), p.end());
    vector<punto> s(p.size()*2);
    for(int i = 0; i < p.size(); i++){
        while(k>=2 && !ccw(s[k-2],s[k-1],p[i])) k--;
        s[k++] = p[i];
    }

    for(int i=p.size()-2, t=k+1; i>=0; i--){
        while(k>=t && !ccw(s[k-2],s[k-1],p[i])) k--;
        s[k++] = p[i];
    }
    s.resize(k);
    return s;
}

double minDist(vector<punto> &v){
    double minx = 1000000000.0, maxx = -1000000000.0;
    forr(i, v.size()){
        minx = min(minx, v[i].x);
        maxx = max(maxx, v[i].x);
    }
    return maxx - minx;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, caso = 0;
    double x, y;
    punto cero(0,0);

    while(scanf("%d", &n), n){
        vector<punto> v;
        vector<punto> aux;

        forr(i, n){
            scanf("%lf %lf", &x, &y);
            v.pb(punto(x, y));
            aux.pb(punto(x, y));
        }

        double ans = 1000000000.0, d, may;
        vector<punto> ch = ConvexHull(v);
        forab(i,1,ch.size()){
            //printf("linea (%.5f %.5f)(%.5f %.5f) | %.5f\n", ch[i-1].x, ch[i-1].y,ch[i].x, ch[i].y, d);
            may = 0.0;
            linea l(ch[i-1], ch[i]);

            forr(j,ch.size()){
                //printf("punto %.5f, %.5f\n", ch[j].x, ch[j].y);
                d = distLinea(ch[j], l, cero);
                may = max(may, d);
            }
            ans = min(ans, may);
        }

        printf("Case %d: %.2f\n", ++caso, ans);
    }

    return 0;
}


