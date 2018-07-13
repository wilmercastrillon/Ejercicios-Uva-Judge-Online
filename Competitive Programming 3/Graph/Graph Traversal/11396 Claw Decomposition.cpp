#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vvi lista;
vector<int> color;

bool bfs(int nodo, int c){
    int aux, next, x;
    queue<int> cola;
    cola.push(nodo);
    color[nodo] = c;

    while(cola.size()){
        aux = cola.front();
        cola.pop();
        next = 1 - color[aux];

        for(int i = 0; i < lista[aux].size(); i++){
            x = lista[aux][i];
            if(color[x] == -1){
                color[x] = next;
                cola.push(x);
            }else if(color[x] == color[aux]) return false;
        }
    }
    return true;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int x, y;

    while(scanf("%d", &n), n){
        lista.assign(n+1, vi(0));
        color.assign(n+1, -1);

        while(scanf("%d %d", &x, &y), x && y){
            lista[x].push_back(y);
            lista[y].push_back(x);
        }

        bool res = true;
        for(int i = 1; i <= n && res; i++){
            if(color[i] == -1) res = bfs(i, 0);
        }
        printf("%s\n", (res)? "YES": "NO");
    }

    return 0;
}


