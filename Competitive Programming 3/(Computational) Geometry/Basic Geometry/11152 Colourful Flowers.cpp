#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
const double eps = 1e-6;
const double PI = acos(-1.0);

double area(double a, double b, double c){
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * (ab+bc+ca));
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    double a, b, c;

    while(cin >> a >> b >> c){

        double sumf = pow(rCircumCircle(a, b, c), 2.0)*PI;
        double vio = area(a, b, c);
        double roses = pow(rInCircle(a, b, c), 2.0)*PI;

        sumf -= vio;
        vio -= roses;

        printf("%.4f %.4f %.4f\n", sumf, vio, roses);
    }

    return 0;
}


