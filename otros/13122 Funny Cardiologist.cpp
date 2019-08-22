#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#define inf 1000000000
#define forab(i, a, b) for(int i = a; i < b; i++)
#define forr(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> ii;

double memo[300][300];
vector<ii> puntos;

double dist(ii &a, ii &b){
    return hypot(a.first-b.first, a.second-b.second);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, k, x, y;

    while(scanf("%d %d", &n, &k) != EOF){
        puntos.clear();
        forr(i, n){
            scanf("%d %d", &x, &y);
            puntos.push_back(ii(x, y));
        }

        memo[0][0] = 0.0;//k, n
        forab(i, 1, n){
            memo[0][i] = memo[0][i-1] + dist(puntos[i-1], puntos[i]);
        }

        forab(i, 1, k+1){
            memo[i][i-1] = memo[i-1][i-1];
            forab(j, i, n){
                memo[i][j] = 1e8;
                for(int l = 0; l<=i && (l+1)<=j; l++){
                    memo[i][j] = min(memo[i][j],memo[i-l][j-(l+1)]+dist(puntos[j-(l+1)],puntos[j]));
                }
            }
        }

        printf("%.3f\n", memo[k][n-1]);
    }

    return 0;
}


