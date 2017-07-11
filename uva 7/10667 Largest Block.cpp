#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b)? a: b

using namespace std;

int tab[110][110], n;

int main(){
    int casos, f1, c1, f2, c2, b;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        scanf("%d", &b);

        memset(tab, 0, sizeof(tab));

        for(int i = 0; i < b; i++){
            scanf("%d %d %d %d", &f1, &c1, &f2, &c2);
            for(int j = f1 - 1; j < f2; j++)
                for(int k = c1 - 1; k < c2; k++) tab[j][k] = 1;
        }

        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(i) tab[i][j] += tab[i - 1][j];
            if(j) tab[i][j] += tab[i][j - 1];
            if(i && j) tab[i][j] -= tab[i-1][j-1];
        }

        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) printf("%3d", tab[i][j]);
            printf("\n");
        }*/

        int men = 100000, aux, res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
            for(int k = i; k < n; k++) for(int l = j; l < n; l++){
                aux = tab[k][l];
                if(i) aux -= tab[i - 1][l];
                if(j) aux -= tab[k][j-1];
                if(i && j) aux += tab[i - 1][j - 1];
                if(!aux) res = max(res, (k - (i - 1)) * (l - (j - 1)));
            }

        printf("%d\n", res);
    }
    return 0;
}
