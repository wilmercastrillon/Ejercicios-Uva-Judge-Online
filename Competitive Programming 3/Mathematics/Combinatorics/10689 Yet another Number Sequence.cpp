#include <bits/stdc++.h>
#define mod 1000000

using namespace std;

int fibo[20100], match[] = {-1, 60, 300, 1500, 15000};
int a, b;

void pre(int l){
    fibo[0] = a;
    fibo[1] = b;

    for(int i = 2; i <= l; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
    }
}

int main(){
    int t, n, m;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d %d", &a, &b, &n, &m);
        if(n > match[m]) n = n % match[m];
        m = pow(10, m);
        pre(n);
        printf("%d\n", fibo[n] % m);
    }

    return 0;
}


