#include <bits/stdc++.h>

using namespace std;

bool grande[110];
bool vis[110];

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int t, n, m, d;
    string str;
    char s[2];
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d %d", &n, &d);
        memset(vis, false, sizeof(vis));

        vector<int> dist;
        dist.push_back(0);
        for(int j = 0; j < n; j++){
            cin >> str;
            dist.push_back(atoi(str.substr(2).c_str()));
            grande[j+1] = (str[0] == 'B');
        }
        dist.push_back(d);
        grande[0] = grande[dist.size()-1] = true;

        int res = -1, lim = dist.size() - 1;
        for(int j = 0; j < lim; j++){
            //cout << "c1, lim " << lim << " j: " << j << " \n";
            vis[j] = true;
            if(grande[j + 1]){
                //cout << "c1 de " << dist[j] << " hasta " << dist[j+1] << endl;
                res = max(res, dist[j+1] - dist[j]);
            }else{
                //cout << "hola?\n";
                res = max(res, dist[j+2] - dist[j]);
                j++;
            }
        }
        for(int j = lim; j > 0; j--){
            //cout << "c2, lim " << lim << " j: " << j << " \n";
            if(!grande[j - 1] && vis[j-1]){
                res = max(res, dist[j] - dist[j - 2]);
                j--;
            }else{
                //cout << "c2 de " << dist[j] << " hasta " << dist[j-1] << endl;
                res = max(res, dist[j] - dist[j - 1]);
            }
        }

        printf("Case %d: %d\n", i, res);
    }
    return 0;
}


