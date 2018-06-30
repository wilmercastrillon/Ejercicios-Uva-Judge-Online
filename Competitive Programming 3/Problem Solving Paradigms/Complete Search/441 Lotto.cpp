#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

void backtraking(int ant, int &n, vi &ar, vi &v){
    //if((ar.size() - (ant+1)) + v.size() < n) return;

    if(v.size() == n){
        for(int i = 0; i < v.size() - 1; i++) printf("%d ", v[i]);
        printf("%d\n", v[v.size() - 1]);
        return;
    }

    for(int i = ant + 1; i < ar.size(); i++){
        v.push_back(ar[i]);
        backtraking(i, n, ar, v);
        v.pop_back();
    }
}

int main(){
    int k, x, n = 6;
    scanf("%d", &k);

    while(k){
        vi n1, aux;
        for(int i = 0; i < k; i++){
            scanf("%d", &x);
            n1.push_back(x);
        }

        backtraking(-1, n, n1, aux);
        scanf("%d", &k);
        if(k) printf("\n");
    }

    return 0;
}


