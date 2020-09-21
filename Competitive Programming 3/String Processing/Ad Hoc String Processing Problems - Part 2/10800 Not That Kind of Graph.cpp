#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

char tab[110][110];
int maxcol[110];

void bordes(int ini, int fin){
    forab(i,ini,fin+2)
    forr(j, 110){
        if(i && !j) tab[i][j] = '|';
        if(i>fin && j) tab[i][j] = '-';
        if(i>fin && !j) tab[i][j] = '+';
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t;
    cin >> t;
    string cad;

    forr(i, t){
        cin >> cad;
        memset(tab, ' ', sizeof(tab));
        memset(maxcol, 0, sizeof(maxcol));

        int fil = 50, col = 2, mini = 1000000, maxi = -1000000;
        forr(j, cad.size()){
            if(cad[j] == 'R'){
                if(j && cad[j-1] == 'R') fil--;
                tab[fil][col++] = '/';
                maxcol[fil] = col;
            }else if(cad[j] == 'C'){
                if(j && cad[j-1] == 'R') fil--;
                tab[fil][col++] = '_';
                maxcol[fil] = col;
            }else{
                if(j && cad[j-1] != 'R') fil++;
                tab[fil][col++] = '\\';
                maxcol[fil] = col;
            }
            mini = min(fil, mini);
            maxi = max(fil, maxi);
            //printf("pinta en %d, %d\n", fil, col);
        }

        bordes(mini, maxi);
        maxcol[maxi+1] = col+1;
        cout << "Case #" << (i+1) << ":\n";
        forab(j, mini, maxi+2){
            forr(k, maxcol[j]){
                printf("%c", tab[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}


