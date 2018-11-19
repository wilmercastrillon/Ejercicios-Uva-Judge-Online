#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define mp(a, b, c) iii(a, ii(b, c))

int fil, col, tab[1010][1010];
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return !(f<0 || f >= fil || c<0 || c>=col || tab[f][c]==-1);
}

int bfs(int xi, int yi, int xf, int yf){
    queue<ii> cola;
    cola.push(ii(xi, yi));
    ii par;
    tab[xi][yi] = 0;
    int auxx, auxy;
    int con = 0;

    while(cola.size()){
        con++;
        par = cola.front();
        cola.pop();
        //printf("llegamos a %d %d con peso %d\n", par.first, par.second, t.first);

        for(int i = 0; i < 4; i++){
            auxx = par.first + mf[i];
            auxy = par.second + mc[i];
            if(!val(auxx, auxy))continue;
            //printf("para ir a %d %d es valido\n", auxx, auxy);
            if(tab[par.first][par.second]+1 >= tab[auxx][auxy]) continue;
            tab[auxx][auxy] = tab[par.first][par.second]+1;
            //printf("si %d es mayor a %d\n", t.first + 1, tab[auxx][auxy]);
            cola.push(ii(auxx, auxy));
        }
    }

    /*for(int i = 0; i < fil; i++){
        for(int j = 0; j < col; j++){
            printf("%4d", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    //printf("it = %d\n", con);
    return tab[xf][yf];
}

int main(){
    int b, f, can, x, q, w, e, r;

    while(scanf("%d %d", &fil, &col), fil){
        scanf("%d", &b);
        memset(tab, 5436, sizeof(tab));

        for(int i = 0; i < b; i++){
            scanf("%d %d", &f, &can);
            for(int j = 0; j < can; j++){
                scanf("%d", &x);
                tab[f][x] = -1;
            }
        }

        scanf("%d %d", &q, &w);
        scanf("%d %d", &e, &r);
        printf("%d\n", bfs(q, w, e, r));
    }

    return 0;
}


