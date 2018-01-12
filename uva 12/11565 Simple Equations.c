#include <stdio.h>
#include <math.h>

typedef long long int lli;

int main(){
    lli a, b, c, x, y, z;
    lli px, py, pc;
    int casos;
    scanf("%d", &casos);

    while(casos--){
        scanf("%lld %lld %lld", &a, &b, &c);
        int flag = 0;

        for(x = -10000; x <= a && x <= b; x++){
            px = x*x;
            for(y = x + 1; x+y <= a && x*y <= b && px+y*y <= c; y++){
                py = y*y;
                for(z = y + 1; x+y+z <= a && x*y*z <= b && px+py+z*z <= c; z++){
                    if(x+y+z==a && x*y*z == b && px+py+z*z == c){
                        printf("%lld %lld %lld\n", x, y, z);
                        flag = 1;
                        x = y = z = a+b+c;
                    }
                }
            }
        }

        if(!flag) printf("No solution.\n");
    }

    return 0;
}


