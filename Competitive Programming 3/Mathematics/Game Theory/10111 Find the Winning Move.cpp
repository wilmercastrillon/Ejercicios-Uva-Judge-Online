#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int, int> ii;

char c[2], tab[4][4];

bool val(int f, int c){
    return !(f<0 || f>3 || c<0 || c>3 || tab[f][c] != '.');
}

bool win(char p){
    bool wf, wc, wdd = true, wdi = true;
    forr(i,4){
        wf = true;
        wc = true;
        forr(j, 4){
            wf = wf && (tab[i][j] == p);
            wc = wc && (tab[j][i] == p);
        }
        if(wf || wc) return true;
        wdi = wdi && (tab[i][i] == p);
        wdd = wdd && (tab[i][3-i] == p);
    }
    return (wdd || wdi);
}

bool backt(bool x){
    if(win('x')) return true;
    if(win('o')) return false;

    bool res = true, lleno = true;
    forr(i, 4){
        forr(j, 4){
            if(tab[i][j] != '.') continue;
            lleno = false;
            tab[i][j] = (x)? 'x' : 'o';
            res = res && backt(!x);
            tab[i][j] = '.';
        }
    }
    return (res && !lleno);
}

void imp(){
    printf("--------------------\n");
    forr(i, 4){
    forr(j, 4){
        printf("%c", tab[i][j]);
    }
    printf("\n");
    }
}

ii solve(){
    forr(i, 4){
    forr(j, 4){
        if(tab[i][j] != '.') continue;
        //printf("pinta %d %d\n", i, j);
        tab[i][j] = 'x';
        if(win('x')) return ii(i, j);

        int conx = 0, cono = 0;
        forr(k, 4){
        forr(l, 4){
            if(tab[k][l] != '.') continue;
            tab[k][l] = 'x';
            //imp();
            if(win('x')) conx++;

            tab[k][l] = 'o';
            if(win('o')) cono++;

            tab[k][l] = '.';
        } }

        if(conx > 1 && cono == 0) return ii(i, j);
        tab[i][j] = '.';
    } }
    return ii(-1, -1);
}

int main(){//NO TERMINADO
    while(scanf("%s", &c) != EOF && c[0] != '$'){
        forr(i, 4){
            scanf("%s", &tab[i]);
        }

        ii res = solve();
        if(res.first >= 0) printf("(%d,%d)\n", res.first, res.second);
        else printf("#####\n");
    }
    return 0;
}


