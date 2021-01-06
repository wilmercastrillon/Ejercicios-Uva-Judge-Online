#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef long long int lli;
const double eps = 1e-8;

struct punto{
    double x, y;
    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }
};

double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
double distpow2(punto p1, punto p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

double CircumCircle(punto &A, punto &B, punto &C, punto &centro) {
    double bx = B.x - A.x, by = B.y - A.y, cx = C.x - A.x, cy = C.y - A.y;
    double _B = bx * bx + by * by;
    double _C = cx * cx + cy * cy;
    double _D = bx * cy - by * cx;
    centro = punto((cy * _B - by * _C) / (2 * _D), (bx * _C - cx * _B) / (2 * _D));
    centro.x += A.x;
    centro.y += A.y;
    return distpow2(centro, A);
}

vector<punto> puntos;

double minCoverCircle(vector<punto> &p){
    double maxlen = 0.0, aux;
    punto c = p[0];
    double r = 0.0;

    forab(i,1,p.size()){
        if(distpow2(c, p[i]) >= r+eps){
            r = 0.0;
            c = p[i];
            //printf("radio1 %.5f\n", r);
            forr(j, i){
                if(distpow2(c, p[j]) >= r+eps){
                    c.x = (p[i].x+p[j].x)/2.0;
                    c.y = (p[i].y+p[j].y)/2.0;
                    r = distpow2(c, p[i]);
                    //printf("radio2 %.5f\n", r);
                    forr(k, j){
                        if(distpow2(p[k], c) >= r+eps)
                            r = CircumCircle(p[i],p[j],p[k],c);
                        //printf("(%.5f,%.5f),(%.5f,%.5f),(%.5f,%.5f)\n", p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
                        //printf("centro (%.5f,%.5f), radio3 %.5f\n", c.x, c.y, r);
                    }
                }
            }
        }
    }
    return sqrt(r);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    double x, y, r, minr;
    int t;

    while(cin >> t, t){
        puntos.clear();
        forr(i, t){
            cin >> x >> y;
            puntos.pb(punto(x, y));
        }
        cin >> r;

        minr = minCoverCircle(puntos);
        if(minr > r){
            printf("There is no way of packing that polygon.\n");
        }else{
            printf("The polygon can be packed in the circle.\n");
        }
    }

    return 0;
}


