#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int n, m, q, x, y, w, l;

    while(scanf("%d %d", &n, &m), n, m){
        vector<vi> arr;
        for(int i = 0; i < n; i++){
            vi fila;
            for(int j = 0; j < m; j++){
                scanf("%d", &w);
                fila.push_back(w);
            }
            arr.push_back(fila);
        }

        scanf("%d", &q);
        int may;

        for(int i = 0; i < q; i++){
            scanf("%d %d", &x, &y);
            vector<int>::iterator it;
            may = 0;

            for(int j = 0; j < n; j++){
                it = lower_bound(arr[j].begin(), arr[j].end(), x);
                int con = 0, fil = j, col = it - arr[j].begin();
                //cout << "comenzamos desde columna: " << col;
                while(fil < n && col < m && arr[fil][col] <= y){
                    con++; fil++; col++;
                }
                //cout << " longitud: " << con << endl;
                may = max(may, con);
            }

            printf("%d\n", may);
        }

        printf("-\n");
    }

    return 0;
}


