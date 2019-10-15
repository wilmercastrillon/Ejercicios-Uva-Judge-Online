#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;

vector<int> num;
vector<ii> res;

bool cmp(int a, int b, int c, int d){//mejor la 1
    return a+d+2*b < 2*a+c+d;
}

int solve(){
    int tiempo = 0, a = num[0], b = num[1], c, d;
    vector<int> v(num.begin()+2,num.end());
    res.push_back(ii(a, b));
    tiempo += b;
    //printf("1|suma %d\n",b);

    while(v.size()>1){
        c = v[v.size()-2];
        d = v.back();
        if(cmp(a, b, c, d)){
            res.push_back(ii(a, -1));
            res.push_back(ii(c, d));
            res.push_back(ii(b, -1));
            res.push_back(ii(a, b));
            tiempo += (a+d+2*b);
            //printf("2|suma %d\n",(a+d+2*b));
        }else{
            res.push_back(ii(a, -1));
            res.push_back(ii(a, c));
            res.push_back(ii(a, -1));
            res.push_back(ii(a, d));
            tiempo += (2*a+c+d);
            //printf("3|suma %d\n",(2*a+c+d));
        }
        v.pop_back();
        v.pop_back();
    }

    if(v.size()){
        res.push_back(ii(a, -1));
        res.push_back(ii(a,v[0]));
        tiempo += (a+v[0]);
        //printf("4|suma %d\n",v[0]);
    }

    return tiempo;
}

int main(){
    //freopen("salida.txt","w",stdout);
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        res.clear();
        num.clear();

        scanf("%d", &n);
        forr(i,n){
            scanf("%d", &x);
            num.push_back(x);
        }
        if(n==1){
            printf("%d\n%d\n",x,x);
            if(t) printf("\n");
            continue;
        }

        sort(num.begin(),num.end());
        int r = solve();
        printf("%d\n", r);
        forr(i,res.size()){
            if(res[i].second>0)
                printf("%d %d\n",res[i].first,res[i].second);
            else printf("%d\n",res[i].first);
        }

        if(t) printf("\n");
    }

    return 0;
}


