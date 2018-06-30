#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int main(){
    int casos, a, x;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &a);
        vector<ii> v;
        for(int i = 0; i < a; i++)
            scanf("%d", &x), v.push_back(ii(x, i));

        sort(v.begin(), v.end());
        int res = 0;
        for(int i = v.size() - 1; i > -1; i--)
            for(int j = 0; j < i; j++)
                if(v[j].second < v[i].second) res++;

        printf("%d\n", res);
    }

    return 0;
}


