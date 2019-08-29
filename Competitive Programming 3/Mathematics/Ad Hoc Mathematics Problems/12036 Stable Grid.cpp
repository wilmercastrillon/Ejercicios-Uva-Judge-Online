#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int tab[110][110];
int con[110];

int main(){
    //freopen("salida.txt","w",stdout);
    int n;
    int t;
    scanf("%d", &t);
    t++;

    forab(i,1,t){
        scanf("%d", &n);
        memset(con,0,sizeof(con));
        bool flag = true;

        forr(i,n) forr(j,n){
            scanf("%d", &tab[i][j]);
            con[tab[i][j]]++;
            if(con[tab[i][j]] > n) flag = false;
        }

        if(flag) printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);
    }

    return 0;
}


