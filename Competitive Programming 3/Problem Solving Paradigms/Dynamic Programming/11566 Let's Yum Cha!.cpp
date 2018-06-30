#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define infN -1000000000

using namespace std;

int memo[110][1010][22];//pos, gastado, platos restantes.
int v[110], costo[110], n, x, t, k, platos;

int dp(int pos, int acum, int res){
    int total = ceil((double) acum * 1.1L);
    if(total > x || res > platos) return infN;
    if(pos == k || total == x || res == platos) return 0;

    if(memo[pos][acum][res] != -1) return memo[pos][acum][res];

    int aux = dp(pos+1, acum, res);//no tomar
    int aux2 = v[pos] + dp(pos+1, acum + costo[pos], res+1);//tomar 1
    int aux3 = v[pos]*2 + dp(pos+1, acum + costo[pos]*2, res+2);//tomar 2

    return memo[pos][acum][res] = max(aux, max(aux2, aux3));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int aux;

    while(scanf("%d %d %d %d", &n, &x, &t, &k), n, k){
        for(int i = 0; i < k; i++){
            scanf("%d", &costo[i]);
            aux = v[i] = 0;

            for(int j = 0; j <= n; j++){
                scanf("%d", &aux);
                v[i] += aux;
            }
        }
        t = t*(n+1); x = x*(n+1);//costo total del te y total de dinero
        platos = (n+1)<<1;

        memset(memo, -1, sizeof(memo));
        printf("%.2f\n", (double) dp(0, t, 0) / (double)(n+1));
    }

    return 0;
}


/*int dp(int pos, int acum, int res){
    if(pos == k || res == platos) return 0;
    if(memo[pos][acum][res] != -1) return memo[pos][acum][res];

    int aux = dp(pos+1, acum, res), aux2 = 0, aux3 = 0;//no tomar
    if(ceil((double)(costo[pos] + acum)*1.1) <= x && res+1 <= platos)
        aux2 = v[pos] + dp(pos+1, acum + costo[pos], res+1);//tomar 1
    if(ceil((double)(costo[pos]*2 + acum)*1.1) <= x && res+2 <= platos)
        aux3 = v[pos]*2 + dp(pos+1, acum + costo[pos]*2, res+2);//tomar 2

    return memo[pos][acum][res] = max(aux, max(aux2, aux3));
}*/
