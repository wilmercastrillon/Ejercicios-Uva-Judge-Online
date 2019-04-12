#include <bits/stdc++.h>

using namespace std;

int degree[210];

int main(){//NO TERMINADO
    int n, r, x, y;

    while(scanf("%d %d", &n, &r) != EOF){
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < r; i++){
            scanf("%d %d", &x, &y);
            degree[x]++;
            degree[y]++;
        }
        bool pos = true;
        for(int i = 0; i < n && pos; i++){
            pos = pos && !(degree[i]&1) && degree[i];
        }

        if(pos) printf("Possible\n");
        else printf("Not Possible\n");
    }


    return 0;
}


