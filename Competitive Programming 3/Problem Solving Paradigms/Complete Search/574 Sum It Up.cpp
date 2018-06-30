#include <bits/stdc++.h>

using namespace std;

int t, n, con;
int ar[110], res[110], used[110];
map<string, bool> mapa;
vector<string> vs;

void backtraking(int sum, int pos, int ant){
    int i, l, aux;
    if(sum == t){
        l = pos - 1;
        stringstream ss;
        for(i = 0; i < l; i++)ss << res[i], ss << "+";
        ss << res[l];
        if(mapa.count(ss.str()) == 0){
            vs.push_back(ss.str());
            mapa[ss.str()] = true;
            con++;
        }
        return;
    }

    for(i = ant; i < n; i++){
        if(used[i]) continue;
        aux = sum + ar[i];
        if(aux <= t){
            used[i] = 1;
            res[pos] = ar[i];
            backtraking(aux, pos + 1, i + 1);
            used[i] = 0;
        }
    }
}

int main(){
    int i;

    while(scanf("%d %d", &t, &n), n){
        vs.clear();
        mapa.clear();
        for(i = 0; i < n; i++){
            scanf("%d", &ar[i]);
        }

        memset(used, 0, sizeof(used));
        backtraking(0, 0, 0);
        printf("Sums of %d:\n", t);
        if(!vs.size()) printf("NONE\n");
        for(int i = 0; i < vs.size(); i++)
            printf("%s\n", vs[i].c_str());
    }

    return 0;
}


