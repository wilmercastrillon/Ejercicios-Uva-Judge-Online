#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso, nodo
typedef pair<int, string> is;
typedef pair<int, is> iis;//peso, nodo, idioma-anterior
typedef pair<string, string> ss;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
#define mp(a, b, c) iis(a, is(b, c))

//vi padre;
vector<string> p;
vector<ss> idiomas;
string ini, fin;
map<string, int> mapa;

vi dijkstra(vvii &grafo, int nodo, int tam){
    vi dis(tam + 1, inf);
    //padre.assign(tam+1, -1);
    priority_queue<iis> cola;
    if(idiomas[nodo].first == ini) cola.push(mp(-0, nodo, idiomas[nodo].second));
    else cola.push(mp(-0, nodo, idiomas[nodo].first));
    int peso, aux;
    string ant, next;
    ii par, par2;
    iis triple;

    while(cola.size()){
        triple = cola.top();
        cola.pop();
        peso = -triple.first;
        nodo = triple.second.first;
        ant = triple.second.second;

        if(dis[nodo] <= peso) continue;
        dis[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            par2 = grafo[nodo][i];
            if(idiomas[par2.second].first != ant && idiomas[par2.second].second != ant) continue;
            aux = dis[nodo] + par2.first;
            if(idiomas[par2.second].first == ant) next = idiomas[par2.second].second;
            if(idiomas[par2.second].second == ant) next = idiomas[par2.second].first;

            if(dis[par2.second] > aux){
                cola.push(mp(-aux, par2.second, next));
                //padre[par2.second] = nodo;
            }
        }
    }

    return dis;
}

/*void camino(int n){//imprimir el camino
    if(padre[n] == -1) printf("%s", p[n].c_str());
    else{
        camino(padre[n]);
        printf(" %s", p[n].c_str());

    }
}*/

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, x, y, z, con;
    string l1, l2, cad;

    while(cin >> m){
        if(!m) break;
        vvii grafo(2002);
        con = 1;

        cin >> ini >> fin;
        p.clear();
        idiomas.clear();
        vector<int> nodoIni, nodoFin;

        for(int i = 0; i < m; i++){
            cin >> l1 >> l2 >> cad;
            p.push_back(cad);
            idiomas.push_back(ss(l1, l2));
            if(ini == l1 || ini == l2) nodoIni.push_back(i);
            if(fin == l1 || fin == l2) nodoFin.push_back(i);
        }

        for(int i = 0; i < p.size(); i++){
            for(int j = i + 1; j < p.size(); j++){
                if(p[i][0] != p[j][0]){
                    if(idiomas[i].first == idiomas[j].first ||
                       idiomas[i].first == idiomas[j].second ||
                       idiomas[i].second == idiomas[j].first ||
                       idiomas[i].second == idiomas[j].second){
                        /*cout << p[i] << " comparte idioma con " << p[j] << " |||   ";
                        cout << idiomas[i].first << "," << idiomas[i].second << " | " <<
                                idiomas[j].first << "," << idiomas[j].second << endl;*/
                        //printf("camino de %s a %s\n", p[i].c_str(), p[j].c_str());
                        grafo[i].push_back(ii(p[i].size(), j));
                        grafo[j].push_back(ii(p[j].size(), i));
                    }
                }
            }
        }

        int res = inf, q;
        for(int i = 0; i < nodoIni.size(); i++){
            vi v = dijkstra(grafo, nodoIni[i], p.size());
            for(int j = 0; j < nodoFin.size(); j++){
                q = v[nodoFin[j]] + p[nodoFin[j]].size();
                //printf("camino desde %s a %s es \n", p[nodoIni[i]].c_str(), p[nodoFin[j]].c_str());
                //camino(nodoFin[j]);
                //printf("\n");
                res = min(res, q);
            }
        }
        if(res == inf) cout << "impossivel\n";
        else cout << res << '\n';
    }

    return 0;
}


