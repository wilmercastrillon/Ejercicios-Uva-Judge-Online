#include <stdio.h>

using namespace std;

unsigned long long int memo[45];
void pre(){
    memo[1] = 1; memo[2] = 5; memo[3] = 11;
    for(int i = 4; i < 42; i++)
        memo[i] = memo[i-1]+ 4*memo[i-2] + 2*memo[i-3];
}

int main(){
    int n, t;
    pre();
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        printf("%llu\n", memo[n]);
    }

    return 0;
}
