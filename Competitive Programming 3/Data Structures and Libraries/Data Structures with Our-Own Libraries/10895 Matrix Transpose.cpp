#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, r, x;

    while(scanf("%d %d", &n, &m) != EOF){
        vector<vii> lista(m);

        for(int i = 0; i < n; i++){
            scanf("%d", &r);
            vi aux;
            for(int j = 0; j < r; j++){
                scanf("%d", &x);
                aux.push_back(x);
            }

            for(int j = 0; j < r; j++){
                scanf("%d", &x);
                lista[aux[j] - 1].push_back(ii(x, i + 1));
            }
        }

        printf("%d %d\n", m, n);
        for(int i = 0; i < m; i++){
            printf("%d", lista[i].size());
            for(int j = 0; j < lista[i].size(); j++) printf(" %d", lista[i][j].second);
            printf("\n");

            for(int j = 0; j < (int) lista[i].size() - 1; j++) printf("%d ", lista[i][j].first);
            if(lista[i].size()) printf("%d", lista[i][lista[i].size() - 1].first);
            printf("\n");
        }
    }
}

