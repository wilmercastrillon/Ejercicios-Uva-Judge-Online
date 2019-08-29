#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int num1, num2, num3;
char cad1[10], cad2[10], cad3[10], op[2];
map<char,int> mapa;

void llenar(){
    mapa['V'] = 0;  mapa['U'] = 1;
    mapa['C'] = 2;  mapa['D'] = 3;
}

int main(){
    int t;
    llenar();
    scanf("%d", &t);

    printf("COWCULATIONS OUTPUT\n");
    while(t--){
        scanf("%s", &cad1);
        scanf("%s", &cad2);

        num1 = num2 = num3 = 0;
        forr(i,5){
            num1 *= 4;
            num1 += mapa[cad1[i]];
            num2 *= 4;
            num2 += mapa[cad2[i]];
        }
        forr(i,3){
            scanf("%s", &op);
            if(op[0] == 'A')
                num2 = num1 + num2;
            if(op[0] == 'R') num2 /= 4;
            if(op[0] == 'L') num2 *= 4;
        }

        scanf("%s", &cad3);
        forr(i,8){
            num3 *= 4;
            num3 += mapa[cad3[i]];
        }

        //printf("%d == %d\n", num2, num3);
        if(num3 == num2) printf("YES\n");
        else printf("NO\n");
    }
    printf("END OF OUTPUT\n");

    return 0;
}


