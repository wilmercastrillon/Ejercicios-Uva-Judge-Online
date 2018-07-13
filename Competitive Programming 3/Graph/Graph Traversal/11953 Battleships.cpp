#include <stdio.h>

using namespace std;

int n;
char tab[110][110];
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return !(f<0 || f>=n || c<0 || c>=n || tab[f][c]=='.');
}

bool x;
void dfs(int f, int c){
    //printf("llega %d %d, antes %c\n", f, c, tab[f][c]);
    x = x || (tab[f][c]=='x');
    tab[f][c] = '.';
    //printf("despues %c\n", tab[f][c]);
    int af, ac;
    for(int i = 0; i < 4; i++){
        af = f+mf[i]; ac = c+mc[i];
        if(val(af, ac)) dfs(af, ac);
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%s", &tab[j]);

        int con = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(tab[j][k] != '.'){
                    x = false;
                    dfs(j, k);
                    con += x;
                }
            }
        }

        printf("Case %d: %d\n", i, con);
    }

    return 0;
}


