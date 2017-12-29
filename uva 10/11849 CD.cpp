#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x;

    while(scanf("%d %d", &n, &m), n || m){
        set<int> cd;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            cd.insert(x);
        }

        int con = 0;
        set<int>::iterator it;
        for(int i = 0; i < m; i++){
            scanf("%d", &x);
            it = cd.find(x);
            if(it != cd.end()) con++;
        }

        printf("%d\n", con);
    }

    return 0;
}


