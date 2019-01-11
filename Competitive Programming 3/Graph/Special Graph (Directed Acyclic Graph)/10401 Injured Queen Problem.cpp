#include <stdio.h>
#include <vector>
#include <map>
#include <string.h>

using namespace std;
typedef long long int lli;

char cad[20];
int l;
lli memo[20][20];
map<char, int> mapa;

void llenar(){
    for(int i = 1; i < 10; i++) mapa[i+'0'] = i;// printf("%c -> %d\n", i+'0', i);
    for(char c='A'; c < 'M'; c++) mapa[c] = (c-'A')+10;//printf("%c -> %d\n", c, (c-'A')+10);
}

lli dp(int pos, int ant){
    //printf("llamado pos %d, ant %d\n", pos, ant);
    if(pos >= l) return 1;
    if(memo[pos][ant] != -1) return memo[pos][ant];

    if(cad[pos] != '?'){
        int aux = mapa[cad[pos]]-1;
        //printf("debe estar en %d, ant: %d\n", aux, ant);
        if(aux>=ant-1 && aux<=ant+1){
            //printf("cruce!!!!\n");
            return 0;
        }
        return memo[pos][ant] = dp(pos+1, mapa[cad[pos]]-1);
    }

    lli ans = 0;
    for(int i = 0; i < l; i++){
        if(!(i>=ant-1 && i<=ant+1)){
            //printf("ir a %d\n", i);
            ans += dp(pos+1, i);
        }
    }
    //printf("devuelve %d\n", ans);
    return memo[pos][ant] = ans;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    llenar();

    while(scanf("%s", &cad) != EOF){
        l = strlen(cad);
        memset(memo, -1, sizeof(memo));
        lli res = 0;

        if(cad[0]=='?'){
            for(int i = 0; i < l; i++){
                res+= dp(1, i);
                //printf("para %d es %d\n", i, memo[1][i]);
            }
        }else{
            res = dp(1, mapa[cad[0]]-1);
        }

        printf("%lld\n", res);
    }

    return 0;
}

