#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef pair<int, int> ii;

int n, m, f, l;
vector<ii> pares, res;
bool used[15], sol;

void backtraking(int ant, int can){
    if(can == n){
        if(ant == l){
            /*for(int i = 0; i < res.size(); i++){
                printf(" (%d %d) ", res[i].first, res[i].second);
            }
            printf("\n");*/
            sol = true;
        }
        return;
    }

    for(int i = 0; i < m && !sol; i++){
        if(used[i]) continue;

        if(pares[i].first == ant || pares[i].second == ant){
            used[i] = true;
            res.push_back(pares[i]);
            backtraking((pares[i].first == ant)? pares[i].second: pares[i].first
                    , can + 1);
            used[i] = false;
            res.pop_back();
        }
    }
}

int main(){
    int x, y;

    while(scanf("%d", &n), n){
        scanf("%d", &m);
        scanf("%d %d", &x, &y); f = y;
        scanf("%d %d", &x, &y); l = x;

        sol = false;
        pares.clear();
        memset(used, false, sizeof(used));

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            pares.push_back(ii(x, y));
        }
        backtraking(f, 0);

        if(sol) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}


