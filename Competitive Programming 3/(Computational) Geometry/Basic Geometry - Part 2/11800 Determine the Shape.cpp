#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

double eps = 1e-8;
double PI = acos(-1.0);

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
struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};

vec toVec(punto a, punto b){
    return vec(b.x-a.x, b.y-a.y);
}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}

vector<punto> poly;
punto pivot;

double dist2(punto p1, punto p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    //return hypot(p1.x-p2.x, p1.y-p2.y);
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

double AreaPoligono(vector<punto> &p){
    double s = 0.0, d = 0.0;
    int n = p.size();
    forr(i, n){
        s += p[i].x*p[(i+1)%n].y;
        d += p[(i+1)%n].x*p[i].y;
    }
    return s-d;//(s-d)/2.0;
}

bool isSquare(){
    vec v1 = toVec(poly[0], poly[1]), v2 = toVec(poly[1], poly[2]);
    vec v3 = toVec(poly[2], poly[3]), v4 = toVec(poly[3], poly[0]);
    if(fabs(dot(v1, v2)) > eps || fabs(dot(v2, v3)) > eps
            || fabs(dot(v3, v4)) > eps || fabs(dot(v4, v1)) > eps)
        return false;

    double d1 = dist2(poly[0], poly[1]), d2 = dist2(poly[1], poly[2]);
    double d3 = dist2(poly[2], poly[3]), d4 = dist2(poly[3], poly[0]);
    return (fabs(d1-d2)<eps && fabs(d2-d3)<eps && fabs(d3-d4)<eps && fabs(d4-d1)<eps);
}

bool isRectangle(){
    vec v1 = toVec(poly[0], poly[1]), v2 = toVec(poly[1], poly[2]);
    vec v3 = toVec(poly[2], poly[3]), v4 = toVec(poly[3], poly[0]);
    if(fabs(dot(v1, v2)) > eps || fabs(dot(v2, v3)) > eps
            || fabs(dot(v3, v4)) > eps || fabs(dot(v4, v1)) > eps){
        //printf("1\n");
        return false;
    }

    double d1 = dist2(poly[0], poly[1]), d2 = dist2(poly[1], poly[2]);
    double d3 = dist2(poly[2], poly[3]), d4 = dist2(poly[3], poly[0]);
    return (fabs(d1-d3)<eps || fabs(d2-d4)<eps);
}

bool isRhombus(){
    double d1 = dist2(poly[0], poly[1]), d2 = dist2(poly[1], poly[2]);
    double d3 = dist2(poly[2], poly[3]), d4 = dist2(poly[3], poly[0]);
    return (fabs(d1-d2)<eps && fabs(d2-d3)<eps && fabs(d3-d4)<eps && fabs(d4-d1)<eps);
}

bool isParallelogram(){
    double d1 = dist2(poly[0], poly[1]), d2 = dist2(poly[1], poly[2]);
    double d3 = dist2(poly[2], poly[3]), d4 = dist2(poly[3], poly[0]);
    return (fabs(d1-d3) < eps && fabs(d2-d4) < eps);
}

bool isTrapezium(){
    linea l1(poly[0], poly[1]), l2(poly[1], poly[2]);
    linea l3(poly[2], poly[3]), l4(poly[3], poly[0]);
    return (paralelas(l1, l3)&&!paralelas(l2, l4)) || (paralelas(l2, l4)&&!paralelas(l1, l3));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int n, x, y, caso = 1;
    cin >> n;
    string res[] = {"Square","Rectangle","Rhombus","Parallelogram","Trapezium","Ordinary Quadrilateral"};

    while(n--){
        poly.clear();
        forr(i, 4){
            cin >> x >> y;
            poly.pb(punto(x, y));
        }

        int menor = 5, aux;
        //printf("area %.5f\n", AreaPoligono(poly));
        sort(poly.begin(), poly.end());
        //pivot = poly[0];
        //sort(++poly.begin(), poly.end(), angleCmp);
        do{
            if(AreaPoligono(poly) > eps) break;
        } while(next_permutation(poly.begin(), poly.end()));

        aux = 5;
        if(isSquare()) aux = 0;
        if(aux==5 && isRectangle()) aux = 1;
        if(aux==5 && isRhombus()) aux = 2;
        if(aux==5 && isParallelogram()) aux = 3;
        if(aux==5 && isTrapezium()) aux = 4;

        cout << "Case " << caso++ << ": " << res[aux] << endl;
    }

    return 0;
}


