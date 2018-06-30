#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, caso = 1;

    while(scanf("%d %d", &n, &m), n){
        vector<int> v;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back(x);
        }
        for(int j = 0; j < m; j++) scanf("%d", &x);

        if(n > m){
            sort(v.begin(), v.end());
            printf("Case %d: %d %d\n", caso++, n-m, v[0]);
        }else{
            printf("Case %d: 0\n", caso++);
        }
    }

    return 0;
}


