#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#define forr(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;

char cad[100010];
vector<vi> idx;
int lon;

int solve(){
    int pos1, pos2, pos3, res = 0;

    for(char c1 = 'A'; c1 <= 'Z'; c1++){
        if(!idx[c1].size()) continue;
        pos1 = idx[c1][0];
        //printf("1|esta la %c\n",c1);

        for(char c2 = 'A'; c2 <= 'Z'; c2++){
            if(!idx[c2].size()) continue;
            pos2 = lower_bound(idx[c2].begin(),idx[c2].end(),pos1+1) - idx[c2].begin();
            if(pos2<0 || pos2>=idx[c2].size()) continue;
            pos2 = idx[c2][pos2];
            //printf("2## |esta la %c\n",c2);

            for(char c3 = 'A'; c3 <= 'Z'; c3++){
                if(!idx[c3].size()) continue;
                pos3 = lower_bound(idx[c3].begin(),idx[c3].end(),pos2+1) - idx[c3].begin();
                if(pos3<0 || pos3>=idx[c3].size()) continue;
                pos3 = idx[c3][pos3];
                //printf("3 ############## |esta la %c\n",c3);
                //printf("encontramos: (%d,%c), (%d,%c), (%d,%c)\n", pos1,c1,pos2,c2,pos3,c3);

                res++;
            }
        }
    }
    return res;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%s", &cad);

        idx.assign('Z'+1,vi(0));
        lon = strlen(cad);
        forr(i, lon)
            idx[cad[i]].push_back(i);

        //printf("tam %d\n", idx[]);

        printf("%d\n", solve());
    }
    return 0;
}


