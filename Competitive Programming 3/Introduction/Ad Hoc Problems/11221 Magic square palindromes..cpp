#include <bits/stdc++.h>

using namespace std;
string cad, cad2, rev;
int n;

bool valido(char c){
    return (c >= 'a' && c <= 'z');
}

bool solve(){
    cad2 = "";
    rev = "";
    for(int i = 0; i < cad.length(); i++){
        if(valido(cad[i])){
			 cad2.push_back(cad[i]);
			 rev.push_back(cad[i]);
		 }
    }

    n = sqrt(cad2.length());
    if((n*n) != cad2.length()) return false;
    reverse(rev.begin(), rev.end());
    
    return rev == cad2;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos;
    scanf("%d", &casos);
    getchar();
    char cadena[15000];

    for(int i = 1; i <= casos; i++){
        gets(cadena);
        //printf("se lee %d\n", strlen(cadena));
        cad = (string) cadena;

        printf("Case #%d:\n", i);
        if(solve())
            printf("%d\n", n);
        else
            printf("No magic :(\n");
    }

    return 0;
}
