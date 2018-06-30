#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, k, x;

    while(scanf("%d", &n), n){
        set<ii> facturas;
        map<int, int> mapa;
        int a, b;
        long acum = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &k);

            for(int j = 0; j < k; j++){
                scanf("%d", &x);
                facturas.insert(ii(x, mapa[x]++));
            }

            a = (*facturas.begin()).first;
            b = (*facturas.rbegin()).first;
            //printf("mayor= %d , menor= %d ", b, a);
            facturas.erase(facturas.begin());
            facturas.erase(--facturas.end());
            acum += b - a;
            //printf("acum= %ld , lenSet= %d\n", acum, facturas.size());
        }

        printf("%ld\n", acum);
    }


    return 0;
}


