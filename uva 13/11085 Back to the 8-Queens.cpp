#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<int> reinas(8);
vector<vi> sol(92, vi(8));
int con = 0;

bool val(int f, int can){
    for(int i = 0; i < can; i++)
        if(reinas[i] == f || (abs(reinas[i] - f) == abs(i - can)))
            return false;

    return true;
}

void backTraking(int can){
    if(can == 8){
        //printf("solucion # %d:\n", ++con);
        for(int i = 0; i < 8; i++){
            //printf("%d ", reinas[i]);
            sol[con][i] = reinas[i];
            //sol[con][reinas[i]] = i;
        }
        con++;
        //printf("\n");
    }

    for(int i = 0; i < 8; i++){
        if(val(i, can)){
            reinas[can] = i;
            backTraking(can + 1);
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    backTraking(0);
    char cad[25];
    int ar[8];
    int l, con, qwe = 0;

    while(gets(cad)){
        l = strlen(cad);
        con = 0;
        for(int i = 0; i < l; i+=2) ar[con++] = cad[i] - '0';

        int cambiar, men = 1000000;
        for(int i = 0; i < sol.size(); i++){
            cambiar = 0;
            for(int j = 0; j < 8; j++){
                if(sol[i][j] + 1 != ar[j]) cambiar++;
            }
            men = min(men, cambiar);
        }

        cout << "Case " << ++qwe << ": " << men << "\n";
    }

    return 0;
}


