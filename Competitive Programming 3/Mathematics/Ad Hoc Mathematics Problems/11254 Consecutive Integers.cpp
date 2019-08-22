#include <stdio.h>
#include <math.h>
#define forr(i, n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
typedef long long int lli;

int main(){
    lli sn, a1, aux;

    while(scanf("%lld", &sn), sn != -1){
        lli best = -1;
        if(sn == 1){
            printf("1 = 1 + ... + 1\n");
            continue;
        }

        forab(n,1,sn){
            aux = (2*sn-(n*n)+n);
            //printf("con %d elementos desde %.3f hasta %.3f suman: %d\n", n, 1.0*aux/(n<<1), 1.0*aux/(n<<1)+n*1.0, sn);
            if(aux <= 0){
                //printf("no viable desde %d\n", n);
                break;
            }
            if(aux % (n<<1) == 0){
                a1 = aux / (n<<1);
                best = n;
            }
        }

        printf("%lld = %lld + ... + %lld\n", sn, a1, (a1+best)-1);
    }

    return 0;
}


