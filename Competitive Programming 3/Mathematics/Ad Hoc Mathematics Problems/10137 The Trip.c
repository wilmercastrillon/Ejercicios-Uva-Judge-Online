#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    //freopen("salida.txt","w",stdout);
    int n, i, j, avg, avg2, aux, aux2, acum, ar[1010];
    char x[10];

    while(scanf("%d",&n),n){
        acum = avg = aux = 0;
        for(i = 0; i < n; ++i){
            scanf("%s",&x);
            ar[i] = 0;
            for(j=0; j<strlen(x);++j){
                if(x[j]=='.') continue;
                ar[i] *= 10;
                ar[i] += (x[j]-'0');
            }
            aux += ar[i];
        }
        avg = avg2 = aux/n;
        if((aux%n) > 0) avg++;

        aux = aux2 = 0;
        for(i = 0; i < n; ++i){
            if(ar[i] > avg)
                aux += (ar[i]-avg);
            else if(ar[i]<avg2) aux2 += (avg2-ar[i]);
        }

        if(aux > aux2) printf("$%d.%02d\n",aux/100,aux%100);
        else printf("$%d.%02d\n",aux2/100,aux2%100);
    }

    return 0;
}


