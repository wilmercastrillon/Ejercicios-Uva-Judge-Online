#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int lli;
typedef tree<int,null_type,less<int>,
    rb_tree_tag,tree_order_statistics_node_update> set_t;

int main(){
    int n,m,l,x;

    while(scanf("%d %d", &n, &m) != EOF){
        set_t se;
        l = n*m;
        lli inv = 0LL, dist = 0LL;

        for(int i = 0; i < l; i++){
            scanf("%d", &x);
            inv += (lli) x - (se.order_of_key(x)+1);
            se.insert(x);

            if(x == n*m)
                dist = abs((i/m) - (n-1)) + abs((i%m) - (m-1));
        }
        //printf("inv = %lld, dist %lld\n", inv, dist);

        if((inv + dist)%2LL == 0LL) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
