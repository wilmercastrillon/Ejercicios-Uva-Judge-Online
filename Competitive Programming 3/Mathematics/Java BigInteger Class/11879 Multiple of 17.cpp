#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

char cad[110];

bool multiplo17(){
    int l = strlen(cad);
    int mod = 0;

    forr(i,l){
        mod = (mod*10) % 17;
        mod = (mod+(cad[i]-'0')) % 17;
    }

    return (mod==0);
}

int main(){
    //freopen("salida.txt","w",stdout);

    while(scanf("%s",&cad)){
        if(cad[0] == '0' && cad[1] == '\0') break;
        printf("%d\n",(int) multiplo17());
    }

    return 0;
}


