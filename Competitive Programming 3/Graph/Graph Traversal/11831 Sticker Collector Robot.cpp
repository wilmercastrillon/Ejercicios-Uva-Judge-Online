#include <stdio.h>

using namespace std;

char tab[110][110], cad[100000];
int n, m, s, fila, col, dir;
int mf[] = {-1, 0, 1, 0};
int mc[] = {0,  1, 0, -1};

bool val(int f, int c){
    return !(f<0 || c<0 || f>=n || c>=m || tab[f][c] == '#');
}

int solve(){
    int con = 0;
    for(int i = 0; i < s; i++){
        if(cad[i] == 'D'){
            dir = (dir + 1) % 4;
        }else if(cad[i] == 'E'){
            dir--;
            if(dir == -1) dir = 3;
        }else{
            if(val(fila+mf[dir], col+mc[dir])){
                fila += mf[dir];
                col += mc[dir];
                if(tab[fila][col] == '*'){
                    con++;
                    tab[fila][col] = '.';
                }
            }
        }
    }
    return con;
}

int main(){

    while(scanf("%d %d %d", &n, &m, &s), n, s){
        for(int i = 0; i < n; i++){
            scanf("%s", &tab[i]);
            for(int j = 0; j < m; j++){
                if(tab[i][j] == 'N'){
                    fila = i; col = j; dir = 0;
                }else if(tab[i][j] == 'S'){
                    fila = i; col = j; dir = 2;
                }else if(tab[i][j] == 'L'){
                    fila = i; col = j; dir = 1;
                }else if(tab[i][j] == 'O'){
                    fila = i; col = j; dir = 3;
                }
            }
        }
        scanf("%s", &cad);

        printf("%d\n", solve());
    }

    return 0;
}


