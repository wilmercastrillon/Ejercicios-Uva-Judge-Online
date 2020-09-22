#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int, int> ii;

char tab[90][90];
string cad, ent[10];
int m, pow2[10];

void prepow2(){
    pow2[0] = 1;
    forab(i,1,10)
        pow2[i] = pow2[i-1]<<1;
}

char b(int i, char c){
    if((c/pow2[i]) % 2 == 0) return '/';
    return '\\';
}

char h(int i, int j){
    if(i == 0 && j >= 0 && j <= m+1) return '/';
    if(i == 9 && j >= 0 && j <= m+1) return '/';
    if(j == 0 && i >= 0 && i <= 9) return '/';
    if(j == m+1 && i >= 0 && i <= 9) return '/';
    return b(i-1, cad[j-1]);
}

void imp(){
    prepow2();
    m = cad.size();
    forr(i, 10){
        forr(j, m+2){
            tab[i][j] = h(i, j);
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        forr(i, 10){
            cin >> ent[i];
        }
        m = ent[0].size()-2;

        forab(j,1,m+1){
            char ascii = 0;
            forab(i,1,9){
                if(ent[i][j] == '\\')
                    ascii |= (1<<(i-1));
            }
            printf("%c", ascii);
        }
        printf("\n");
    }
    return 0;
}


