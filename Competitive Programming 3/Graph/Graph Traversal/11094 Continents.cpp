#include <stdio.h>
#include <algorithm>

using namespace std;

int fil, col;
char tab[21][21], tierra;
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col || tab[f][c] != tierra);
}

int dfs(int f, int c){
    tab[f][c] = ' ';
    int af, ac, res = 1;
    for(int i = 0; i < 4; i++){
        af = mf[i]+f; ac = c+mc[i];
        if(ac == col) ac = 0;
        if(ac == -1) ac = col-1;
        if(val(af, ac)) res += dfs(af, ac);
    }
    return res;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int q, w;

    while(scanf("%d %d", &fil, &col) != EOF){
        for(int i = 0; i < fil; i++)
            scanf("%s", &tab[i]);

        scanf("%d %d", &q, &w);
        tierra = tab[q][w];
        dfs(q, w);
        //printf("----%d\n", dfs(0, 0));

        int res = 0;
        for(int i = 0; i < fil; i++){
            for(int j = 0; j < col; j++){
                //printf("%c", tab[i][j]);
                if(tab[i][j] == tierra){
                    res = max(res, dfs(i, j));
                }
            }
            //printf("\n");
        }
        printf("%d\n", res);
    }

    return 0;
}


