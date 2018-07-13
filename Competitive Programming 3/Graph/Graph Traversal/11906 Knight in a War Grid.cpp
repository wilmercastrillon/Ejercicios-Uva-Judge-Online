#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> ii;

int r, c, n, m, par, impar;
int tab[110][110];
vector<ii> mov;
set<ii> dif;

bool val(int fil, int col){
    return !(fil<0 || fil>=r || col<0 || col>=c || tab[fil][col] == -1);
}

int dfs(int fil, int col){
    int can = 0;
    //printf("(%d, %d) puede moverse a:\n", fil, col);
    for(int i = 0; i < mov.size(); i++){
        if(val(fil+mov[i].first, col+mov[i].second)){
            can++;
            //printf("%d, %d    --- cambios: ", fil+mov[i].first, col+mov[i].second);
            //printf("%d %d\n", mov[i].first, mov[i].second);
        }
    }
    //printf("total %d\n\n", can);
    tab[fil][col] = can;
    par += !(can&1);
    impar += can&1;

    int auxf, auxc;
    for(int i = 0; i < mov.size(); i++){
        auxf = fil+mov[i].first;
        auxc = col+mov[i].second;
        if(val(auxf, auxc) && tab[auxf][auxc] == 0)
            dfs(auxf, auxc);
    }
}

int main(){
    int t, w, x, y;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d %d %d %d", &r, &c, &m, &n);
        memset(tab, 0, sizeof(tab));
        scanf("%d", &w);
        for(int j = 0; j < w; j++){
            scanf("%d %d", &x, &y);
            tab[x][y] = -1;
        }

        mov.clear();
        dif.clear();
        dif.insert(ii(m, n));
        dif.insert(ii(m, -n));
        dif.insert(ii(-m, n));
        dif.insert(ii(-m, -n));
        dif.insert(ii(n, m));
        dif.insert(ii(n, -m));
        dif.insert(ii(-n, m));
        dif.insert(ii(-n, -m));
        for(set<ii>::iterator it = dif.begin(); it != dif.end(); it++){
            mov.push_back(ii((*it).first, (*it).second));
        }
        par = impar = 0;

        dfs(0, 0);
        printf("Case %d: %d %d\n", i, par, impar);
    }

    return 0;
}


