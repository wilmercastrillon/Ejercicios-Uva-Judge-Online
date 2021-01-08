#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
double eps = 1e-8;

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
    vec operator - (const vec& q) const{
        return vec(x-q.x, y-q.y);
    }
};
double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
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
};

vec toVec(punto a, punto b){
    return vec(b.x-a.x, b.y-a.y);
}
double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool ccw(punto p, punto q, punto r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}

typedef vector<punto> poly;

// line segment p-q intersect with line A-B.
punto lineIntersectSeg(punto p, punto q, punto A, punto B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return punto((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
poly cutPolygon(punto a, punto b, poly &q) {
    poly p1;

    for (int i = 0; i < q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, q[i])), left2 = 0;
        if(i != (int)q.size()-1)
            left2 = cross(toVec(a, b), toVec(a, q[i+1]));
        if(left1 > -eps){
            p1.push_back(q[i]);
        }
        if(left1 * left2 < -eps){
            p1.push_back(lineIntersectSeg(q[i], q[i+1], a, b));
        }
    }
    if (!p1.empty() && !(p1.back() == p1.front()))
        p1.push_back(p1.front()); // make P’s first point = P’s last point
    return p1;
}

double AreaPoligono(poly &p){
    double s = 0.0, d = 0.0;
    int n = p.size();
    forr(i, n){
        s += p[i].x*p[(i+1)%n].y;
        d += p[(i+1)%n].x*p[i].y;
    }
    return fabs(0.5*(s-d));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, h, w, x, y, x1, y1, x2, y2, caso = 1;

    while(scanf("%d %d %d %d %d", &n, &w, &h, &x, &y) != EOF){

        poly part;
        part.pb(punto(0,0));
        part.pb(punto(0,h));
        part.pb(punto(w,h));
        part.pb(punto(w,0));
        part.pb(punto(0,0));

        punto f(x, y);

        forr(i, n){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            punto a = punto(x1,y1);
            punto b = punto(x2,y2);
            //int m = parts.size();
            if(ccw(a, b, f))
                part = cutPolygon(a, b, part);
            else
                part = cutPolygon(b, a, part);
            //printf("terminan %d partes\n", parts.size());
        }

        printf("Case #%d: %.3f\n", caso++, AreaPoligono(part));
    }


    return 0;
}


