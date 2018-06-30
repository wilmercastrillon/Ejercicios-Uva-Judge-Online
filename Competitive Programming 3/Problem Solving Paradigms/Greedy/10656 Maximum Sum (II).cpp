#include <stdio.h>

using namespace std;
int arr[1010];

int main(){

    int n, x, l;
    while(scanf("%d", &n), n){
        l = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            if(x){
                arr[l++] = x;
            }
        }

        if(l)printf("%d", arr[0]);
        else printf("0");
        for(int i = 1; i < l; i++)
            printf(" %d", arr[i]);
        printf("\n");
    }

    return 0;
}
