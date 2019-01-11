#include <stdio.h>
#include <string.h>

using namespace std;

char tab[110][110];
int memo[110][110], n, mod = 1000007;
int mf[] = {-1, -1}, mc[] = {-1, 1};

bool val(int f, int c){
    return !(f<0 || f>=n || c<0 || c>=n || tab[f][c]=='B');
}

int dp(int f, int c){
    if(f==0) return 1;
    if(memo[f][c] != -1) return memo[f][c];

    int auxf, auxc, ans = 0;
    for(int i = 0; i < 2; i++){
        auxf = f+mf[i];
        auxc = c+mc[i];
        if(val(auxf, auxc)){
            ans = (ans + dp(auxf, auxc)) % mod;
        }else{
            auxf = f+mf[i]*2;
            auxc = c+mc[i]*2;
            if(val(auxf, auxc)){
                ans = (ans + dp(auxf, auxc)) % mod;
            }
        }
    }

    return memo[f][c] = ans;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int t, inif, inic;
    scanf("%d", &t);

    for(int k = 1; k <= t; k++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", &tab[i]);
            for(int j = 0; j < n; j++){
                if(tab[i][j] == 'W'){
                    inif = i;
                    inic = j;
                }
            }
        }

        memset(memo, -1, sizeof(memo));
        printf("Case %d: %d\n", k, dp(inif, inic));
    }

    return 0;
}


