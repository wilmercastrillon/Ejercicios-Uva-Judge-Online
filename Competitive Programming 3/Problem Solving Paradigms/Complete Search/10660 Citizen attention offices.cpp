#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

bool cmp(ii a, ii b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){//NO TERMINADO
    int n, f, c, x, casos, tab[6][6];
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        vector<ii> v;
        vector<int> v2;
        memset(tab, 0, sizeof(tab));

        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &f, &c, &x);
            tab[f][c] = x;
        }
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                v.push_back(ii(tab[i][j], (i*5) + j));


        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < 5; i++) v2.push_back(v[i].second);
        sort(v2.begin(), v2.end());

        for(int i = 0; i < 4; i++)
            printf("%d ", v2[i]);
        printf("%d\n", v2[4]);
    }

    return 0;
}


