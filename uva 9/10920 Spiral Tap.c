#include <stdio.h>

typedef unsigned long long int ulli;

ulli mf[4];
ulli mc[4];

void llenar(){
    mf[0] = 1; mf[1] = 0; mf[2] = -1; mf[3] = 0;
    mc[0] = 0; mc[1] = -1; mc[2] = 0; mc[3] = 1;
}

void solve(ulli n, ulli lim){
    ulli i, f = (n >> 1) + 1, c = (n >> 1) + 1, dir = 0;
    ulli acum = 1, con = 1, con2 = 0;

    while(1){
        if(acum + con >= lim){
            //printf("estamos cerca\n");
            printf("Line = %llu, column = %llu.\n", f + (mf[dir] * (lim - acum)),
                    c + (mc[dir] * (lim - acum)));
            return;
        }
        acum += con;
        f += (mf[dir] * con);
        c += (mc[dir] * con);

        con2++;
        if(con2 == 2){
            con2 = 0;
            con++;
        }
        dir = (dir + 1) % 4;
        //printf("quedamos en %d %d el numero: %d\n", f, c, acum);
    }
}

int main(){
    ulli s, p;
    llenar();
    while(scanf("%llu %llu", &s, &p), s, p){
        solve(s, p);
    }

    return 0;
}


