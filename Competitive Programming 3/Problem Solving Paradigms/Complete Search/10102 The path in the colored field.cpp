#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

int m, tab[1010][1010];
char matriz[1010][1010];
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return (f >= 0 && f < m && c >= 0 && c < m);
}

int bfs(queue<ii> &cola, queue<int> &pasos){
    int f, c, p, ini1 = cola.size();
    ii par;

    while(cola.size()){
        par = cola.front(); cola.pop();
        p = pasos.front(); pasos.pop();
        f = par.first;
        c = par.second;
        if(!val(f, c) || tab[f][c]) continue;

        tab[f][c] = p;
        if(matriz[f][c] == '3') return p;

        for(int i = 0; i < 4; i++){
            pasos.push(p + 1);
            cola.push(ii(f + mf[i], c + mc[i]));
        }
    }
    return 1;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    while(scanf("%d", &m) != EOF){

        for(int i = 0; i < m; i++) scanf("%s", &matriz[i]);

        int may = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++)
                if(matriz[i][j] == '1'){
                    memset(tab, 0, sizeof(tab));
                    queue<int> paso;
                    queue<ii> cola;
                    cola.push(ii(i, j));
                    paso.push(1);
                    may = max(may, bfs(cola, paso) - 1);
                }
        }

        printf("%d\n", may);
    }

    return 0;
}


