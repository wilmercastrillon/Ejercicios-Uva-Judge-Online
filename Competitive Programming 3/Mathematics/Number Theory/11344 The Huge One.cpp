#include<bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

char cad[1010];
vector<int> v;

bool div(int d){
    int mod = 0, l = strlen(cad);
    //printf("\t cad %s con numero %d\n", cad, d);
    forr(i, l){
        mod = (10*mod) % d;
        mod = ((cad[i]-'0')+mod) % d;
    }
    //printf("\t %d\n", mod);
    return (mod==0);
}

int main(){
    int m, s, t;
    scanf("%d", &t);

    while(t--){
        scanf("%s", &cad);
        scanf("%d", &s);
        v.clear();

        forr(i, s){
            scanf("%d", &m);
            v.push_back(m);
        }

        bool w = true;
        forr(i,s){
            w = w && div(v[i]);
            if(!w) break;
        }

        if(w) printf("%s - Wonderful.\n", cad);
        else printf("%s - Simple.\n", cad);
    }

    return 0;
}


