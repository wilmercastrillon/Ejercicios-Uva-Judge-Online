#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, x;
    scanf("%d", &n);

    while(n){
        vector<int> vi;
        int con = 1, may = 1;

        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            vi.push_back(x);
        }
        sort(vi.begin(), vi.end());
        for(int i = 1; i < n; i++){
            if(vi[i] != vi[i-1]) con = 1;
            else con++;
            may = max(may, con);
        }

        printf("%d\n", may);
        for(int j = 0; j < may; j++){
            printf("%d", vi[j]);
            for(int k = j+may; k < n; k += may){
                printf(" %d", vi[k]);
            }
            printf("\n");
        }
        scanf("%d", &n);
        if(n) printf("\n");
    }

    return 0;
}


