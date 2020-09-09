#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    //freopen("salida.txt", "w", stdout);
    int a, f, t;
    cin >> t;

    while(t--){
        cin >> a >> f;

        forr(i, f){
            forab(j,1,a+1){
                forr(k, j){
                    printf("%d",j);
                }
                printf("\n");
            }
            for(int j = a-1; j >= 1; j--){
                forr(k, j){
                    printf("%d",j);
                }
                printf("\n");
            }
            if(t || i < f-1)
                printf("\n");
        }
    }

    return 0;
}


