#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;

int main(){
    int n;
    int side[4];
    cin >> n;

    forr(i, n){
        forr(j, 4)
            cin >> side[j];
        sort(side, side+4);

        if(side[0]==side[3]){
            printf("square\n");
        }else if(side[0]==side[1] && side[2]==side[3]){
            printf("rectangle\n");
        }else if(side[3] < (side[0]+side[1]+side[2])){
            printf("quadrangle\n");
        }else{
            printf("banana\n");
        }
    }

    return 0;
}


