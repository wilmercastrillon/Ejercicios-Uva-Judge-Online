#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n;

    while(scanf("%d", &n) != EOF){
        int ant = 0, act = 1;
        int numAnt, numAct, res = 1;
        scanf("%d", &numAnt);

        for(int i = 1; i < n; i++){
            scanf("%d", &numAct);
            if(numAnt > numAct){
                //printf("anterior mayor, act=%d\n", act);
                res = max(res, ant+act);
                ant = act;
                act = 1;
            }else{
                act++;
                //printf("actual mayor o igual , act=%d\n", act);
                res = max(res, ant+act);
            }
            numAnt = numAct;
        }
        res = max(res, ant+act);

        printf("%d\n", res);
    }

    return 0;
}


