#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;

bool cmp(ii &a, ii &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    //freopen("salida.txt","w",stdout);
    int n, t, l, r;
    vector<ii> v;
    scanf("%d", &t);

    while(t--){
        v.clear();
        scanf("%d", &n);
        while(scanf("%d %d", &l, &r), l||r){
            v.push_back(ii(l,r));
        }
        sort(v.begin(),v.end(),cmp);

        //forr(i,v.size()) printf(" (%d , %d),", v[i].first, v[i].second);
        //printf("\n");

        vector<ii> sol, imp;
        int res, mejor = 1000000;
        ii ant = ii(-1,-1);

        forr(j,v.size()){
            if(v[j].second < 0) continue;
            if(v[j].first > 0) break;

            if(v[j].second > 0 && v[j].first <= 0){
                ant = v[j];
                sol.clear();
                sol.push_back(ant);
                res = 1;
                //printf("sirve (%d %d)\n",ant.first,ant.second);

                forab(i,j+1,v.size()){
                    if(ant.second >= n){
                        //printf("termino!!!\n");
                        break;
                    }
                    //printf("\t (%d %d) ",v[i].first,v[i].second);

                    if(v[i].first > ant.second){
                        //printf("por fuera, NO SIRVIO\n");
                        res = -1;
                        break;
                    }
                    if(v[i].second <= ant.second){
                        //printf("dentro del anterior (l,%d) <= (l,%d)\n",v[i].second,ant.second);
                        continue;
                    }
                    if(res > 2 && v[i].first <= sol[res-2].second && v[i].second >= ant.second){
                        //printf(" |quitar anterior, no sirve de intermedio| ");
                        sol.pop_back();
                    }//else printf(" | comparo con (%d,%d) (%d,%d) | ",v[res-2].first,v[res-2].second,ant.first,ant.second);
                    ant = v[i];
                    sol.push_back(ant);
                    res = sol.size();
                    //printf("### si sirve\n",v[i].first,v[i].second);
                }

                if(ant.second < n) res = -1;
                //printf("\t res final %d\n", res);
                if(res > 0 && res < mejor){
                    mejor = res;
                    imp = sol;
                }
            }
        }

        if(mejor < 5001){
            printf("%d\n",mejor);
            forr(i,imp.size()) printf("%d %d\n",imp[i].first,imp[i].second);
        }else printf("0\n");


        if(t) printf("\n");
    }

    return 0;
}


