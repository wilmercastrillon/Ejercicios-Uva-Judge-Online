#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
//typedef pair<double, double> punto;
const double eps = 1e-4;
const double PI = acos(-1.0);

struct punto{
    double x, y;

    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }
};

vector<punto> triangulo;

bool cmp(punto p1, punto p2) {
    return fabs(p1.x - p2.x) < eps && fabs(p1.y - p2.y) < eps;
}

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

bool interseccion(linea l1, linea l2, punto &p){
    //if(paralelas(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>eps) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

linea perpendicular(linea &l){
    //printf("linea %.5f X + %.5f Y + %.5f = 0\n", l.a, l.b, l.c);
    if(l.a == 0) return linea(1.0, 0.0, (l.p1.x+l.p2.x)/2.0);
    if(l.b == 0) return linea(0.0, 1.0, (l.p1.y+l.p2.y)/2.0);

    double xmed = (l.p1.x + l.p2.x) / 2.0;
    double ymedio = (l.a*xmed + l.c)/(l.b*-1.0);
    double c1 = ((l.b/l.a*-1.0)*xmed+ymedio)*-1.0;
    //printf("punto medio en (%.5f, %.5f)\n", xmed, ymedio);
    return linea((l.b/l.a)*-1.0, 1.0, c1);
}

double DEG_TO_RAD(double n){ return n*PI/180.0; }

punto rotar(punto p, punto centro, double grados){
    double rad = DEG_TO_RAD(grados);
    punto t(p.x-centro.x, p.y-centro.y);
    punto rotado(t.x*cos(rad) - t.y*sin(rad), t.x*sin(rad) + t.y*cos(rad));
    return punto(rotado.x + centro.x, rotado.y + centro.y);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int n, caso = 1;
    double x, y;

    while(cin >> n, n){
        triangulo.clear();
        string s1, s2;
        forr(i, 3){
            cin >> x >> y;
            triangulo.pb(punto(x,y));
        }

        linea ab = linea(triangulo[0],triangulo[1]);
        linea bc = linea(triangulo[1],triangulo[2]);

        linea p1 = perpendicular(ab);
        linea p2 = perpendicular(bc);

        punto centro;
        interseccion(p1,p2,centro);
        //printf("punto centro en (%.5f, %.5f)\n", centro.x, centro.y);

        double ang = 360.0/(n*1.0);
        vector<punto> poly(1, triangulo[0]);
        //printf("punto (%.7f, %.7f), rotar %.5f grados\n", poly[0].x, poly[0].y, ang);
        forr(i, n){
            ang = (360.0/(n*1.0))*(i+1.0);
            punto p = rotar(poly[0], centro, ang);
            bool f = false;
            forr(i, 3){
                if(cmp(p, triangulo[i])){
                    poly.push_back(triangulo[i]);
                    f = true; break;
                }
            }
            if(!f) poly.push_back(p);
            //printf("punto (%.7f, %.7f)\n", poly.back().x, poly.back().y);
        }

        double minx=1000000.0, miny=1000000.0, maxx=-1000000.0, maxy=-1000000.0;
        forr(i, n){
            minx = min(minx, poly[i].x);
            miny = min(miny, poly[i].y);
            maxx = max(maxx, poly[i].x);
            maxy = max(maxy, poly[i].y);
        }
        printf("Polygon %d: %.3f\n", caso++, fabs(minx-maxx)*fabs(miny-maxy));
    }

    return 0;
}


