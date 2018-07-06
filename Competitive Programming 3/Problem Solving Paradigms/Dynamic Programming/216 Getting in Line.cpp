#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int n, may;
double men, tab[10][2];
vector<int> aux, mejor;

void backtraking(int pos, double acum, int mask){
    if(mask == may){
        if(acum < men){
            men = acum;
            //printf("encontrado mejor de %.5f\n", acum);
            mejor.clear();
            mejor.assign(aux.begin(), aux.end());
        }
        return;
    }
    if(acum > men) return;

    for(int i = 0; i < n; i++){
        if(i != pos && !(mask&(1<<i)) ){
            aux.push_back(i);
            backtraking(i, acum + hypot(tab[pos][0]-tab[i][0], tab[pos][1]-tab[i][1]), mask|(1<<i));
            aux.pop_back();
        }
    }
}

int main(){
    int casos = 0;

    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++)
            scanf("%lf %lf", &tab[i][0], &tab[i][1]);

        men = 1e9; may = (1<<n)-1;
        aux.clear();
        for(int i = 0; i < n; i++){
            //printf("probamos comenzando desde %.2f, %.2f\n", tab[i][0], tab[i][1]);
            aux.push_back(i);
            backtraking(i, 0, 1<<i);
            aux.pop_back();
        }

        printf("**********************************************************\nNetwork #%d\n", ++casos);
        //double acum = 0;
        for(int i = 1; i < mejor.size(); i++){
            printf("Cable requirement to connect (%.0f,%.0f) to (%.0f,%.0f) is %.2f feet.\n",
                   tab[mejor[i-1]][0], tab[mejor[i-1]][1], tab[mejor[i]][0], tab[mejor[i]][1],
                   hypot(tab[mejor[i-1]][0]-tab[mejor[i]][0], tab[mejor[i-1]][1]-tab[mejor[i]][1]) + 16.0);
            //acum += hipo(tab[i-1][0]-tab[i][0], tab[i-1][1]-tab[i][1]) + 16.0;
        }
        printf("Number of feet of cable required is %.2f.\n", men + 16.0*(mejor.size()-1));
    }

    return 0;
}


