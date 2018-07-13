#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

char tab[210][210];
int fil, col;
int mf[] = {-1, 0, 1, 0};
int mc[] = {0,  1, 0, -1};
map<char, int> hex;
map<int, char> res;

void llenar(){
    hex.clear(); res.clear();
    for(int i = 0; i < 10; i++) hex['0'+i] = i;
    for(int i = 0; i < 6; i++) hex['a'+i] = i+10;

    res[0]='W'; res[1]='A'; res[2]='K';
    res[3]='J'; res[4]='S'; res[5]='D';
}

bool val(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col || tab[f][c]!='0');
}

void dfs0(int f, int c){
    tab[f][c] = '.';
    int auxf, auxc;
    for(int i = 0; i < 4; i++){
        auxf = f+mf[i]; auxc = c+mc[i];
        if(val(auxf, auxc)) dfs0(auxf, auxc);
    }
}

bool val2(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col || tab[f][c]=='.' || tab[f][c]=='n');
}
int componentes;
void dfs1(int f, int c){
    tab[f][c] = 'n';
    int auxf, auxc;
    for(int i = 0; i < 4; i++){
        auxf = f+mf[i]; auxc = c+mc[i];
        if(val2(auxf, auxc)){
            if(tab[auxf][auxc] == '0'){
                dfs0(auxf, auxc), componentes++;
            }else dfs1(auxf, auxc);
        }
    }
}

void imp(){
    for(int i = 0; i < fil; i++){
        for(int j = 0; j < col; j++){
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n\n");
}

int main(){//no esta terminado
    char cad[210];
    llenar();
    int caso = 1;

    while(scanf("%d %d", &fil, &col), fil, col){
        int pos;
        for(int i = 0; i < fil; i++){
            pos = 0;
            scanf("%s", &cad);
            for(int j = 0; j < col; j++){
                for(int k = 0; k < 4; k++){
                    tab[i][pos++] = '0'+ ((bool)(hex[cad[j]]&(1<<k)));
                    //printf("se leyo %d en pos %d\n", hex[cad[j]]&(1<<k), pos-1);
                }

            }
        }
        col *= 4;
        for(int i = 0; i < fil; i++){
            if(tab[i][0] == '0') dfs0(i, 0);
            if(tab[i][col-1]=='0') dfs0(i, col-1);
        }
        for(int j = 0; j < col; j++){
            if(tab[0][j] == '0') dfs0(0, j);
            if(tab[fil-1][j]=='0') dfs0(fil-1, j);
        }

        imp();

        vector<int> v;
        for(int i = 0; i < fil; i++)
            for(int j = 0; j < col; j++)
                if(tab[i][j] == '1'){
                    componentes = 0;
                    dfs1(i, j);
                    v.push_back(componentes);
                    //printf("tenia %d comp corresponde: %c\n", componentes, res[componentes]);
                    //imp();
                }

        printf("Case %d: %c", caso++, res[v[0]]);
        for(int i = 1; i < v.size(); i++) printf("%c", res[v[i]]);
        printf("\n");
    }

    return 0;
}


