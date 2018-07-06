#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int t, n, v[110];
int memo[100][30010];

void solve(){
    memset(memo, 0, sizeof(memo));
    bool sig;
    int aux, lim = (v[0] >= t)? v[0]:30001;
    memo[0][v[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= lim; j++){
            if(memo[i-1][j]){
                if(memo[i][j]) memo[i][j] = min(memo[i-1][j], memo[i][j]);
                else memo[i][j] = memo[i-1][j];
                aux = j + v[i];

                if(memo[i-1][aux]){
                    memo[i][aux] = min(memo[i-1][aux], memo[i-1][j]+1);
                }else{
                    memo[i][aux] = memo[i-1][j]+1;
                }
                if(aux >= t && aux < lim) lim = aux;
                //printf("con j = %d Hay cambio de %d HASTA %d\n", j, memo[i-1][j], memo[i][j]);
            }
        }
        memo[i][v[i]] = 1;
        if(v[i] >= t && v[i] < lim) lim = v[i];
    }

    printf("%d %d\n", lim, memo[n-1][lim]);
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int casos;
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d", &t);
        scanf("%d", &n);

        for(int j = 0; j < n; j++){
            scanf("%d", &v[j]);
        }
        if(n > 1) solve();
        else printf("%d 1\n", v[0]);
    }

    return 0;
}


