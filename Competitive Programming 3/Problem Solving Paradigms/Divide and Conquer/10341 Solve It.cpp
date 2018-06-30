#include <stdio.h>
#include <math.h>

using namespace std;
double p, q, r, s, t, u;
const double e = exp(1);

double f(double x){
    double parte1 = p*exp(-x) + q*sin(x) + r*cos(x);
    double parte2 = s*tan(x) + t*pow(x,2) +u;
    return parte1 + parte2;
}

double biseccion(){
    double men = 0, may = 1, med = 0;
    double eps = 1e-7, res = -1, ant = -2;

    while(abs(res) > eps){
        //printf("x: %lf, f(x): %lf, may: %lf, men: %lf\n", med, res,may, men);
        med = (men+may)/2;
        res = f(med);
        if(res <= 0){
            may = med;
        }else{
            men = med;
        }
        if(res == ant){
            return -1;
        }
        ant = res;
    }
    return med;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    double x;
    long aux;
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF){
        x = biseccion();
        if(x == -1) printf("No solution\n");
        else{
            //aux = x*10000;
            printf("%.4f\n", x);
            //printf("%.4f\n", (double)aux/10000.0);
        }
    }

    return 0;
}


