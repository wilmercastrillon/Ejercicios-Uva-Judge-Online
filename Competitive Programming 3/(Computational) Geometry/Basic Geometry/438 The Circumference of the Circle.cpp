#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
const double PI = 3.141592653589793;//acos(-1.0);

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
    cin.tie(NULL);
    double x, y;

    while(cin >> x >> y){
        punto p1(x, y);
        cin >> x >> y;
        punto p2(x, y);
        cin >> x >> y;
        punto p3(x, y);

        //printf("(%.5f,%.5f), (%.5f,%.5f), (%.5f,%.5f)\n",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
        double r1 = rCircumCircle(p1, p2, p3);
        //double r2 = rInCircle(p1, p2, p3);
        //printf("radio1 = %.5f | radio2 = %.5f\n", r1, r2);
        double cir = PI*r1*2.0;
        printf("%.2f\n", cir);
    }

    return 0;
}


