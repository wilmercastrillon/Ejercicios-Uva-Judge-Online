#include <stdio.h>

int main(){
    int t, n;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        if(n > 2) printf("%.3f\n", pow(n,2.0)-pow(n-2.0,2.0)+pow(n-2.0,2.0)*sqrt(2.0));
        else if(n == 2) printf("4.000\n");
        else printf("0.000\n");
    }
    return 0;
}
