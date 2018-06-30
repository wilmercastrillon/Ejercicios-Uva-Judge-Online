#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x;

    while(scanf("%d %d", &n, &m), n || m){
        map<int, int> cd;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            cd[x] = 1;
        }

        int con = 0;
        for(int i = 0; i < m; i++){
            scanf("%d", &x);
            if(cd.count(x)) con++;
        }

        printf("%d\n", con);
    }

    return 0;
}


