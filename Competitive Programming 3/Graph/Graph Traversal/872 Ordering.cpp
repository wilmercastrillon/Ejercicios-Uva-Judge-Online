#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string.h>

using namespace std;
typedef vector<int> vi;

vector<vi> lista(27);
vector<int> letras, sol;
bool used[27], vacio;

void backtraking(int can){
    //printf("can %d\n", can);
    if(can == letras.size()){
        //printf("solucion: tam: %d, tam sol=%d\n", can, sol.size());
        printf("%c", sol[0]);
        for(int i = 1; i < sol.size(); i++) printf(" %c", sol[i]);
        printf("\n");
        vacio = false;
        return;
    }

    bool sig;
    for(int i = 0; i < letras.size(); i++){
        //printf("----%c\n", letras[i]+'A');
        if(!used[letras[i]]){
            sig = true;
            for(int j = 0; j < lista[letras[i]].size() && sig; j++){
                //printf("conexion con pos %d\n", lista[letras[i]][j]);
                sig = sig && used[lista[letras[i]][j]];
            }

            if(sig){
                sol.push_back(letras[i] + 'A'); used[letras[i]] = true;
                backtraking(can+1);
                sol.pop_back(); used[letras[i]] = false;
            }
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int t, tam;
    char cad[500], res[500];
    scanf("%d", &t);
    getchar();

    while(t--){
        string x; tam = 0;
        letras.clear();

        getchar();
        gets(cad);
        stringstream ss(cad);
        while(ss >> x){
            lista[x[0]-'A'].clear();
            letras.push_back(x[0]-'A');
        }

        gets(res);
        stringstream ss2(res);
        while(ss2 >> x){
            lista[x[2]-'A'].push_back(x[0]-'A');
        }

        vacio = true;
        sort(letras.begin(), letras.end());
        memset(used, false, sizeof(used));
        backtraking(0);
        if(vacio) printf("NO\n");
        if(t)printf("\n");
    }

    return 0;
}


