#include <stdio.h>
#include <math.h>

#define max(a, b) (a > b)? a: b

typedef long long int lli;

int main(){
    lli a, b, c, d, r = 0, aux1, aux2, x1, x2, x3;

    for(a = 8; a < 126; a += 1)
        for(b = a; b < 593; b += 1)
            for(c = b; c < 885; c += 1){
                x1 = (a+b+c)* -1000000;
                x2 = -(a*b*c) + 1000000;
                if(x2 != 0){
                    x3 =  x1/x2;
                    aux1 = a+b+c+x3;
                    aux2 = (a*b*c*x3)/1000000;

                    if(aux1 == aux2 && aux2 <= 2000 && c <= x3){
                        printf("%.2f %.2f %.2f %.2f\n",
                               (double) a/100,(double) b/100, (double)c/100, (double) x3/100);
                    }
                }
            }

    return 0;
}


