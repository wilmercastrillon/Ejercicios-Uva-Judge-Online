#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

char tab[5][5], cad[20];
bool vis[5][5], found;
int mf[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int len;

bool val(int f, int c){
    return !(f<0 || f>=4 || c<0 || c>= 4 || vis[f][c]);
}

void backtraking(int f, int c, int pos){
    if(pos == len-1){
        found = true;
        return;
    }
    int af, ac;

    for(int i = 0; i < 8 && !found; i++){
        af = f+mf[i];
        ac = c+mc[i];
        if(val(af, ac) && tab[af][ac] == cad[pos+1]){
            vis[f][c] = true;
            backtraking(af, ac, pos+1);
            vis[f][c] = false;
        }
    }
}

int puntaje(int l){
    if(l < 3) return 0;
    if(l < 4) return 1;
    if(l < 7) return l-3;
    if(l < 8) return 5;
    return 11;
}

int main(){
    int t, q;
    scanf("%d", &t);

    for(int caso = 1; caso <= t; caso++){
        for(int i = 0; i < 4; i++){
            scanf("%s", &tab[i]);
        }

        int res = 0;
        scanf("%d", &q);
        while(q--){
            scanf("%s", &cad);
            len = strlen(cad);
            memset(vis, false, sizeof(vis));

            for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
            if(tab[i][j] == cad[0]){
                found = false;
                vis[i][j] = true;
                backtraking(i, j, 0);
                vis[i][j] = false;
                if(found){
                    res += puntaje(len);
                    j = 5; i = 5;
                    break;
                }
            }
        }
        printf("Score for Boggle game #%d: %d\n", caso, res);
    }

    return 0;
}


