#include <bits/stdc++.h>

using namespace std;

struct team{
    int numero = 0, maskres = 0, penality = 0, canres = 0;
    int conpenality[10];

    void iniciar(){
        memset(conpenality, 0, sizeof(conpenality));
    }

    void accepted(int n, int tiempo){
        if(maskres & (1 << n)) return;
        maskres = maskres | (1 << n);
        canres++;
        penality += tiempo + 20*(conpenality[n]);
    }
};

vector<team> vt;
map<int, int> mapa;

bool cmp(team &a, team &b){
    if(a.canres != b.canres) return a.canres > b.canres;
    if(a.penality != b.penality) return a.penality < b.penality;
    return a.numero < b.numero;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int casos, equipo, problema, tiempo;
    char cad[100], res[2];
    gets(cad);
    sscanf(cad, "%d", &casos);
    getchar();

    for(int i = 0; i < casos; i++){
        int con = 1;
        vt.clear();
        mapa.clear();

        while(gets(cad) && cad[0]!='\0'){
            sscanf(cad, "%d %d %d %s", &equipo, &problema, &tiempo, &res);

            team t;
            if(!mapa[equipo]){
                //cout << "nuevo se guarda en: " << con << endl;
                t.iniciar();
                t.numero = equipo;
                vt.push_back(t);
                mapa[equipo] = con++;
            }else{
                //cout << "existe en: " << mapa[equipo] << endl;
                t = vt[mapa[equipo] - 1];
            }
            //cout << "trabajamos con " << t.numero << " " << t.canres << " " << t.penality << endl;

            if(res[0] == 'C'){
                t.accepted(problema, tiempo);
                //cout << "aceptado " << t.numero << " " << t.canres << " " << t.penality << endl;
            }else if(res[0] == 'I'){
                t.conpenality[problema]++;
                //cout << "rechazado " << t.numero << " " << t.canres << " " << t.penality << endl;
            }

            vt[mapa[equipo] - 1] = t;
        }

        sort(vt.begin(), vt.end(), cmp);
        for(int j = 0; j < vt.size(); j++){
            printf("%d %d %d\n", vt[j].numero, vt[j].canres, vt[j].penality);
        }

        if(i != casos - 1) printf("\n");
    }

    return 0;
}
