#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
double eps = 1e-7;
const double PI = acos(-1.0);

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
};

vec toVec(punto a, punto b){
    return vec(b.x-a.x, b.y-a.y);
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
punto transladar(punto p, vec v){
    return punto(p.x+v.x, p.y+v.y);
}
vec escalar(vec v, double s){
    return vec(v.x*s, v.y*s);
}

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

bool paralelas(linea l1, linea l2){
    return fabs(l1.a-l2.a)<eps && fabs(l1.b-l2.b)<eps;
}
bool interseccion(linea l1, linea l2, punto &p){
    if(paralelas(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>eps) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}
double distLinea(punto p, linea l, punto &c){
    punto a = l.p1, b = l.p2;
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = transladar(a, escalar(ab, u));//punto mas cercano
    return dist(p, c);
}
double distSegmento(punto p, linea l, punto &c){
    punto a = l.p1, b = l.p2;
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0){
        c = punto(a.x, a.y); return dist(p, a);
    }
    if(u > 1.0){
        c = punto(b.x, b.y); return dist(p, b);
    }
    return distLinea(p, l, c);
}
bool intersecSegmentos(linea l1, linea l2, punto &p){
    punto pp, c;
    if(interseccion(l1,l2,pp)){
        if(distSegmento(pp,l1,c)<eps &&
           distSegmento(pp,l2,c)<eps){
            p.x = pp.x;  p.y = pp.y;
            return true;
        }
    }
    return false;
}

typedef vector<punto> poly;
punto pivote;

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
    double s = 0.0, d = 0.0;
    int n = p.size();
    forr(i, n){
        s += p[i].x*p[(i+1)%n].y;
        d += p[(i+1)%n].x*p[i].y;
    }
    return fabs(0.5*(s-d));
}

double areaTriangulo(punto &pa, punto &pb, punto &pc){
    vec a(pa.x,pa.y), b(pb.x,pb.y), c(pc.x,pc.y);
    return (cross((c-a),(b-a)))/2.0;
}
bool enPoligono(punto pt, vector<punto> &p) {
    double area = AreaPoligono(p), sum = 0.0;
    for(int i = 0; i < p.size()-1; i++) {
        if(p[i] == pt) return true;
        sum += fabs(areaTriangulo(p[i],pt,p[i+1]));
    }
    return fabs(area - sum) < eps;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y;

    while(scanf("%d", &n), n){
        poly p1, p2, p3;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            p1.push_back(punto(x, y));
        }
        p1.pb(p1[0]);

        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            p2.push_back(punto(x, y));
        }
        p2.pb(p2[0]);

        forab(i, 1, p1.size()){
            linea l1(p1[i-1], p1[i]);
            forab(j, 1, p2.size()){
                linea l2(p2[j-1], p2[j]);
                punto inter;
                //printf("l1 -> (%.5f, %.5f) (%.5f, %.5f)\n", p1[i-1].x,p1[i-1].y, p1[i].x, p1[i].y);
                //printf("l2 -> (%.5f, %.5f) (%.5f, %.5f)\n", p2[j-1].x,p2[j-1].y, p2[j].x, p2[j].y);
                if(intersecSegmentos(l1, l2, inter)){
                    p3.pb(inter);
                    //printf("## inter (%.5f, %.5f)\n", inter.x, inter.y);
                }
            }
        }
        forr(i, n){
            if(enPoligono(p1[i], p2)){
                p3.pb(p1[i]);
                //printf("dentro (%.5f, %.5f)\n", p1[i].x, p1[i].y);
            }
        }
        forr(i, m){
            if(enPoligono(p2[i], p1)){
                p3.pb(p2[i]);
                //printf("dentro (%.5f, %.5f)\n", p2[i].x, p2[i].y);
            }
        }

        double area = AreaPoligono(p1) + AreaPoligono(p2);
        //printf("a 1-> %.5f, 2-> %.5f\n", AreaPoligono(p1), AreaPoligono(p2));
        if(p3.size() >= 3){
            vector<punto> ch = ConvexHull(p3);
            //for(int i = 0; i < ch.size(); i++){
            //    printf("(%.3f %.3f)\n", ch[i].x, ch[i].y);
            //}
            //printf("\n");
            area -= 2.0*AreaPoligono(ch);
            //printf("ch-> %.5f\n", AreaPoligono(ch));
        }

        printf("%8.2f", area);
        //printf("\n");
    }
    printf("\n");
    return 0;
}


