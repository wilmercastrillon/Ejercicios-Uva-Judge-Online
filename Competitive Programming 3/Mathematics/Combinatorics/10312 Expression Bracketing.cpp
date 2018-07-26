#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long int lli;

lli Scat[27];
lli catalan[27];

void preCat(){
    catalan[0] = 1;
    for(int i = 1; i < 27; i++){
        catalan[i] = ((2*i)*(2*i-1)*catalan[i-1])/((1+i)*i);
    }
}

void preScat(){
    Scat[1] = Scat[2] = 1;
    for(int i = 3; i < 27; i++){
        Scat[i] = ((3*(2*i-3)*Scat[i-1]) - ((i-3)*Scat[i-2]))/i;
    }
}

int main(){
    int n;
    preCat();
    preScat();

    while(scanf("%d", &n) != EOF){
        printf("%lld\n", Scat[n] - catalan[n-1]);
    }

    return 0;
}


