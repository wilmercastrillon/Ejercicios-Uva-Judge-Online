#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, total[2];
vvi lista;
vector<int> color;

bool bfs(int nodo, int c){
    int aux, next, x;
    queue<int> cola;
    cola.push(nodo);
    color[nodo] = c;
    total[c]++;

    while(cola.size()){
        aux = cola.front();
        //printf("llega %d, tiene %d vecinos, color %d\n", aux, lista[aux].size(), color[aux]);
        cola.pop();
        next = 1 - color[aux];

        for(int i = 0; i < lista[aux].size(); i++){
            x = lista[aux][i];
            if(color[x] == -1){
                color[x] = next;
                total[next]++;
                cola.push(x);
            }else if(color[x] == color[aux]) return false;
        }
    }
    return true;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, x, y;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        lista.assign(n, vi(0));
        color.assign(n, -1);

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(y);
            lista[y].push_back(x);
        }

        int acum = 0;
        bool res = true;

        for(int i = 0; i < n && res; i++){
            if(color[i] == -1){
                total[0] = total[1] = 0;
                res = bfs(i, 0);
                if(total[0] && total[1]) acum += min(total[0], total[1]);
                else acum += max(total[0], total[1]);
            }
        }
        printf("%d\n", (res)? acum: -1);
    }

    return 0;
}


