#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int r, n, aux, caso = 0;

    while(scanf("%d %d", &r, &n), n){
        aux = r/n;
        aux -= ((r%n) == 0);
        aux = max(0, aux);
        if(aux > 26) printf("Case %d: impossible\n", ++caso);
        else printf("Case %d: %d\n", ++caso, aux);
    }

    return 0;
}


