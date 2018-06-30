#include <stdio.h>
#include <iostream>

using namespace std;

int arr[100010], tab[100010][10];

void llenar(int tam){
    for(int i = 0; i < 10; i++) tab[0][i] = 0;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < 10; j++){
            tab[i + 1][j] = tab[i][j];
        }
        tab[i + 1][arr[i]]++;
    }
}

int contar(int x, int y){
    int con = 0;
    x--;
    for(int j = 0; j < 10; j++){
        if(tab[y][j] - tab[x][j]) con++;
    }
    return con;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y;

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        llenar(n);

        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            printf("%d\n", contar(x, y));
        }
    }

    return 0;
}
