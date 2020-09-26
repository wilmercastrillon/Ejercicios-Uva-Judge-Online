#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, m, n, a, b, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &m, &n, &a, &b);
        x = a ^ b ^ (m-a-1) ^ (n-b-1);
        if(x) printf("Gretel\n");
        else printf("Hansel\n");
    }
    return 0;
}


