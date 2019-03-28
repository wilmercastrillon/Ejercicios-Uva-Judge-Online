#include <bits/stdc++.h>
#define mod 20437

using namespace std;
typedef pair<int, int> ii;

int dis[12][12][100], n, lim, ult;
int memo[11][11][28][2610];
char tab[12][12];
int mf[] = {0, 1, 0, -1}, mc[] = {1, 0, -1, 0};

bool val(int f, int c){
    return !(f<0 || f>=n || c<0 || c>=n || tab[f][c]=='#');
}

bool upper(char c){
    return (c >= 'A' && c <= 'Z');
}

int dp(int fil, int col, int c, int len){
    if(len > lim || tab[fil][col] > c+'A'){
        return 0;
    }
    if(c == ult){
        return 1;
    }
    if(memo[fil][col][c][len] != -1){
        return memo[fil][col][c][len];
    }

    int auxf, auxc, ans = 0;
    for(int i = 0; i < 4; i++){
        auxf = fil+mf[i];
        auxc = col+mc[i];
        if(!val(auxf, auxc))continue;
        if(tab[auxf][auxc] == (c+1)+'A'){
            ans = (ans + dp(auxf, auxc, c+1, len+1)) % mod;
        }else{
            ans = (ans + dp(auxf, auxc, c, len+1)) % mod;
        }
    }
    return memo[fil][col][c][len] = ans;
}

int bfs(int inif, int inic){
    queue<ii> cola1;
    queue<char> cola2;
    cola1.push(ii(inif, inic));
    cola2.push('A');
    dis[inif][inic]['A'] = 0;
    ii par1, par2;
    int fil, col;
    char c;

    while(cola1.size()){
        par1 = cola1.front();  cola1.pop();
        c = cola2.front();  cola2.pop();
        fil = par1.first;  col = par1.second;

        if(c == ult+'A'){
            return dis[fil][col][c];
        }

        int auxf, auxc, aux;
        for(int i = 0; i < 4; i++){
            auxf = fil+mf[i];
            auxc = col+mc[i];
            aux = dis[fil][col][c] + 1;
            if(!val(auxf, auxc))continue;
            if(upper(tab[auxf][auxc])){
                if(tab[auxf][auxc] > c+1) continue;
                if(tab[auxf][auxc] == c+1 && dis[auxf][auxc][c+1] > aux){
                    dis[auxf][auxc][c+1] = aux;
                    cola1.push(ii(auxf, auxc));
                    cola2.push(c+1);
                }else if(dis[auxf][auxc][c] > aux){
                    dis[auxf][auxc][c] = aux;
                    cola1.push(ii(auxf, auxc));
                    cola2.push(c);
                }
            }else{
                if(dis[auxf][auxc][c] <= aux) continue;
                dis[auxf][auxc][c] = aux;
                cola1.push(ii(auxf, auxc));
                cola2.push(c);
            }
        }
    }
    return -1;
}

int main(){//No enviado a uva, pero funciona perfectamente en uDebug
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int caso = 1, inif, inic;
    while(scanf("%d", &n), n){
        ult = -1;

        for(int i = 0; i < n; i++){
            scanf("%s", &tab[i]);
            for(int j = 0; j < n; j++){
                ult = max(ult, tab[i][j]-'A');
                if(tab[i][j] == 'A'){
                    inif = i;
                    inic = j;
                }
            }
        }

        memset(dis, 5436, sizeof(dis));
        memset(memo, -1, sizeof(memo));

        int q = bfs(inif, inic);
        if(q == -1){
            printf("Case %d: Impossible\n", caso++);
            continue;
        }
        lim = q;//n*n + 1;
        int w = dp(inif, inic, 0, 0);
        printf("Case %d: %d %d\n", caso++, q, w);
    }

    return 0;
}


