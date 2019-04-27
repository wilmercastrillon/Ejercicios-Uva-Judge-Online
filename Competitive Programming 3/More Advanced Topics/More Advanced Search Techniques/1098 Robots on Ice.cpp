#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int fil, col, p1, p2, p3, con, target;
int f1,f2,f3,c1,c2,c3;
int mf[4]={-1, 1, 0, 0}, mc[4]={0, 0, -1, 1};
int vis[10], reached[10];

int dfs(int f, int c){
    reached[f] |= 1<<c;

    int auxf, auxc, ans = 1;
    for(int i = 0; i < 4; ++i){
        auxf = f+mf[i];
        auxc = c+mc[i];
        if(auxf<0||auxf==fil||auxc<0||auxc==col||(reached[auxf]&(1<<auxc))) continue;
        ans += dfs(auxf, auxc);
    }
    return ans;
}

void backtraking(int f, int c, int paso){
    //printf("llega a %d %d con paso %d\n", f, c, paso);
    if(f==0&&c==1){
        if(paso==target) ++con;
        return;
    }

    if(paso==p1 && (f!=f1||c!=c1)) return;
    if(paso==p2 && (f!=f2||c!=c2)) return;
    if(paso==p3 && (f!=f3||c!=c3)) return;

    if(f==f1 && c==c1 && p1!=paso) return;
    if(f==f2 && c==c2 && p2!=paso) return;
    if(f==f3 && c==c3 && p3!=paso) return;

    if(paso < p1 && (paso+abs(f-f1)+abs(c-c1)>p1)) return;
    if(paso < p2 && (paso+abs(f-f2)+abs(c-c2)>p2)) return;
    if(paso < p1 && (paso+abs(f-f3)+abs(c-c3)>p3)) return;

    for(int i = 0; i < fil; ++i)
        reached[i] = vis[i];
    if(dfs(f,c)+paso <= target) return;

    int auxf, auxc;
    for(int i = 0; i < 4; ++i){
        auxf = f+mf[i];
        auxc = c+mc[i];
        if(auxf<0||auxf==fil||auxc<0||auxc==col||(vis[auxf]&(1<<auxc))) continue;
        vis[auxf] |= 1<<auxc;
        backtraking(auxf,auxc,paso+1);
        vis[auxf] ^= 1<<auxc;
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int caso = 0;

    while(scanf("%d %d", &fil, &col), fil){
        scanf("%d %d %d %d %d %d", &f1,&c1,&f2,&c2,&f3,&c3);
        memset(vis, 0, sizeof(vis));
        con=0;
        target = fil*col;
        p1 = target>>2;
        p2 = target>>1;
        p3 = (3*target)>>2;

        vis[0] = 1;
        backtraking(0,0,1);
        printf("Case %d: %d\n", ++caso, con);
    }

    return 0;
}


