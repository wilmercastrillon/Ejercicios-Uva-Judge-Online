#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

struct point{
    double x, y;
    point(){x = y = 0.0;}
    point(double _x, double _y) :x(_x), y(_y){}

    void imp(){ printf(" %.5f %.5f ", x, y); }
};

struct vec{
    double x, y;
    vec(double _x, double _y) :x(_x), y(_y){}
};

point translate(point p, vec v){
    return point(p.x+v.x, p.y+v.y);
}

vec toVec(point a, point b){
    return vec(b.x-a.x, b.y-a.y);
}

vec scale(vec v, double s){
    return vec(v.x*s, v.y*s);
}

double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}

double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}

double dist(point p1, point p2){
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

double distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0){
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if(u > 1.0){
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

int main(){
    double xm, ym, q, w;
    int n;

    while(scanf("%lf", &xm) != EOF){
        scanf("%lf", &ym);
        scanf("%d", &n);
        n++;

        point estacion(xm, ym);
        point res, aux;
        double menor = 100000000.0, aux2;
        vector<point> puntos;

        scanf("%lf", &q);
        scanf("%lf", &w);
        puntos.push_back(point(q, w));
        for(int i = 1; i < n; i++){
            scanf("%lf", &q);
            scanf("%lf", &w);
            puntos.push_back(point(q, w));
            aux2 = distToLineSegment(estacion, puntos[i-1], puntos[i], aux);
            //printf("segmento "); puntos[i-1].imp(); printf(" con "); puntos[i].imp();
            //printf(" distacia es %.5f\n", aux2);
            if(aux2 < menor){
                //printf("nuevo menor en pos "); aux.imp(); printf("\n");
                menor = aux2;
                res = point(aux.x, aux.y);
            }
        }
        printf("%.4f\n%.4f\n", res.x, res.y);
    }

    return 0;
}


