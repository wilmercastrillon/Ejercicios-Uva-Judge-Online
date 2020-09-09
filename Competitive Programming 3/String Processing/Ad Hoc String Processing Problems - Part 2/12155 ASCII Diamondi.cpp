#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

char tab[20010][20010];
char imp[20010][20010];
int f1, c1, f2, c2, len;

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, caso = 0;

    while(scanf("%d %d %d %d %d", &n,&f1,&c1,&f2,&c2) != EOF){
        ++caso;
        if(!n) break;

        len = (n*2-1);
        int lf = f1%len, lc = c1%len;
        int lfinf = lf+(f2-f1), lfinc = lc+(c2-c1);//ultima fila y col
        int inif = (n-1)-lf, inic = (n-1)-lc;
        int auxf1, auxf2, auxc1, auxc2;

        bool lastf, lastc;
        int ii = 0, jj, auximpi = 0, auximpc = 0;
        do{
            lastf = inif+(n-1) >= (lfinf-lf);
            jj = 0;
            auxf1 = (ii)? 0: lf;
            auxf2 = (!lastf)? len: ((inif+lf)%len) + (lfinf-lf)-inif;

            do{
                lastc = (inic + (n-1)) >= lfinc-lc;
                auxc1 = (jj)? 0: lc;
                auxc2 = (!lastc)? len: ((inic+lc)%len) + (lfinc-lc)-inic;

                int impi = auximpi, impj = auximpc;
                char letra;
                forab(i, auxf1, auxf2+1){
                    forab(j, auxc1, auxc2+1){
                        //printf("%d, %d\n", impi, impj);
                        letra = ((abs(inif-impi) + abs(inic-impj)) % 26) + 'a';
                        if(abs(inif-impi) + abs(inic-impj) >= n){
                            letra = '.';
                        }

                        imp[impi][impj] = letra;
                        impj++;
                    }
                    impi++;
                    impj = auximpc;
                }

                inic += (n*2)-1;
                jj++;
                auximpc += (auxc2-auxc1);
            }while(!lastc);

            inic = (n-1)-lc;
            inif += (n*2)-1;
            ii++;
            auximpi += (auxf2-auxf1);
            auximpc = 0;
        }while(!lastf);

        printf("Case %d:\n", caso);
        int tamf = (f2-f1)+1, tamc = (c2-c1)+1;
        forab(i, 0, tamf){
            forab(j, 0, tamc){
                printf("%c", imp[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}


