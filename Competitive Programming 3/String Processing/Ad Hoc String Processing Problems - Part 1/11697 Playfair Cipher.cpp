#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int, int> ii;

char tab[5][5];
string key, cad;
bool pos[26];

void buid(){
    memset(pos, false, sizeof(pos));
    int i = 0, j = 0;
    forr(k, key.size()){
        if(key[k] == ' ' || pos[key[k]-'a']) continue;
        tab[i][j] = key[k];
        //printf("(%d, %d) = %c\n", i, j, key[k]);
        pos[key[k]-'a'] = true;
        j++;
        if(j >= 5){
            j = 0;
            i++;
        }
    }
    forr(k, 26){
        if(pos[k] || (k + 'a') == 'q') continue;
        tab[i][j] = k + 'a';
        //printf("(%d, %d) = %c\n", i, j, (k + 'a'));
        j++;
        if(j >= 5){
            j = 0;
            i++;
        }
    }
}

void imp(){
    forr(i, 5){
        forr(j, 5){
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}

void nextChar(char &c1, char &c2, int &idx){
    while(cad[idx] == ' ') idx++;
    //printf("idx = %d ", idx);
    c1 = cad[idx++];
    //printf("| c= %c\n", c1);
    if(idx >= cad.size()){
        c2 = 'x';
        return;
    }
    while(cad[idx] == ' ') idx++;
    c2 = cad[idx++];
    if(c1 == c2){
        c2 = 'x';
        idx--;
    }
}

void buscar(char &c1, char &c2, ii &p1, ii &p2){
    bool a1, a2;
    forr(i, 5){
        forr(j, 5){
            if((c1 == tab[i][j]))
                p1 = ii(i, j);
            if((c2 == tab[i][j]))
                p2 = ii(i, j);
        }
    }
}

int main(){
    int n;
    cin >> n;
    getchar();

    while(n--){
        getline(cin, key);
        buid();
        getline(cin, cad);

        int idx = 0;
        char c1, c2;
        ii p1, p2;
        string res = "";
        while(idx < cad.size()){
            nextChar(c1, c2, idx);
            buscar(c1, c2, p1, p2);

            if(p1.first == p2.first){
                res.push_back(toupper(tab[p1.first][(p1.second+1)%5]));
                res.push_back(toupper(tab[p2.first][(p2.second+1)%5]));
            }else if(p1.second == p2.second){
                res.push_back(toupper(tab[(p1.first+1)%5][p1.second]));
                res.push_back(toupper(tab[(p2.first+1)%5][p2.second]));
            }else{
                res.push_back(toupper(tab[p1.first][p2.second]));
                res.push_back(toupper(tab[p2.first][p1.second]));
            }
        }
        cout << res << '\n';
    }
    return 0;
}


