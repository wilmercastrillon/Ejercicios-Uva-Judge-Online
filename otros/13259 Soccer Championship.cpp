#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#define forr(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i <= b; i++)

using namespace std;
typedef unsigned long long int ulli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

struct equipo{
    string nombre;
    int puntos;
    int dif;
    int goles;
    int golesVis;
} team[200];

struct match{
    int team1;
    int team2;
    int gteam1;
    int gteam2;
} partidos[200];

string input[100];
map<string, int> mapa;

string getNombreEquipo(int ini, int fin){
    string str = input[ini];
    for(int i = ini + 1; i <= fin; i++){
        str = str + " ";
        str = str + input[i];
    }
    return str;
}

bool cmp(equipo &e1, equipo &e2){
    if(e1.puntos != e2.puntos){
        return e1.puntos > e2.puntos;
    }else if(e1.dif != e2.dif){
        return e1.dif > e2.dif;
    }else if(e1.goles != e2.goles){
        return e1.goles > e2.goles;
    }else if(e1.golesVis != e2.golesVis){
        return e1.golesVis > e2.golesVis;
    }else{
        return e1.nombre < e2.nombre;
    }
}

int main(){
    int n;
    string in, token;

    while(cin >> n){
        string t1="", t2="";
        int idx = 1, pos, vs, p1, p2;
        mapa.clear();

        getchar();
        forr(i, n){
            getline(cin, in);
            stringstream ss(in);
            pos = 0;
            vs = -1;

            while(ss >> token){
                if(token == "vs.") vs = pos;
                input[pos++] = token;
            }

            t1 = getNombreEquipo(0, vs - 2);
            t2 = getNombreEquipo(vs + 2, pos - 1);

            if(mapa[t1] == 0){
                p1 = idx;
                team[idx].nombre = t1;
                team[p1].goles = team[p1].dif = team[p1].golesVis = team[p1].puntos = 0;
                mapa[t1] = idx++;
                //printf("\tl|se crea el %s con pos %d\n", t1.c_str(), idx-1);
            }else{
                p1 = mapa[t1];
            }
            if(mapa[t2] == 0){
                p2 = idx;
                team[idx].nombre = t2;
                team[p2].goles = team[p2].dif = team[p2].golesVis = team[p2].puntos = 0;
                mapa[t2] = idx++;
                //printf("\tv|se crea el %s con pos %d\n", t2.c_str(), idx-1);
            }else{
                p2 = mapa[t2];
            }

            partidos[i].team1 = p1;
            partidos[i].team2 = p2;
            partidos[i].gteam1 = atoi(input[vs-1].c_str());
            partidos[i].gteam2 = atoi(input[vs+1].c_str());

            if(partidos[i].gteam1 > partidos[i].gteam2){
                team[p1].puntos += 3;
                //printf("\t gana el %s\n", team[p1].nombre.c_str());
            }else if(partidos[i].gteam1 < partidos[i].gteam2){
                team[p2].puntos += 3;
                //printf("\t gana el %s\n", team[p2].nombre.c_str());
            }else{
                team[p1].puntos++;
                team[p2].puntos++;
                //printf("\t empatan %s con %s\n", team[p1].nombre.c_str(),team[p2].nombre.c_str());
            }

            team[p1].goles += partidos[i].gteam1;
            team[p2].goles += partidos[i].gteam2;
            team[p1].dif += (partidos[i].gteam1 - partidos[i].gteam2);
            team[p2].dif += (partidos[i].gteam2 - partidos[i].gteam1);
            team[p2].golesVis += partidos[i].gteam2;
        }

        int c = 0;
        forr(i, n){
            if(partidos[i].gteam1 < partidos[i].gteam2 && cmp(team[partidos[i].team1], team[partidos[i].team2])){
                //printf("%s %d vs %d %s ###GANA:### %d\n", team[partidos[i].team1].nombre.c_str(), partidos[i].gteam1,
                //        partidos[i].gteam2, team[partidos[i].team2].nombre.c_str(),
                //       cmp(team[partidos[i].team1], team[partidos[i].team2]));
                c++;
            }
            if(partidos[i].gteam1 > partidos[i].gteam2 && !cmp(team[partidos[i].team1], team[partidos[i].team2])){
                //printf("%s %d vs %d %s ###GANA:### %d\n", team[partidos[i].team1].nombre.c_str(), partidos[i].gteam1,
                //        partidos[i].gteam2, team[partidos[i].team2].nombre.c_str(),
                //       cmp(team[partidos[i].team1], team[partidos[i].team2]));
                c++;
            }
        }

        sort(team+1, team + mapa.size() + 1, cmp);
        //printf("----------------\n");

        printf("The paradox occurs %d time(s).\n", c);
        forab(i, 1, mapa.size()){
            printf("%d. %s\n", i, team[i].nombre.c_str());
        }
        //printf("----------------\n");
    }

    return 0;
}


