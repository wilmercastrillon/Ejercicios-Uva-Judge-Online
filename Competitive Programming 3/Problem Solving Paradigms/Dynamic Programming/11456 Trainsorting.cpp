#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int A[2001], D[2001], n;
int inc[2001], dec[2001];

int LIS_dp(){
    int res1 = 0, res2 = 0;
    int sol = 0;

    memset(inc, 0, sizeof(inc));
    memset(dec, 0, sizeof(dec));

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(D[i] < D[j]) inc[j] = max(inc[j], inc[i] + 1);
            if(D[i] > D[j]) dec[j] = max(dec[j], dec[i] + 1);
        }
    }

    for(int i = 0; i < n; i++){
        //printf("%3d ", inc[i]+1);
        //printf("%3d\n", dec[i]+1);
        sol = max(sol, inc[i] + dec[i] + 1);
    }

    return sol;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
            D[(n - i) - 1] = A[i];
        }
        printf("%d\n", LIS_dp());
    }

    return 0;
}


