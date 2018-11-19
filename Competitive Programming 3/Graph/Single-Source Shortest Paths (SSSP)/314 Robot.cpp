#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define mp(a, b, c) iii(a, ii(b, c))

int fil, col, tabini[51][51], tab[51][51][5], d[] = {-1, 1};
int mf2[] = {0, 0, 1, 1}, mf[] = {-1, 0, 1, 0};
int mc2[] = {0, 1, 1, 0}, mc[] = {0, 1, 0, -1};

bool disp(int f, int c){
    bool d = true;
    for(int i = 0; i < 4; i++){
        d = d && (tabini[f+mf2[i]][c+mc2[i]]==0);
    }
    return d;
}

bool val(int f, int c, int dir){
    return !(f<0 || f>=fil-1 || c<0 || c>=col-1 || tab[f][c][dir]==-1);
}
//dir: 0 norte, 1 derecha, 2 abajo, 3 izquierda
int bfs(int xi, int yi, int pos, int xf, int yf){
    queue<iii> cola;
    cola.push(mp(pos, xi, yi));
    iii triple;
    int dir, x, y;
    int nextd, nextx, nexty;
    tab[xi][yi][pos] = 0;
    int con = 0;

    while(cola.size()){
        con++;
        triple = cola.front(); cola.pop();
        dir = triple.first;
        x = triple.second.first;
        y = triple.second.second;
        //printf("llegamos a %d %d con direccion %d\n", x, y, dir);

        for(int i = 0; i < 2; i++){
            nextd = dir + d[i];
            if(nextd < 0) nextd = 3;
            if(nextd > 3) nextd = 0;

            //printf("probamos para %d %d dir %d\n", x, y, nextd);
            if(!val(x, y, nextd)) continue;
            //printf("es valido\n");

            if(tab[x][y][dir]+1 >= tab[x][y][nextd]) continue;
            tab[x][y][nextd] = tab[x][y][dir] + 1;
            cola.push(mp(nextd, x, y));
        }
        for(int i = 1; i <= 3; i++){
            nextx = x + i*mf[dir];
            nexty = y + i*mc[dir];
            //printf("probamos para %d %d con dir %d\n", nextx, nexty, dir);
            if(!val(nextx, nexty, dir)) break;
            if(tab[x][y][dir]+1 >= tab[nextx][nexty][dir]) continue;
            tab[nextx][nexty][dir] = tab[x][y][dir] + 1;
            cola.push(mp(dir, nextx, nexty));
        }
    }
    //printf("it %d\n", con);
    return min(tab[xf][yf][0], min(tab[xf][yf][1], min(tab[xf][yf][2], tab[xf][yf][3])));
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int q, w, e, r, pos, res;
    char cad[10];

    while(scanf("%d %d", &fil, &col), fil){
        for(int i = 0; i < fil; i++){
            for(int j = 0;  j < col; j++){
                scanf("%d", &tabini[i][j]);
            }
        }

        memset(tab, 5436, sizeof(tab));
        int f = fil-1, c = col-1;
        for(int i = 0; i < f; i++){
            for(int j = 0; j < c; j++){
                if(!disp(i, j)){
                    tab[i][j][0] = -1;
                    tab[i][j][1] = -1;
                    tab[i][j][2] = -1;
                    tab[i][j][3] = -1;
                }
                //printf("%14d", tab[i][j][0]);
            }
            //printf("\n");
        }
        //printf("\n");

        scanf("%d %d %d %d %s", &q, &w, &e, &r, &cad);
        q--; w--; e--; r--;
        if(cad[0] == 'n') pos = 0;
        else if(cad[0] == 'e') pos = 1;
        else if(cad[0] == 's') pos = 2;
        else pos = 3;

        res = bfs(q, w, pos, e, r);
        if(res > 1000000000){
            printf("-1\n");
        }else{
            printf("%d\n", res);
        }
    }


    return 0;
}
