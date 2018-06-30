#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, x, aux, a, b;
    vector<int> num;

    while(scanf("%d", &n) == 1){
        num.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            num.push_back(x);
        }
        scanf("%d", &m);

        sort(num.begin(), num.end());
        vector<int>::iterator it = lower_bound(num.begin(), num.end(), m/2);
        bool res = false;

        for( ; it != num.end() && !res; it++){
            aux = m - *it;
            a = *it;
            if(*lower_bound(num.begin(), num.end(), aux) == aux){
                res = true;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", aux, a);
    }

    return 0;
}


