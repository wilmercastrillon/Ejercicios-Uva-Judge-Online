#include <bits/stdc++.h>

using namespace std;

int n, m, arr[1000010], k, v;
vector<int> vec[1000010];

int main() {

    while(scanf("%d %d", &n, &m) != EOF){

        for(int i = 0; i < n; i++){
             scanf("%d", &arr[i]);
             vec[i].clear();
        }

        for(int i = n; i < 1000010; i++){
             vec[i].clear();
        }

        for(int i = 0; i < n; i++){
             vec[arr[i]].push_back(i + 1);
        }

        for(int i = 0; i < m; i++){
             scanf("%d %d", &k, &v);
             if(k > vec[v].size())
                printf("0\n");
            else
                printf("%d\n", (vec[v][k - 1]));
        }
    }

    return 0;
}
