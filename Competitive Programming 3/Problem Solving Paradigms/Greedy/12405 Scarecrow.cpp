#include <stdio.h>

using namespace std;

int main(){
    int t, n, res;
    char cad[200];
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        scanf("%s", &cad);
        res = 0;

        for(int j = 0; j < n; ){
            if(cad[j] == '.'){
                res++;
                j+=3;
            }else j++;
        }
        printf("Case %d: %d\n", i+1, res);
    }

    return 0;
}


