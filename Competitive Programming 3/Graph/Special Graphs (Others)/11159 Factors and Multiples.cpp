#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi grafo;
int a[110], b[110], match[210];
bool vis[210];

int augment(int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    for (int v : grafo[u]) {
        if (match[v] == -1 || augment(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int maxMatching(int tam){
    memset(match, -1, sizeof(match));
    int ans = 0;
    for(int i = 0; i < tam; i++){
        memset(vis, false, sizeof(vis));
        ans += augment(i);
    }
    return ans;
}

void addEdge(int x, int y){
    //printf("conexion de %d a %d\n", x, y);
    grafo[x].push_back(y);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, caso = 0, t;
    scanf("%d", &t);

    while(t--){
        grafo.assign(201, vi(0));
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);


        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &b[i]);
            for(int j = 0; j < n; j++){
                if(a[j]==b[i]) addEdge(j, n+i);
                else if(a[j]!=0 && b[i]%a[j] == 0) addEdge(j, n+i);
            }
        }

        int l = n+m;
        printf("Case %d: %d\n", ++caso, maxMatching(n));
    }

    return 0;
}


