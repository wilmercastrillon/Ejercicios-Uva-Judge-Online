#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
double eps = 1e-5;
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
    return cross(toVec(p,q), toVec(p,r)) > -eps;
}

double angulo(punto a, punto o, punto b){//en radianes
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
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

bool enPoligono(punto pt, vector<punto> &p){
    if(p.size() == 0) return false;
    double sum = 0.0;
    for(int i = 1; i < p.size(); i++){
        if(ccw(pt, p[i-1], p[i]))
            sum+= angulo(p[i-1],pt,p[i]);
        else sum -= angulo(p[i-1],pt,p[i]);
    }
    return fabs(fabs(sum) - 2*PI) < eps;
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

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, r, x, y;
    vector<poly> p;

    while(scanf("%d", &n) != EOF){
        if(n == -1) break;
        poly king;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            king.push_back(punto(x, y));
        }

        vector<punto> ch = ConvexHull(king);
        p.pb(ch);
        //for(int i = 0; i < ch.size(); i++){
        //    printf("(%.3f %.3f)\n", ch[i].x, ch[i].y);
        //}
        //printf("\n");
    }

    double area = 0;
    vector<bool> ok(p.size(), false);
    while(scanf("%d %d", &x, &y) != EOF){
        punto misil(x, y);
        forr(i, p.size()){
            if(ok[i]) continue;

            if(enPoligono(misil, p[i])){
                //printf("en el poligono %d\n", i+1);
                area += AreaPoligono(p[i]);
                ok[i] = true;
            }else{
                //printf("no en poly %d\n", i+1);
            }
        }
    }
    printf("%.2f\n", area);

    return 0;
}


