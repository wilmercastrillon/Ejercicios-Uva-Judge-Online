#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, d, r, x;

    while(scanf("%d %d %d",&n,&d,&r), n){
        vector<int> morning, tarde;
        for(int i = 0; i < n; i++)
            scanf("%d", &x), morning.push_back(x);
        for(int i = 0; i < n; i++)
            scanf("%d", &x), tarde.push_back(x);

        sort(morning.begin(), morning.end());
        sort(tarde.rbegin(), tarde.rend());

        long acum = 0, aux;
        for(int i = 0; i < n; i++){
            aux = morning[i]+tarde[i]-d;
            if(aux > 0){
                acum += (aux*r);
            }
        }
        printf("%ld\n", acum);
    }

    return 0;
}


