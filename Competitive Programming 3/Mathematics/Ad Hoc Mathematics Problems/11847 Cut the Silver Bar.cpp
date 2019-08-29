#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    int n;

    while(scanf("%d", &n), n){
        printf("%.0f\n", floor(log2(n)));
    }

    return 0;
}


