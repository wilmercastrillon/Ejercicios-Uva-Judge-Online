#include <bits/stdc++.h>

using namespace std;

unsigned tab[11], mask[11];
typedef unsigned int uii;

void duplicate(){
    for(uii i = 0; i < 11; i++){
        mask[i] = tab[i];
        for(uii j = 0; j < 10; j++){
            //printf("%u", (tab[i]&(1<<j)) > 0);
        }
        //printf("\n%u ==== %u === %u\n", i, tab[i], mask[i]);
    }
}

void imp(){
    for(uii i = 0; i < 10; i++){
        for(uii j = 0; j < 10; j++){
            printf("%u", (mask[i]&(1<<j)) > 0);
        }
        printf("\n");
    }
}

uii solve(){
    uii l = 1<<10;
    uii men = 1000000000;
    for(uii i = 0; i < l; i++){
        duplicate();
        uii op = 0;
        //printf("intento %d al oprimir %d\ninicia:\n", i, op);
        //imp();
        for(uii j = 0; j < 10; j++){
            if(i&(1<<j)){
                mask[0] = mask[0]^((7<<j)>>1);
                mask[1] = mask[1]^(1<<j);
                op++;
            }
        }

        for(int k = 1; (k < 10) && (op<=100); k++){
            for(uii j = 0; j < 10; j++){
                if(mask[k-1]&(1<<j)){
                    //printf("encendido fila %u, col %u cambian %u %u %u ", k, j, mask[k-1], mask[k], mask[k+1]);
                    op++;
                    mask[k-1] = mask[k-1]^(1<<j);
                    mask[k] = mask[k]^((7<<j)>>1);
                    mask[k+1] = mask[k+1]^(1<<j);
                    //printf("a %u %u %u\n", mask[k-1], mask[k], mask[k+1]);
                }
            }
        }
        if((mask[9]&(l-1)) == 0){
            men = min(men, op);
        }
        //printf("termina:\n");
        //imp();
        //printf("\n");
    }
    return men;
}

int main(){
    freopen("salida.txt", "w", stdout);
    string cad, fil;

    while(true){
        getline(cin, cad);
        if(cad == "end") break;

        for(uii i = 0; i < 10; i++){
            cin >> fil;
            tab[i] = 0;
            for(uii j = 0; j < 10; j++){
                tab[i] <<= 1;
                tab[i] |= ((uii) fil[j]=='O');
                //printf("%u|",(uii) fil[j]=='O');
            }
            //printf("\n%u = %u\n", i, tab[i]);
        }
        while (cin.get() != '\n');

        duplicate();
        //imp();
        int res = (int) solve();
        if(res > 100) res = -1;
        cout << cad << ' ' << res << endl;
    }

    return 0;
}


