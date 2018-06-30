#include <stdio.h>
#include <vector>
#define max(a, b) (a < b)? b: a

using namespace std;
vector<long> alt, ori, anc, anc2;

void solve(int n, int caso){
    long res = 0, res2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(alt[j] < alt[i]) anc[j] = max(anc[j], ori[j] + anc[i]);
            if(alt[j] > alt[i]) anc2[j] = max(anc2[j], ori[j] + anc2[i]);
        }
        res = (res < anc[i])? anc[i]: res;
        res2 = (res2 < anc2[i])? anc2[i]: res2;

        /*for(int j = 0; j < n; j++) printf("%3d ", anc[j]);
        printf("\n");
        for(int j = 0; j < n; j++) printf("%3d ", anc2[j]);
        printf("\n-------------------------------------\n");*/
    }

    if(res2 < res)
        printf("Case %d. Decreasing (%ld). Increasing (%ld).\n", caso, res, res2);
    else
        printf("Case %d. Increasing (%ld). Decreasing (%ld).\n", caso, res2, res);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos, n;
    scanf("%d", &casos);

    for(int i = 1; i <= casos; i++){
        scanf("%d", &n);
        alt.clear();
        anc.clear();
        anc2.clear();
        ori.clear();

        long aux;
        for(int j = 0; j < n; j++){
            scanf("%ld", &aux);
            alt.push_back(aux);
        }
        for(int j = 0; j < n; j++){
            scanf("%ld", &aux);
            anc.push_back(aux);
            anc2.push_back(aux);
            ori.push_back(aux);
        }
        solve(n, i);
    }
    return 0;
}
