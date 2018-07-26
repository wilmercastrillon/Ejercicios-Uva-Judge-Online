#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long int lli;

lli memo[51][51];

lli dp(int n, int k){
    if(k == 0 || n == k) return 1;
    if(memo[n][k] != -1) return memo[n][k];
    return memo[n][k] = dp(n-1,k-1)+dp(n-1,k);
}

int main(){
    char cad[110], cad1[100], cad2[100];
    int t, k, l, j, pos;
    bool found;
    memset(memo, -1, sizeof(memo));
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%s", &cad);
        l = strlen(cad);
        found = false;
        pos = 0;
        for(j = 1; j < l && cad[j] != ')'; j++){
            if(cad[j] == '+'){
                found = true;
                cad1[pos] = '\0';
                pos = 0;
                continue;
            }
            if(found) cad2[pos++] = cad[j];
            else cad1[pos++] = cad[j];
        }
        cad2[pos++] = '\0';
        k = 0;
        j+=2;
        for(; j < l; j++){
            k *= 10;
            k += cad[j] - '0';
        }

        if(k == 1){
            printf("Case %d: %s+%s\n", i, cad1, cad2);
            continue;
        }else if(k == 2){
            printf("Case %d: %s^2+2*%s*%s+%s^2\n", i, cad1, cad1, cad2, cad2);
            continue;
        }

        printf("Case %d: %s^%d", i, cad1, k);
        int exp1 = k-1, exp2 = 1;
        for(int l = k-1; l > 0; l--){
            printf("+%lld*%s", dp(k, l), cad1);
            if(exp1 > 1) printf("^%d", exp1--);
            printf("*%s", cad2);
            if(exp2 > 1) printf("^%d", exp2);
            exp2++;
        }
        printf("+%s^%d\n", cad2, k);

        //printf("le lee %s %s %d\n", cad1, cad2, k);
    }

    return 0;
}


