#include <bits/stdc++.h>
//#define forr(i,n) for(int

using namespace std;
typedef long long int lli;

int main(){
    int f, c, esq, aux;
    lli n;

    while(scanf("%d %d %d", &f,&c,&esq), f){
        f -=7;
        c -= 7;
        aux = (f*c)/2+((f*c)%2);

        if(esq == 1) printf("%d\n", aux);
        else printf("%d\n", (f*c)-aux);
    }
    return 0;
}


