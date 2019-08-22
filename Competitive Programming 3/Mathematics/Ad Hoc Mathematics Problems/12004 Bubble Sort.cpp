#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long int lli;

lli mcd(lli a, lli b){
    return a? mcd(b %a, a): b;
}

int a[100], b[100], con[100];

int findSwaps(int n) {
    int count = 0, i, j, temp;
    for( i = 0; i < n; i++ ) {
        b[i] = a[i];
    }
    for( i = 0; i < n; i++ ) {
        for( j = 0; j < n - 1; j++ ) {
            if( b[j] > b[j+1] ) {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
                count++;
            }
        }
    }
    return count;
}

void fuerza(int n){
    for(int i = 0; i < n; ++i) a[i] = i;
    do{
        con[findSwaps(n)]++;
    }while(next_permutation(a, a+n));
    for(int i = 0; i <= n*(n-1)/2; ++i){
        printf("%d -> %d\n", i, con[i]);
        con[i] = 0;
    }
}

int main(){
    int t, caso = 0;
    lli num, den, n;
    scanf("%d", &t);

    while(t--){
        scanf("%lld", &n);
        num = (n*(n-1))/2LL;
        den = 2LL;

        lli gcd = mcd(num, den);
        num /= gcd;
        den /= gcd;

        if(den == 1LL) printf("Case %d: %lld\n",++caso, num);
        else printf("Case %d: %lld/%lld\n",++caso, num, den);
    }
    return 0;
}
