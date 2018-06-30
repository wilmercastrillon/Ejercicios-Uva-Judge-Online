#include <stdio.h>
#include <math.h>

using namespace std;
int n, m, c[1010], sum;

bool val(int x){
    int acum = 0, con = 1;
    for(int i = 0; i < n; i++){
        if(c[i] > x) return false;
        if(acum + c[i] > x) acum = 0, con++;
        if(con > m) return false;
        acum += c[i];
    }
    return true;
}

int busquedaBinaria(){
    int men = 0, may = sum, med;
    int eps = 1, res = -1;

    while(may-men > eps){
        //printf("may: %d, men: %d, med: %d, f(med): ", may, men, med);
        med = (men+may)/2;
        if(val(med)){
            //printf("si\n");
            may = med;
        }else{
            //printf("no\n");
            men = med;
        }
    }
    return may;
}

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int x;
    while(scanf("%d %d",&n, &m)!=EOF){
        sum = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &c[i]), sum+=c[i];
        x = busquedaBinaria();
        printf("%d\n", x);
    }

    return 0;
}


