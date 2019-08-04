#include <stdio.h>
#include <math.h>

double xlen, ylen, vo, ang, t, disTotal, a;
const double pi = acos(-1);

int main(){
    while(scanf("%lf %lf %lf %lf %lf", &xlen, &ylen, &vo, &ang, &t)){
        if(xlen==0) break;

        disTotal = (0.0+vo)/2.0*t;
        double x = xlen/2.0, y = ylen/2.0;
        y = sin(ang/180.0*pi)*disTotal;
        x = cos(ang/180.0*pi)*disTotal;

        printf("%.0f %.0f\n", x/xlen, y/ylen);
    }

    return 0;
}


