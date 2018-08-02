#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

char tab[60][60], cad[60];
int mf[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int m, n, len;
ii par;

bool igual(char q, char w){
    if(q>'Z') q = (q-'a')+'A';
    if(w>'Z') w = (w-'a')+'A';
    return q == w;
}

bool val(int f, int c){
    return !(f<0 || f>=m || c<0 || c>= n);
}

void backtraking(int f, int c, int pos, int mov){
    //printf("### f=%d , c=%d , pos=%d , mov=%d\n", f, c, pos, mov);
    if(!val(f, c)) return;
    if(!igual(tab[f][c], cad[pos])) return;
    if(pos == len-1){
        par.first = f;
        par.second = c;
        return;
    }
    backtraking(f+mf[mov], c+mc[mov], pos+1, mov);
}

int main(){
    int t, q;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++){
            scanf("%s", &tab[i]);
        }

        scanf("%d", &q);
        while(q--){
            scanf("%s", &cad);
            len = strlen(cad);

            for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            if(igual(tab[i][j], cad[0]))
                for(int k = 0; k < 8; k++){
                    par.first = -1;
                    backtraking(i+mf[k], j+mc[k], 1, k);
                    if(par.first != -1){
                        printf("%d %d\n", i+1, j+1);
                        j = n; i = m;
                        break;
                    }
                }
        }
        if(t != 0) printf("\n");
    }

    return 0;
}


