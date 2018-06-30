#include <stdio.h>

int main(){
    unsigned int n, a, b, con, pos;

    while(scanf("%u", &n), n){
        a = b = pos = con = 0;

        while(n){
            if(n&1){
                if(con&1) b |= (1 << pos);
                else a |= (1 << pos);

                con++;
            }
            pos++;
            n >>= 1;
        }

        printf("%u %u\n", a, b);
    }

    return 0;
}
