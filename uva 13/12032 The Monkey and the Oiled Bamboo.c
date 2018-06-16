#include <stdio.h>

int main(){
    int t, n, x, may, res, dif, ant, caso=1;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        may = 0;
        res = 0;
        ant = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            dif = x-ant;
            if(dif==res){
                res--;
            }else if(dif > res){
                if(dif > may){
                    may = dif;
                    res = may-1;
                }else{
                    may++;
                    res = may;
                }
            }
            //printf("may %d, res %d\n", may, res);
            ant = x;
        }
        printf("Case %d: %d\n", caso++, may);
    }

    return 0;
}
