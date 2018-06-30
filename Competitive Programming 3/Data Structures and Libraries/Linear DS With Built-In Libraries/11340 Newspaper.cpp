#include <bits/stdc++.h>

using namespace std;

int main(){

    int casos, letras, lineas;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &letras);
        char x[3], l[10010];
        int aux;
        map<char, int> mapa;

        for(int i = 0; i < letras; i++){
            scanf("%s %d", &x, &aux);
            mapa[x[0]] = aux;
        }

        scanf("%d", &lineas);
        int acum = 0;
        getchar();
        for(int i = 0; i < lineas; i++){
            gets(l);
            int lon = strlen(l);
            for(int j = 0; j < lon; j++) acum += mapa[l[j]];
        }

        printf("%.2f$\n", (double) acum/100);
    }

    return 0;
}

