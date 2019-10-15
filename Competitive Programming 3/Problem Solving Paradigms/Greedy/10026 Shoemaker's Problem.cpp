#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<double,int> di;

int n, t[1010],s[1010];
vector<di> sol;

bool cmp(di &a, di &b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    //freopen("salida.txt","w",stdout);
    int casos, a, b;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        sol.clear();

        forr(i,n){
            scanf("%d %d", &t[i], &s[i]);
            sol.push_back(di(1.0*s[i]/t[i],i+1));
            //printf("inserto %.5f %d\n",1.0*s[i]/t[1],i+1);
        }

        sort(sol.begin(),sol.end(),cmp);
        printf("%d",sol[0].second);
        forab(i,1,n){
            printf(" %d",sol[i].second);
        }
        printf("\n");

        if(casos) printf("\n");
    }


    return 0;
}


