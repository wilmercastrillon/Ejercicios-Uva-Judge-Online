#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};
double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}

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
    punto operator + (punto p) const{
        return punto(x + p.x, y + p.y);
    }
};
vec toVec(punto a, punto b){
    return vec(b.x-a.x, b.y-a.y);
}

double signed_triangle_area(const punto& a, const punto& b, const punto& c){
  return (a.x * b.y - a.y * b.x + a.y * c.x - a.x * c.y + b.x * c.y - c.x * b.y) / 2.0;
}

bool colineal(punto p, punto q, punto r){
    return fabs(signed_triangle_area(p, q, r)) <= eps;
    //return fabs(cross(toVec(p,q),toVec(p,r))) < eps;
}

double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool ccw(punto p, punto q, punto r){
    //return cross(toVec(p,q), toVec(p,r)) > 0.0;
    return signed_triangle_area(p, q, r) > eps;
}

double angulo(punto a, punto o, punto b){//en radianes
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

double DEG_TO_RAD(double n){ return n/180.0*PI; }

punto rotar(punto p, double rad){
    //double rad = DEG_TO_RAD(grados);
    //printf("rotar (%.3f %.3f) segun(%.3f %.3f) = ", p.x, p.y, centro.x, centro.y);
    p.x = p.x;
    p.y = p.y;
    //printf("(%.3f %.3f) \n", r.x, r.y);
    return punto(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}

typedef vector<punto> poly;

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

double AreaPoligono(vector<punto> &p){
    double s = 0.0, d = 0.0, area = 0.0;
    int n = p.size(), j;
    forr(i, n){
        s += p[i].x*p[(i+1)%n].y;
        d += p[(i+1)%n].x*p[i].y;
    }
    return fabs(0.5*(s-d));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, n;
    double x, y, h, w, a;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        poly puntos;
        vector<poly> rect;
        punto p1, p2, p3, p4, centro;
        double areaR = 0.0;

        for(int i = 0; i < n; i++){
            scanf("%lf %lf %lf %lf %lf", &x, &y, &w, &h, &a);
            areaR += w*h;
            //printf("rotar con ang %.5f\n", a);
            centro = punto(x, y);
            p1 = punto(w/-2.0, h/2.0);
            p2 = punto(w/2.0, h/2.0);
            p3 = punto(w/2.0, h/-2.0);
            p4 = punto(w/-2.0, h/-2.0);
            //if(a > 0.0){
                a = DEG_TO_RAD(a);
                p1 = centro + rotar(p1, -a);
                p2 = centro + rotar(p2, -a);
                p3 = centro + rotar(p3, -a);
                p4 = centro + rotar(p4, -a);
            //}
            poly aux;
            aux.pb(p1);  aux.pb(p2);  aux.pb(p3);  aux.pb(p4);
            rect.pb(aux);

            puntos.pb(p1);  puntos.pb(p2);  puntos.pb(p3);  puntos.pb(p4);
        }

        vector<punto> ch = ConvexHull(puntos);
        double areaCH = AreaPoligono(ch);
        printf("%.1f %%\n", areaR * 100 / areaCH);

        //for(int i = 0; i < ch.size(); i++){
        //    printf("(%.3f %.3f)\n", ch[i].x, ch[i].y);
        //}
        //printf("\n");
    }


    return 0;
}


