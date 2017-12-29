#include <stdio.h>
#include <map>

using namespace std;//no terminado!!!!!

int main(){
    freopen("salida.txt", "w", stdout);
    int casos, n, x;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        map<int, int> mapa;
        int may = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            mapa[x]++;
            may = max(may, mapa[x]);
        }
        printf("%d\n", (n % may)? (n/may) + 1: n/may);
    }
}
