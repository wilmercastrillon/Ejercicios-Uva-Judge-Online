#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;

vector<ii> f;

int mcd(int a, int b){
    return  a? mcd(b %a, a): b;
}

void llenar(int n, int k){
    forab(i,1,n+1){
        for(int j = n; j >= i; --j){
            if(mcd(i,j)==1)
                f.push_back(ii(i,j));
        }
    }
}

bool cmp(ii &a, ii &b){
    return 1.0*a.first/a.second < 1.0*b.first/b.second;
}

int main(){
    int n, k;

    while(scanf("%d %d", &n, &k) != EOF){
        f.clear();
        llenar(n, k);
        sort(f.begin(),f.end(),cmp);
        printf("%d/%d\n", f[k-1].first, f[k-1].second);
    }

    return 0;
}


