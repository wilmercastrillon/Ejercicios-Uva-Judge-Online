#include <stdio.h>
#define true 1
#define false 0

int tcuadro, tcuadrito;
char cuadro[1000][1000];
char cuadrito[1000][1000];
char girar[1000][1000];

int contar(){
    int con = 0, i, lim = tcuadro-tcuadrito, j, k, l, aux, aux2;
    int i2, j2;
    short igual;

    for(i = 0; i <= lim; i++)
        for(j = 0; j <= lim; j++){
            aux = i + tcuadrito;
            aux2 = j + tcuadrito;
            igual = true;
            i2 = j2 = 0;

            for(k = i; k < aux; k++){
                for(l = j; l < aux2; l++){
                    if(cuadro[k][l] != cuadrito[i2][j2++]){
                        igual = false;
                        k = aux;
                        break;
                    }
                }
                i2++;
                j2 = 0;
            }

            if(igual) con++;
        }

    return con;
}

void rotar(){
    int i, j, k, l = 0;
    for(i = 0; i < tcuadrito; i++)
        for(j = 0; j < tcuadrito; j++)
            girar[i][j] = cuadrito[i][j];

    for(i = 0; i < tcuadrito; i++){
        k = tcuadrito;
        for(j = 0; j < tcuadrito; j++){
            cuadrito[i][j] = girar[--k][l];
        }
        l++;
        //printf("%s\n", cuadrito[i]);
    }
    //printf("---------------------------\n");
}

int main(){
    int i;

    while(scanf("%d %d", &tcuadro, &tcuadrito), tcuadro){
        for(i = 0; i < tcuadro; i++) scanf("%s", &cuadro[i]);
        for(i = 0; i < tcuadrito; i++) scanf("%s", &cuadrito[i]);

        for(i = 0; i < 3; i++){
            printf("%d ", contar());
            rotar();
        }
        printf("%d\n", contar());
    }

    return 0;
}
