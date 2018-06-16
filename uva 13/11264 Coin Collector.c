#include <stdio.h>

int main(){
    int t, n, con, i, j;
    long c, acum = 0, ant;
    scanf("%d", &t);

    for(j = 0; j < t; j++){
        scanf("%d", &n);
        scanf("%ld", &c);
        acum = 0;
        ant = c;
        con = 1;

        for(i = 1; i < n; i++){
            scanf("%ld", &c);
            if(acum + ant < c){
                acum += ant;
                con++;
            }
            ant = c;
        }
        printf("%d\n" ,con);
    }

    return 0;
}

