#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b)? a: b

using namespace std;

int tab[100010];

void pre(int t){
    for(int i = 1; i < t; i++) tab[i] += tab[i - 1];
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n;

    while(scanf("%d", &n), n){
        memset(tab, 0, sizeof(tab));
        for(int i = 1; i <= n; i++){
            scanf("%d", &tab[i]);
            //printf("i = %d\n", i);
        }
        pre(n+1);

        int res = -1;
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
                res = max(res, tab[j] - tab[i - 1]);

        if(res > 0) printf("The maximum winning streak is %d.\n", res);
        else printf("Losing streak.\n");
    }

    return 0;
}
