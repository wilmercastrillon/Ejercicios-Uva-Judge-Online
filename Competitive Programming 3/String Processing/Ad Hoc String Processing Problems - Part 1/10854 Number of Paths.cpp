#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define inf 1000000000

using namespace std;
typedef long long int lli;

vector<string> inp;

lli contar(int &pos){
    //printf("inicia en pos %d\n", pos);
    lli con = 0, acum = 1;
    string cad;
    bool open = false, salir = false;

    //printf("hola? %d < %d ? \n", inp.size(), pos);
    while(inp.size() > pos){
        cad = inp[pos];
        if(cad == "IF"){
            //printf("\t encuentra un if, con = %d\n", con);
            pos++;
            con += contar(pos);
            open = true;
        }else if(cad == "ELSE"){
            if(!open) break;
            //printf("\t encuentra un else, con = %d\n", con);
            pos++;
            con += contar(pos);
        }else if(cad == "END_IF"){
            //printf("\t encuentra un end_if, con = %d\n", con);
            if(open == true) open = false;
            else break;
            pos++;
            acum *= con;
            con = 0;
        }else{
            pos++;
        }
    }
    //printf("fin con pos = %d, con = %d, acum = %d\n", pos, con, acum);
    return acum;
}

int main(){
    cin.tie(NULL);
    string cad;
    int n;  cin >> n;

    while(n--){
        inp.clear();
        while(cin >> cad){
            if(cad == "ENDPROGRAM") break;
            inp.push_back(cad);
        }
        int pos = 0;
        lli res = contar(pos);
        printf("%lld\n", res);
    }

    return 0;
}


