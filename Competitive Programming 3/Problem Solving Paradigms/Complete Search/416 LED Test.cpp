#include <bits/stdc++.h>

using namespace std;
int n;
string num[10], input[15];

void numeros(){
    num[0] = "YYYYYYN"; num[1] = "NYYNNNN";
    num[2] = "YYNYYNY"; num[3] = "YYYYNNY";
    num[4] = "NYYNNYY"; num[5] = "YNYYNYY";
    num[6] = "YNYYYYY"; num[7] = "YYYNNNN";
    num[8] = "YYYYYYY"; num[9] = "YYYYNYY";
}

bool val(int posnum, string &b, string &quemado){
    //cout << "probamos numero " << posnum << " con cad " << b << " quemados " << quemado << endl;
    for(int i = 0; i < 7; i++){
        if(b[i] == 'Y'){
            if(quemado[i] == 's' || num[posnum][i] == 'N')
                return false;
        }else{
            if(num[posnum][i] == 'Y')
                quemado[i] = 's';
        }
    }
    //cout << "si!!!\n";
    return true;
}

bool solve(int pos, int next, string q){
    //cout << "llamado pos " << pos << " numero a probar " << next << " quemados " << q << endl;
    if(pos == n) return true;
    if(next == -1) return false;

    string aux = q;
    if(val(next, input[pos], aux)){
        return solve(pos + 1, next - 1, aux);
    }else{
        //cout << "no es valido\n";
        return false;
    }
}

int main(){
    cin.tie(NULL);
    //ios_base::sync
    numeros();

    while(cin >> n, n){
        for(int i = 0; i < n; i++){
            cin >> input[i];
        }

        bool res = false;
        for(int j = 9; j >= 0; j--){
            string qw = "nnnnnnn";
            //cout << "j = " << j << endl << endl;
            if(solve(0, j, qw)){
                res = true;
                break;
            }
        }

        if(res) cout << "MATCH\n";
        else cout << "MISMATCH\n";
    }

    return 0;
}


