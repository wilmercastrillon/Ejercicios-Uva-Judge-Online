#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli sum[510][510], cont[510][510];
double pwin[510];

void pre(){
    forr(i, 510){
        sum[0][i] = 1;
        sum[i][1] = 1;
    }
    forab(i,1,510){
        forab(j,2,510){
            sum[i][j] = sum[i-1][j] + sum[i][j-1];
        }
    }
}

void pre2(double p, int n){
    cont[0][0] = 1;
    forr(i, n+1){//p ganar i
        pwin[i] = 1.0;
        pwin[i] *= pow(p, i);
        pwin[i] *= pow(1.0-p, n-i);

        int x = 1;
        for(int j = i; j >= 1 && (n-i+2-x)>0; j--){
            printf("%d %d = %d\n", i, j, sum[x][n-(i-1)-(x-1)]);
            cont[i][j] += sum[x][n-(i-1)-(x-1)];
            x++;
        }
    }
}

int n, m, x, y;
double p;

int main(){//No terminado
    pre();

    while(scanf("%d %lf", &n, &p) != EOF){
        memset(cont, 0, sizeof(cont));
        pre2(p, n);

        int l = (n/2) + 1, espejo = 0, inc = 1;
        double res = 0.0, x;
        forab(i,0,n+1){
            for(int j = i; j >= 0 && cont[i][j]; j--){
                res += pwin[i]*j*1.0*cont[i][j]*1.0;
                printf(" %d bits | %d seguidos | %lld cantidad | p = %.5f\n", i, j, cont[i][j], pwin[i]);
            }
            /*if(i+1 == l){
                if(n&1){
                    espejo++;
                }
                inc = -1;
            }*/
        }

        printf("%.8f\n", res);
    }
    return 0;
}


