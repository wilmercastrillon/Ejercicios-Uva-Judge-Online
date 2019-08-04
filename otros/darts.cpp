#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int m = 2500, primo[2510];
vector<int> ppp;
int lim = sqrt(m)+1;

void criba(){
    ppp.push_back(1);
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        ppp.push_back(i);
        primo[i] = i;

        for(int j = i*i; j < m; j += i)
            primo[j] = i;
    }
}

int n, p;
int memo[110][5010];

void dp(){
    memset(memo, 0, sizeof(memo));
     for(int j = 1; j < 5005; j++)
        memo[0][j] = j;

    for(int i = 1; i < 105; i++){
        for(int j = 0; j < ppp[i]; j++)
            memo[i][j] = memo[i-1][j];

        for(int j = ppp[i]; j < 5005; j++){
            memo[i][j] = min(memo[i-1][j], memo[i][j-ppp[i]] + 1);
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    criba();
    dp();

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &p);
        printf("%d\n", memo[n-1][p]);
    }

    return 0;
}


