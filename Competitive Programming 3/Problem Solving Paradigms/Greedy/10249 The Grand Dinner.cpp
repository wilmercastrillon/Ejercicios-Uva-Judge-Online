#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<ii> mesas;
vector<ii> teams;
vector<vi> res;
int con[100];

bool cmp(ii a, ii b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

bool solve(int m, int n){
    int t, c, aux;
    forr(i,m){
        c = teams[i].first;
        t = teams[i].second;
        aux = 0;
        //printf("prueba %d con duracion %d\n",t,c);

        for(int j = 0; aux<c && j<n; j++){
            if(con[mesas[j].second]+1 > mesas[j].first)
                continue;
            con[mesas[j].second]++;
            res[t].push_back(mesas[j].second);
            //printf("\t inserta %d\n",mesas[j].second);
            aux++;
        }
        if(aux < c) return false;
    }
    return true;
}

int main(){
    //freopen("salida.txt","w",stdout);
    int m, n, x;

    while(scanf("%d %d", &m, &n), n){
        mesas.clear();
        teams.clear();
        res.assign(m+1,vi(0));
        memset(con,0,sizeof(con));

        forr(i,m){
            scanf("%d", &x);
            teams.push_back(ii(x,i+1));
        }
        forr(i,n){
            scanf("%d", &x);
            mesas.push_back(ii(x,i+1));
        }

        sort(teams.rbegin(),teams.rend());
        sort(mesas.begin(),mesas.end(),cmp);
        if(solve(m, n)){
            printf("1\n");
            forab(i,1,m+1){
                printf("%d",res[i][0]);
                forab(j,1,res[i].size()){
                    printf(" %d",res[i][j]);
                }
                printf("\n");
            }
        }else{
            printf("0\n");
        }
    }

    return 0;
}


