#include <stdio.h>
#include <string.h>

using namespace std;

int dir[50010], n;
int dist[50010];
bool vis[50010];

int dfs(int nodo){
    if(vis[nodo]) return 0;
    vis[nodo] = true;
    int next = dfs(dir[nodo]);
    vis[nodo] = false;
    return dist[nodo] = 1 + next;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    int t, x, y;
    scanf("%d", &t);

    for(int i = 1; i<= t; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d %d", &x, &y);
            dir[x] = y;
            vis[j+1] = false;
            dist[j+1] = -1;
        }

        for(int j = 1; j <= n; j++){
            if(dist[j] == -1) dfs(j);
        }

        int may = 0, res = 0, aux;
        for(int j = 1; j <= n; j++){
            //memset(vis, false, sizeof(vis));
            //memset(dist, -1, sizeof(dist));
            aux = dist[j];
            //aux = dfs(j);
            if(aux > may){
                may = aux;
                res = j;
            }
            //printf("%d tiene %d\n", j, aux);
        }
        printf("Case %d: %d\n", i, res);
    }

    return 0;
}


