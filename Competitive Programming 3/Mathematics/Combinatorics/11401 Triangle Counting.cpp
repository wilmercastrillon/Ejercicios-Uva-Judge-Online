#include <stdio.h>
#include <math.h>

using namespace std;
typedef unsigned long long int ulli;

int main(){
    int n;

    while(scanf("%d", &n) && n > 2){
         ulli con = 0, sum, m;

        for(int i = 3; i < n; i+=2){
            m = n - i;
            sum = (ulli) (m*(m+1))/2;
            con += sum;
        }
        printf("%llu\n", con);
    }

    return 0;
}
