#include <bits/stdc++.h>
#define forr(a, b) for(int a = 0; a < b; a++)
#define inf 100000000

using namespace std;
typedef pair<int, int> ii;

bool cam[510][510][4][4];//fila, col, estado, direccion
int tab[510][510][4];//fila, col, estado
int mf[4] = {-1, 0, 1, 0}, mc[4]={0, 1, 0, -1};
int fil, col;
map<char, int> mapa;

bool val(int f, int c){
    return !(f<0 || f>=fil || c<0 || c>=col);
}

int bfs(int f, int c){
    queue<ii> cola;//fila, columna
    queue<ii> cola2;//depth, estado
    cola.push(ii(f, c));
    cola2.push({0,0});
    int auxf, auxc, auxd, depth, est, auxe;
    int lf=fil-1, lc=col-1;
    ii par, par2;

    while(cola.size()){
        par = cola.front();  cola.pop();
        f = par.first;  c = par.second;
        par2 = cola2.front();  cola2.pop();
        depth = par2.first;  est = par2.second;

        if(tab[f][c][est] < depth) continue;
        if(f==lf&&c==lc) break;
        //printf("llega a %d %d | d=%d est=%d\n", f, c, depth, est);

        forr(i, 4){
            if(cam[f][c][est][i]){
                auxf = f+mf[i];  auxc = c+mc[i];
                auxd = depth+1;  auxe = (est+1)%4;
                //printf("puede ir a la direccion %d, %d | con d=%d | est=%d\n", auxf, auxc, auxd, auxe);
                if(!val(auxf, auxc) || tab[auxf][auxc][auxe] <= auxd) continue;

                //printf("inserta\n");
                cola.push(ii(auxf, auxc));
                cola2.push(ii(auxd, auxe));
                tab[auxf][auxc][auxe] = auxd;
            }
        }
        //printf("-----\n");
    }

    int men = inf;
    forr(i, 4) men = min(men, tab[fil-1][col-1][i]);
    return men;
}

void llenar(){
    mapa.clear();
    mapa['N'] = 0;
    mapa['E'] = 1;
    mapa['S'] = 2;
    mapa['W'] = 3;
}

int main(){
    llenar();

    while(scanf("%d %d", &fil, &col) != EOF){
        int l = fil*col-1, len, f = 0, c = 0, q;
        char in[5];
        memset(tab, 5436, sizeof(tab));
        memset(cam, false, sizeof(cam));

        forr(i, l){
            scanf("%s", &in);
            len = strlen(in);
            //printf("para la casilla %d , %d :\n", f, c);
            forr(j, len){
                q = mapa[in[j]];
                cam[f][c][0][q] = true;
                cam[f][c][1][(q+1)%4] = true;
                cam[f][c][2][(q+2)%4] = true;
                cam[f][c][3][(q+3)%4] = true;
                /*printf("activamos %d|%d| est%d |dir=%d\n", f, c, 0, q);
                printf("activamos %d|%d| est%d |dir=%d\n", f, c, 1, (q+1)%4);
                printf("activamos %d|%d| est%d |dir=%d\n", f, c, 2, (q+2)%4);
                printf("activamos %d|%d| est%d |dir=%d\n", f, c, 3, (q+3)%4);*/
            }

            /*forr(k, 4){
                printf("\tEn el estado %d: ", k);
                forr(l, 4){
                    if(cam[f][c][k][l]) printf("%d ", l);
                }
                printf("\n");
            }
            printf("\n");*/

            c++;
            if(c==col) c = 0, f++;
        }

        int res = bfs(0, 0);
        if(res < inf) printf("%d\n", res);
        else printf("no path to exit\n");
    }

    return 0;
}


