#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
const double eps = 1e-5;
const double PI = acos(-1.0);

struct punto{
    double x, y;

    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }
};

struct linea{//ax + by + c = 0
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

linea perpendicular(linea &l){
    //printf("linea %.5f X + %.5f Y + %.5f = 0\n", l.a, l.b, l.c);
    if(l.a == 0) return linea(1.0, 0.0, (l.p1.x+l.p2.x)/-2.0);
    if(l.b == 0) return linea(0.0, 1.0, (l.p1.y+l.p2.y)/-2.0);

    double xmed = (l.p1.x + l.p2.x) / 2.0;
    double ymedio = (l.a*xmed + l.c)/(l.b*-1.0);
    double c1 = ((l.b/l.a*-1.0)*xmed+ymedio)*-1.0;
    //printf("punto medio en (%.5f, %.5f)\n", xmed, ymedio);
    return linea((l.b/l.a)*-1.0, 1.0, c1);
}
bool interseccion(linea l1, linea l2, punto &p){
    //if(paralelas(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b) > eps) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

double dist(punto &a, punto &b){
    return hypot(a.x-b.x, a.y-b.y);
}
double area(double a, double b, double c){
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle(punto a, punto b, punto c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    double x, y;
    punto origen(0,0);

    while(cin >> x >> y){
        vector<punto> t;
        int minx = 100, maxx = 0, miny = 100, maxy = 0;
        t.pb(punto(x, y));
        forr(i, 2){
            cin >> x >> y;
            t.pb(punto(x, y));
        }
        //t.pb(punto(t[0].x, t[0].y));
        double r = rCircumCircle(t[0], t[1], t[2]);

        linea ab(t[0], t[1]);
        linea bc(t[1], t[2]);
        linea p1 = perpendicular(ab);
        linea p2 = perpendicular(bc);
        //printf("perp %.3f x + %.3fy + %.3f = 0\n", p1.a, p1.b, p1.c);
        //printf("perp %.3f x + %.3fy + %.3f = 0\n", p2.a, p2.b, p2.c);
        punto centro;
        interseccion(p1, p2, centro);
        //printf("punto centro %.5f %.5f\n", centro.x, centro.y);

        double c = -2.0*centro.x;
        double d = -2.0*centro.y;
        double e = pow(centro.x,2.0) + pow(centro.y,2.0) - (r*r);

        char s1 = '-', s2 = '-', s3 = '-', s4 = '-', s5 = '-';
        if(centro.x < 0.0) s1 = '+';
        if(centro.y < 0.0) s2 = '+';
        if(c >= 0.0) s3 = '+';
        if(d >= 0.0) s4 = '+';
        if(e >= 0.0) s5 = '+';

        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", s1, fabs(centro.x), s2, fabs(centro.y), r);
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n", s3, fabs(c), s4, fabs(d), s5, fabs(e));
        printf("\n");

    }

    return 0;
}


