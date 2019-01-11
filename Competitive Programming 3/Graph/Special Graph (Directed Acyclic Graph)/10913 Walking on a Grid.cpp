#include <stdio.h>
#include <string.h>
#include <algorithm>
#define Ninf -1000000000

using namespace std;

int memo[80][80][8][4], n, k, l;
int tab[80][80], mf[] = {0, 1, 0}, mc[] = {1, 0, -1};

bool val(int f, int c){
    return !(f<0 || f>=n || c<0 || c>=n);
}

int dp(int fil, int col, int neg, int ant){
    //printf("llamado a %d | %d \n", fil, col);
    //printf(" salida ini\n");
    if(tab[fil][col] < 0 && neg > k) return Ninf;
    if(fil==l && col == l) return tab[fil][col];
    if(memo[fil][col][neg][ant] != -1) return memo[fil][col][neg][ant];
    //printf(" salida fin\n");

    int auxf, auxc, ans = Ninf;
    for(int i = 0; i < 3; i++){
        if(ant == 0 && i == 2) continue;
        if(ant == 2 && i == 0) continue;
        auxf = fil + mf[i];
        auxc = col + mc[i];
        if(!val(auxf, auxc)) continue;
        if(tab[auxf][auxc] >= 0) ans = max(ans, tab[fil][col] + dp(auxf, auxc, neg, i));
        else ans = max(ans, tab[fil][col] + dp(auxf, auxc, neg+1, i));
    }

    //printf(" retorna\n");
    return memo[fil][col][neg][ant] = ans;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int men, caso = 1;
    while(scanf("%d %d", &n, &k), n){
        men = -100;
        for(int i = 0; i < n; i++){
            for(int j= 0; j < n; j++){
                scanf("%d", &tab[i][j]);
                if(tab[i][j] < 0) men += tab[i][j];
            }
        }

        l = n-1;
        memset(memo, -1, sizeof(memo));
        int res = dp(0, 0, tab[0][0]<0, 1);
        if(res < men) printf("Case %d: impossible\n", caso++);
        else printf("Case %d: %d\n", caso++, res);
    }

    return 0;
}


