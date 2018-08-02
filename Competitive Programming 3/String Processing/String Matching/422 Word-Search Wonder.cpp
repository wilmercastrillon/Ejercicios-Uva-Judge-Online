#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

char tab[110][110], cad[110];
int mf[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int l, len;
ii par;

bool val(int f, int c){
    return !(f<0 || f>=l || c<0 || c>= l);
}

void backtraking(int f, int c, int pos, int mov){
    //printf("### f=%d , c=%d , pos=%d , mov=%d\n", f, c, pos, mov);
    if(!val(f, c)) return;
    if(tab[f][c] != cad[pos]) return;
    if(pos == len-1){
        par.first = f;
        par.second = c;
        return;
    }
    backtraking(f+mf[mov], c+mc[mov], pos+1, mov);
}

int main(){
    while(scanf("%d", &l) != EOF){
        for(int i = 0; i < l; i++){
            scanf("%s", &tab[i]);
        }

        while(scanf("%s", &cad), cad[0] != '0'){
            len = strlen(cad);
            bool found = false;
            for(int i = 0; i < l; i++)
            for(int j = 0; j < l; j++)
                if(tab[i][j] == cad[0])
                    for(int k = 0; k < 8; k++){
                        par.first = -1;
                        backtraking(i+mf[k], j+mc[k], 1, k);
                        if(par.first != -1){
                            printf("%d,%d %d,%d\n", i+1, j+1, par.first+1, par.second+1);
                            j = l; i = l;
                            found = true;
                            break;
                        }
                    }
            if(!found) printf("Not found\n");
        }
    }

    return 0;
}


