#include <stdio.h>

using namespace std;

int main(){
    int t, n, x[11], caso = 0;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        for(int i = 0; i < n; ++i){
            scanf("%d", &x[i]);
        }
        printf("Case %d: %d\n", ++caso, x[n>>1]);
    }

    return 0;
}


