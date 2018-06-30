#include <bits/stdc++.h>

using namespace std;

int der[100010];
int izq[100010];

int main(){
    //freopen("salida.txt", "w", stdout);
    int s, b, q, w;
    while(scanf("%d %d", &s, &b), s, b){
        for(int i = 0; i <= s; i++){
            izq[i] = i - 1;
            der[i] = i + 1;
        }
        izq[0] = der[0] = 0;
        der[s] = der[s + 1] = 0;
        izq[s + 1] = 0;

        for(int i = 0; i < b; i++){
            scanf("%d %d", &q, &w);
            if(izq[q]) printf("%d ", izq[q]);
            else printf("* ");

            if(der[w]) printf("%d\n", der[w]);
            else printf("*\n");

            der[izq[q]] = der[w];
            izq[der[w]] = izq[q];
        }
        printf("-\n");
    }

    return 0;
}


