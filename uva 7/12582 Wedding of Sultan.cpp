#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

stack<char> pila;
char cad[10000];
int res[27];

void solve(){
    memset(res, 0, sizeof(res));
    while(pila.size()) pila.pop();
    pila.push(cad[0]);
    int l = strlen(cad) - 1;

    for(int i = 1; i < l; i++){
        //printf("%d tam de pila i = %d , l = %d\n", pila.size(), i, l);
        if(pila.top() == cad[i]){
            pila.pop();
            res[pila.top() - 'A']++;
        }else{
            pila.push(cad[i]);
            res[cad[i] - 'A']++;
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, caso = 1;
    scanf("%d", &n);

    while(n--){
        scanf("%s", &cad);
        solve();

        printf("Case %d\n", caso++);
        for(int i = 0; i < 26; i++) if(res[i]) printf("%c = %d\n", i+'A', res[i]);
    }
    return 0;
}
