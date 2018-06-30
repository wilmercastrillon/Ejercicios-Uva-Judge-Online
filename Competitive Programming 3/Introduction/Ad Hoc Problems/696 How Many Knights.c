#include <stdio.h>

int main(){

    int m, n, res, a, b;

    while(scanf("%d %d", &m, &n) && (m || n)){
        if(m > 2 && n > 2){
            res = (m * n) / 2;
            if((m * n) % 2) res++;
        }else{
            if(m == 1 || n == 1){
                res = m*n;
            }else{

                a = 2;
                if(m == 2)
                    b = n;
                else
                    b = m;

                switch(b % 4){
                    case 0: res = b;
                        break;
                    case 1: res = b + 1;
                        break;
                    case 2: res = b + 2;
                        break;
                    case 3: res = b + 1;
                        break;
                }
            }
        }

        printf("%d knights may be placed on a %d row %d column board.\n", res, m, n);
    }

    return 0;
}
