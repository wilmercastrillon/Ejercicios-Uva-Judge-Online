#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;

int n, m;
struct agencia{
    int c1, c2, mejor, q;
    char cad[20];
};
vector<agencia> v;
char in1[50];

bool cmp(agencia &a, agencia &b){
    if(a.mejor != b.mejor)
        return a.mejor<b.mejor;
    return strcmp(a.cad,b.cad) < 0;
}

int solve(int pos){
    int res = 0, aux = n, x;
    int c1 = v[pos].c1, c2 = v[pos].c2;

    while(aux > m){
        if(aux/2 >= m){
            x = (aux-(aux/2))*c1;
            res += min(c2,x);
        }else{
            res += ((aux-m)*c1);
        }
        aux /= 2;
    }
    return res;
}

int main(){
    //freopen("salida.txt","w",stdout);
    int t, l,x,y, pos;
    scanf("%d", &t);
    forr(k,t){
        v.clear();
        scanf("%d %d %d", &n, &m, &l);

        forr(i,l){
            agencia ag;
            scanf("%s", &in1);
            x = strlen(in1);
            forr(j,x){
                if(!isalnum(in1[j]))
                    in1[j] = ' ';
            }
            sscanf(in1,"%s %d %d", &ag.cad,&ag.c1,&ag.c2);
            ag.q = i;
            v.push_back(ag);
            //printf("se tiene c1: %d c2: %d pos: %d nombre: %s\n",v[i].c1,v[i].c2,v[i].q,v[i].cad);
        }

        forr(i,l){
            v[i].mejor = solve(i);
            //printf("mejor %s es %d\n",v[i].cad,v[i].mejor);
        }

        sort(v.begin(),v.end(),cmp);
        printf("Case %d\n",k+1);
        forr(i,l){
            printf("%s %d\n",v[i].cad,v[i].mejor);
        }
    }

    return 0;
}


