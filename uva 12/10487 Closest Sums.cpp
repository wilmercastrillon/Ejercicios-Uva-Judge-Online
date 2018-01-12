#include <stdio.h>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n, m, q, x, con = 0;

    while(scanf("%d", &n), n){
        vector<int> v;
        set<int> sum;
        sum.insert(-1000000);
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back(x);

            for(int j = i - 1; j >= 0; j--)
                sum.insert(v[i] + v[j]);
        }

        scanf("%d", &m);
        int a, b, c;
        printf("Case %d:\n", ++con);
        set<int>::iterator it;
        for(int i = 0; i < m; i++){
            scanf("%d", &q);
            it = sum.lower_bound(q);
            a = *it--;
            b = *it;
            if(abs(a - q) > abs(b - q)) c = b;
            else c = a;
            printf("Closest sum to %d is %d.\n", q, c);
        }
    }

    return 0;
}


