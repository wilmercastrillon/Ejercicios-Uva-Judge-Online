#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
        forr(i, n){
            scanf("%d %d", &x, &y);
            puntos.push_back(ii(x, y));
        }

        memo[0][0] = 0.0;//k, n
        forab(i, 1, n){
            memo[0][i] = memo[0][i-1] + dist(puntos[i-1], puntos[i]);
        }

        forab(i, 1, k+1){
            memo[i][0] = 0.0;
            memo[i][1] = dist(puntos[0], puntos[1]);
            forab(j, 2, n){
                memo[i][j] = min(memo[i-1][j-2]+dist(puntos[j-2],puntos[j]),
                                 memo[i][j-1]+dist(puntos[j-1],puntos[j]));
            }
        }

        printf("%.3f\n", memo[k][n-1]);
    }

    return 0;
}


