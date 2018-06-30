#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("salida.txt", "w", stdout);
    char cad[100];

    while(scanf("%s", &cad) && cad[0] != '#'){
        int l = strlen(cad);
        if(next_permutation(cad, cad + l))printf("%s\n", cad);
        else printf("No Successor\n");
    }

    return 0;
}
