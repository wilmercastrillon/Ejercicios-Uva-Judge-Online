#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi lista;
int memo[1000];

int dp(int pos){
    if(!lista[pos].size()) return 1;
    if(memo[pos] != -1) return memo[pos];

    int ans = 0;
    for(int i = 0; i < lista[pos].size(); i++){
        ans += dp(lista[pos][i]);
    }
    return memo[pos] = ans;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x;
    scanf("%d", &n);

    while(true){
        lista.assign(n+1, vi(0));

        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &x);
                lista[i].push_back(x);
            }
        }

        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(0));
        if(scanf("%d", &n) != EOF){
            printf("\n");
        }else break;
    }

    return 0;
}


