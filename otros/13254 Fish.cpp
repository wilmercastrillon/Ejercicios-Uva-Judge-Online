#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
const double eps = 1e-5;
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
vec escalar(vec v, double s){
    return vec(v.x*s, v.y*s);
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
double angulo(punto a, punto o, punto b){//en radianes
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
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

bool inPoligono(punto pt, vector<punto> &p){
    if(p.size() == 0) return false;
    double sum = 0.0;
    for(int i = 1; i < p.size(); i++){
        if(ccw(pt, p[i-1], p[i]))
            sum+= angulo(p[i-1],pt,p[i]);
        else sum -= angulo(p[i-1],pt,p[i]);
    }
    return fabs(fabs(sum) - 2*PI) < eps;
}

int n, r;

bool check(vector<punto> &a, vector<punto> &b){
    punto p, c;

    forab(i,1,a.size()){
        linea aux1(a[i-1],a[i]);

        forab(j,1,b.size()){
            linea aux2(b[j-1],b[j]);
            if(interseccion(aux1,aux2,p)){
                //printf("interseccion en linea(%.3fX, %.3fY, %.3f) con linea(%.3fX, %.3fY, %.3f), en punto (%.3f,%.3f)\n",
                //       aux1.a,aux1.b,aux1.c, aux2.a,aux2.b,aux2.c,p.x,p.y);
                if(distSegmento(p,aux1,c)<eps && distSegmento(p,aux2,c)<eps){
                    //printf("esta dentro del poligono\n");
                    return false;
                }
            }
        }
    }

    if(inPoligono(a[0],b) || inPoligono(b[0],a))
        return false;
    return true;
}

bool puntoLimite(vector<punto> &a, punto p){
    int menx, mayx, meny, mayy;
    forab(i,1,a.size()){
        if(colineal(a[i-1],a[i],p)){
            //printf("i=%d |colineal con (%.3f,%.3f) y (%.3f,%.3f)\n", i, a[i-1].x,a[i-1].y,a[i].x,a[i].y);
            menx = min(a[i-1].x,a[i].x);
            mayx = max(a[i-1].x,a[i].x);
            meny = min(a[i-1].y,a[i].y);
            mayy = max(a[i-1].y,a[i].y);
            if((menx-p.x < eps) && (p.x-mayx < eps) &&
               (meny-p.y < eps) && (p.y-mayy < eps)){
                return true;
           }
        }
    }
    return false;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    while(scanf("%d %d", &n, &r), n || r){
        int x, y;
        char c;
        vector<punto> a, b;
        forr(i, n){
            scanf("%d %d %c", &x, &y, &c);
            if(c == 'A') a.push_back(punto(x, y));
            else b.push_back(punto(x, y));
        }
        a = ConvexHull(a);
        b = ConvexHull(b);
        //forab(i,0,a.size()){
        //    printf("%d -> ()")
        //}

        if(a.size()==1){
            if(puntoLimite(b,a[0]) || inPoligono(a[0],b))
                printf("NOT YET\n");
            else printf("FEED\n");
            continue;
        }else if(b.size()==1){
            if(puntoLimite(a,b[0]) || inPoligono(b[0],a))
                printf("NOT YET\n");
            else printf("FEED\n");
            continue;
        }

        if(check(a, b)) printf("FEED\n");
        else printf("NOT YET\n");
    }
    return 0;
}


