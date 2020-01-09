#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    //freopen("salida.txt","w",stdout);
    int n, c, s, out = 1;
    vector<int> v, res[6];

    while(scanf("%d %d", &c, &s) != EOF){
        forr(i,c) res[i].clear();
        v.clear();
        double aux = 0.0, pro = 0.0;

        forr(i,s){
            scanf("%d", &n);
            v.push_back(n);
            pro += n*1.0;
        }
        forr(i,2*c-s) v.push_back(0);
        sort(v.begin(),v.end());

        pro = pro/c;
        int b = 2*c-1;
        forr(i,c){
            //printf("i %d -> %d %d\n", i,v[i],v[b]);
            res[i].push_back(v[b]);
            res[i].push_back(v[i]);
            aux += fabs(pro-1.0*(res[i][0]+res[i][1]));
            b--;
        }

        printf("Set #%d\n",out++);
        forr(i,c){
            if(res[i][1] != 0) printf(" %d: %d %d\n",i,res[i][0],res[i][1]);
            else if(res[i][0] == 0) printf(" %d:\n", i);
            else printf(" %d: %d\n",i,res[i][0]);
        }
        printf("IMBALANCE = %.5f\n\n", aux);
    }

    return 0;
}


