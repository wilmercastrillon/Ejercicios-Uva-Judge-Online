#include <bits/stdc++.h>

using namespace std;
int bordes[100010], may;
bool match;

void preCalcular(string subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

void kmp(string cad, string subcad){
    int i = 0, j = 0, imay = 0;
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        //may = max(may, j);
        //printf("cad[%d] = %c | subcad[%d] = %c \n", i, cad[i], j, subcad[j]);
        i++; j++;
        if(j == subcad.size()){
            match = true;
            //printf("%s esta en el indice %d de la cadena: %s\n",
                   //subcad.c_str(), i - j, cad.c_str());
            j = bordes[j];
        }
    }
    may = j;
}

int main(){
    //freopen("Salida.txt", "w", stdout);
    cin.tie(NULL);
    string s, pal;

    while(getline(cin, s)){
        pal = string (s.rbegin(), s.rend());
        //cout << "reverse: " << pal << endl;
        may = 0; match = false;
        preCalcular(pal);
        kmp(s, pal);

        if(!match)
            for(int i = may; i < pal.size(); i++)
                s.push_back(pal[i]);

        cout << s << '\n';
    }
    return 0;
}


