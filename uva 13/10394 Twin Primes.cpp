#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int m = 18409202, limit = (m / 6) + 1;
bitset<18409202> primo;
bitset<18409202> used;
bool sig;
vector<ii> gemelos;

void ciclo(int p, int con){
    if(p*con > limit){ sig = false; return; }
    int p6 = p*6;
    for(int n = con, np6 = p6*con; np6 - p < m; n++, np6= p6*n){
        used[np6 - p] = true;
        if(np6 + p < m) used[np6 + p] = true;
    }
}

void criba_6np(){
    int q, w, con = 0; sig = true;
    primo[2] = primo[3] = true;

    for(int i = 6; i < m; i += 6){
        q = i - 1; w = i + 1;
        if(used[q] && used[w]) continue;

        con++;
        if(!used[q]){
            primo[q] = true;
            if(sig) ciclo(q, con);
        }
        if(!used[w]){
            primo[w] = true;
            if(sig) ciclo(w, con);
        }
        if(primo[q] && primo[w]) gemelos.push_back(ii(q, w));
    }
}

int main(){
    int n;
    gemelos.push_back(ii(3, 5));
    gemelos.push_back(ii(3, 5));
    criba_6np();
    //cout << gemelos.size() << endl;

    while(scanf("%d", &n) != EOF)
        printf("(%d, %d)\n", gemelos[n].first, gemelos[n].second);

    return 0;
}


