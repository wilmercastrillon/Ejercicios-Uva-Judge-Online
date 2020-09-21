#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

string cad;

void getnum(int &n, int &pos){
    n = 0;
    while(pos < cad.size() && isdigit(cad[pos])){
        n *= 10;
        n += (cad[pos++]-'0');
    }
}

int main(){
    cin.tie(NULL);
    int res = 0, a, b, c, pos;
    bool negativo;

    while(cin >> cad){
        pos = 0;
        getnum(a, pos);
        negativo = (cad[pos++] == '-');
        getnum(b, pos);
        if(negativo) b *= -1;
        if(cad[pos+1] != '?'){
            //printf("calcula c| pos %d = %c\n", pos+1, cad[pos+1]);
            pos++;
            getnum(c, pos);
        }else c = 1000000000;
        //printf("%d %d = %d\n", a, b, c);

        if(a + b == c) res++;
    }
    cout << res << '\n';
    return 0;
}


