#include <bits/stdc++.h>

using namespace std;

struct autos{
    int men, may;
    char cad[30];
} carros[10010];

bool cmp(autos a, autos b){
    return a.men < b.men;
}

int main(){
    int casos, db, q, p;
    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &db);
        for(int i = 0; i < db; i++){
            scanf("%s %d %d", &carros[i].cad, &carros[i].men, &carros[i].may);
        }
        sort(carros, carros + db, cmp);

        scanf("%d", &q);
        string cad;
        for(int i = 0; i < q; i++){
            scanf("%d", &p);
            cad = "UNDETERMINED";

            for(int j = 0; j < db; j++){
                if(carros[j].men <= p && p <= carros[j].may){
                    if(cad != "UNDETERMINED"){
                        cad = "UNDETERMINED";
                        break;
                    }
                    cad = (string) carros[j].cad;
                }
            }

            printf("%s\n", cad.c_str());
        }

        if(casos != 0) printf("\n");
    }


    return 0;
}


