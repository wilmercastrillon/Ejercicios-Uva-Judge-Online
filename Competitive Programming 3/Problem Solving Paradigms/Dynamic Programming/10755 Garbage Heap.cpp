#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long ll;

ll ini[22][22][22];
ll tab[22][22][22];
int a, b, c;

void build(){
    for(int pi = 1; pi <= c; pi++)
        for(int fi = 1; fi <= a; fi++)
        for(int co = 1; co <= b; co++){
            tab[fi][co][pi] = ini[fi][co][pi] + tab[fi][co][pi-1];
            tab[fi][co][pi] += (tab[fi-1][co][pi] - tab[fi-1][co][pi-1]);
            tab[fi][co][pi] += (tab[fi][co-1][pi] - tab[fi][co-1][pi-1]);
            tab[fi][co][pi] -= (tab[fi-1][co-1][pi] - tab[fi-1][co-1][pi-1]);
        }
}

ll solve(){
    ll may = -4000000000, aux;
    //printf("may %lld\n", may);
    for(int p1 = 1; p1 <= c; p1++)
    for(int f1 = 1; f1 <= a; f1++)
    for(int c1 = 1; c1 <= b; c1++)
        for(int p2 = p1; p2 <= c; p2++)
        for(int f2 = f1; f2 <= a; f2++)
        for(int c2 = c1; c2 <= b; c2++){
            //printf("f1 %d c1 %d p1 %d ||| f2 %d c2 %d p2 %d", f1, c1, p1, f2, c2, p2);
            aux = tab[f2][c2][p2] - tab[f2][c2][p1-1];//inicial
            aux -= (tab[f1-1][c2][p2] - tab[f1-1][c2][p1-1]);//corte de filas
            aux -= (tab[f2][c1-1][p2] - tab[f2][c1-1][p1-1]);//corte de columnas
            aux += (tab[f1-1][c1-1][p2] - tab[f1-1][c1-1][p1-1]);//recuperar diagonal
            if(aux > may){
                may = aux;
            }
        }

    return may;
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &a, &b, &c);
        memset(tab, 0, sizeof(tab));

        for(int fi = 0; fi < a; fi++)
            for(int co = 0; co < b; co++)
                for(int pi = 0; pi < c; pi++)
                    scanf("%lld", &ini[fi+1][co+1][pi+1]);

        build();
        /*for(int pi = 0; pi <= c; pi++){
            for(int fi = 0; fi <= a; fi++){
                for(int co = 0; co <= b; co++){
                    printf("%3lld", tab[fi][co][pi]);
                }
                printf("\n");
            }
            printf("piso----------------------\n");
        }*/

        printf("%lld\n", solve());
        if(i+1 != t) printf("\n");
    }

    return 0;
}


