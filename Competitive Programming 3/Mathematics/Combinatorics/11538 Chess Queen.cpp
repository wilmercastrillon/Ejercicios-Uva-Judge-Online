#include <stdio.h>
#define min(a,b) (a<b)? a:b
#define max(a,b) (a>b)? a:b

using namespace std;
typedef unsigned long long int ulli;

ulli tab[1000010];

void pre(){
    tab[0] = tab[1] = 0;
    for(ulli i = 2; i < 1000002; i++){
        tab[i] = i*(i-1) + tab[i-1];
    }
}

int main(){
    pre();
    ulli n, m, q, w, men, may;

    while(scanf("%llu %llu", &n, &m), n && m){
        q = (m-1 + n-1)*(n*m);
        men = min(m,n);  may = max(m,n);
        w = (ulli) 2*(2*tab[men-1] + men*(men-1)*((may-men)+1));
        printf("%llu\n", q+w);
    }

    return 0;
}

