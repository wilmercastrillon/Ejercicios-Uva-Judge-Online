#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, k, v;

    while(scanf("%d %d", &n, &m) != EOF){
        vector<vi> lista(1000001);
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            lista[x].push_back(i + 1);
        }

        for(int i = 0; i < m; i++){
            scanf("%d %d", &k, &v);
            if(lista[v].size() < k) printf("0\n");
            else printf("%d\n", lista[v][k - 1]);
        }
    }

    return 0;
}

