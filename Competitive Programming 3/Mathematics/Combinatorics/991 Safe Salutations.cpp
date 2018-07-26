#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long int lli;

lli catalan[15];

void pre(){
    catalan[0] = 1;
    for(int i = 1; i < 15; i++){
        catalan[i] = ((2*i)*(2*i-1)*catalan[i-1])/((1+i)*i);
    }
}

int main(){
    int n;
    pre();
    scanf("%d", &n);

    while(true){
        printf("%lld\n", catalan[n]);
        if(scanf("%d", &n) == EOF) break;
        printf("\n");
    }

    return 0;
}


