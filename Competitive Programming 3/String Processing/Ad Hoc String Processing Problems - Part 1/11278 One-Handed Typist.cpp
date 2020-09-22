#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

map<char, char> mapa;

void pre(){
    mapa['4'] = 'q'; mapa['5'] = 'j'; mapa['6'] = 'l'; mapa['7'] = 'm'; mapa['8'] = 'f';
    mapa['9'] = 'p'; mapa['0'] = '/'; mapa['-'] = '['; mapa['='] = ']'; mapa['q'] = '4';
    mapa['w'] = '5'; mapa['e'] = '6'; mapa['r'] = '.'; mapa['t'] = 'o'; mapa['y'] = 'r';
    mapa['u'] = 's'; mapa['i'] = 'u'; mapa['o'] = 'y'; mapa['p'] = 'b'; mapa['['] = ';';
    mapa[']'] = '='; mapa['a'] = '7'; mapa['s'] = '8'; mapa['d'] = '9'; mapa['f'] = 'a';
    mapa['g'] = 'e'; mapa['h'] = 'h'; mapa['j'] = 't'; mapa['k'] = 'd'; mapa['l'] = 'c';
    mapa[';'] = 'k'; mapa['\''] = '-'; mapa['z'] = '0'; mapa['x'] = 'z'; mapa['c'] = 'x';
    mapa['v'] = ','; mapa['b'] = 'i'; mapa['m'] = 'w'; mapa[','] = 'v'; mapa['.'] = 'g';
    mapa['/'] = '\'';

    mapa['$'] = 'Q'; mapa['%'] = 'J'; mapa['^'] = 'L'; mapa['&'] = 'M'; mapa['*'] = 'F';
    mapa['('] = 'P'; mapa[')'] = '?'; mapa['_'] = '{'; mapa['+'] = '}'; mapa['Q'] = '$';
    mapa['W'] = '%'; mapa['E'] = '^'; mapa['R'] = '>'; mapa['T'] = 'O'; mapa['Y'] = 'R';
    mapa['U'] = 'S'; mapa['I'] = 'U'; mapa['O'] = 'Y'; mapa['P'] = 'B'; mapa['{'] = ':';
    mapa['}'] = '+'; mapa['A'] = '&'; mapa['S'] = '*'; mapa['D'] = '('; mapa['F'] = 'A';
    mapa['G'] = 'E'; mapa['H'] = 'H'; mapa['J'] = 'T'; mapa['K'] = 'D'; mapa['L'] = 'C';
    mapa[':'] = 'K'; mapa['"'] = '_'; mapa['Z'] = ')'; mapa['X'] = 'Z'; mapa['C'] = 'X';
    mapa['V'] = '<'; mapa['B'] = 'I'; mapa['M'] = 'W'; mapa['<'] = 'V'; mapa['>'] = 'G';
    mapa['?'] = '"';
}

int main(){
    pre();
    string n;
    while(getline(cin, n)){
        string res = "";
        forr(i,n.size()){
            if(mapa.find(n[i]) != mapa.end())
                res.push_back(mapa[n[i]]);
            else
                res.push_back(n[i]);
        }
        cout << res << '\n';
    }
    return 0;
}


