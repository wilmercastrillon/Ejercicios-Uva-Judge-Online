#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

int menf, mayf, menc, mayc;
int tab[2010][2010];
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return !(f<menf || f>mayf || c<menc || c>mayc);
}

int bfs(queue<ii> cola){
    ii par;
    int f, c, auxf, auxc;
    //int con = 0;
    while(cola.size()){
        //con++;
        //printf("it %d\n", con);
        //if(con == 4000000) printf("4 millones!\n");
        par = cola.front();
        cola.pop();
        f = par.first;
        c = par.second;
        //printf("llegamos a %d %d con dist %d\n", f, c, tab[f][c]);

        for(int i = 0; i < 4; i++){
            auxf = f+mf[i];
            auxc = c+mc[i];
            if(!val(auxf, auxc)) continue;
            if(tab[auxf][auxc] == -1) return tab[f][c] + 1;
            if(tab[f][c] + 1 >= tab[auxf][auxc]) continue;
            tab[auxf][auxc] = tab[f][c] + 1;
            //printf("\tvamos a %d %d con peso %d\n", auxf, auxc, tab[f][c] + 1);
            cola.push(ii(auxf, auxc));
        }
        /*for(int i = 0; i <= mayf; i++){
            for(int j = 0; j <= mayc; j++){
                printf("%12d", tab[i][j]);
            }
            printf("\n");
        }
        printf("\n-------------------------\n");*/
    }
    return -1;
}

int main(){
    int c1, c2, x, y;
    while(scanf("%d", &c1), c1){
        memset(tab, 5436, sizeof(tab));//5436
        queue<ii> cola;
        mayf = mayc = -1;
        menf = menc = 1000000000;

        for(int i = 0; i < c1; i++){
            scanf("%d %d", &x, &y);
            tab[x][y] = -1;
            mayf = max(mayf, x);
            mayc = max(mayc, y);
            menf = min(menf, x);
            menc = min(menc, y);
        }
        scanf("%d", &c2);
        for(int i = 0; i < c2; i++){
            scanf("%d %d", &x, &y);
            tab[x][y] = 0;
            mayf = max(mayf, x);
            mayc = max(mayc, y);
            menf = min(menf, x);
            menc = min(menc, y);
            cola.push(ii(x, y));
        }

        printf("%d\n", bfs(cola));
    }


    return 0;
}


