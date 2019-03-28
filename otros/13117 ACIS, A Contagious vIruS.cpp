#include <bits/stdc++.h>

using namespace std;
double eps = 1e-6;

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
};
struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};
vec toVec(punto a, punto b){return vec(b.x-a.x, b.y-a.y);}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
vec escalar(vec v, double s){
    return vec(v.x*s, v.y*s);
}
punto transladar(punto p, vec v){
    return punto(p.x+v.x, p.y+v.y);
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
            c = -((a-p1.x) / (p1.y));
        }
    }
};

vector<linea> poli;

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

int main(){
    int n, x, y, ax, ay;
    char cad[10];
    punto centro, aux;

    while(scanf("%s", &cad), cad[0] != '*'){
        n = atoi(cad);
        poli.clear();
        scanf("%d %d", &x, &y);
        centro = punto(x*1.0, y*1.0);

        scanf("%d %d", &x, &y);
        for(int i = 1; i < n; i++){
            scanf("%d %d", &ax, &ay);
            poli.push_back(linea(punto(x, y), punto(ax, ay)));
            x = ax;
            y = ay;
        }
        poli.push_back(linea(poli[0].p1, poli[n-2].p2));
        //printf("termino\n");

        double men = 1000.0;
        for(int i = 0; i < poli.size(); i++){
            //printf("dist hasta segmento (%.1f, %.1f) (%.1f, %.1f)\n")
            men = min(men, distSegmento(centro, poli[i], aux));
        }

        printf("%.3f\n", men);
    }

    return 0;
}


