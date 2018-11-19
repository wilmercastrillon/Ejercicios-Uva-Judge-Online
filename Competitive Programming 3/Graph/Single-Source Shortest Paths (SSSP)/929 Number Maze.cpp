#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define mp(a, b, c) iii(a, ii(b, c))

int fil, col, tab[1000][1000], dist[1000][1000];
int mf[] = {-1, 0, 1, 0};
int mc[] = {0, 1, 0, -1};

bool val(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col);
}

int dijkstra(){
    memset(dist, 5436, sizeof(dist));
    priority_queue<iii> cola;
    cola.push(mp(-tab[0][0], 0, 0));
    int f, c, d, auxf, auxc, auxd;
    iii t;

    while(cola.size()){
        t = cola.top();
        cola.pop();
        d = -t.first;
        f = t.second.first;
        c = t.second.second;
        if(d >= dist[f][c]) continue;
        dist[f][c] = d;

        for(int i = 0; i < 4; i++){
            auxf = f + mf[i];
            auxc = c + mc[i];
            if(!val(auxf, auxc)) continue;
            auxd = d + tab[auxf][auxc];
            if(dist[auxf][auxc] > auxd){
                cola.push(mp(-auxd, auxf, auxc));
            }
        }
    }

    return dist[fil-1][col-1];
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &fil);
        scanf("%d", &col);
        for(int j = 0; j < fil; j++){
            for(int k = 0; k < col; k++){
                scanf("%d", &tab[j][k]);
            }
        }

        printf("%d\n", dijkstra());
    }
    return 0;
}


