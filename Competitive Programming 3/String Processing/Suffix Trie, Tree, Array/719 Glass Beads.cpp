#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<int,int> ii;

#define maxn 101000
char cad[maxn], subcad[maxn], cadaux[maxn];
int len_cad, len_subcad;//len t, len p
int ra[maxn], temp_ra[maxn];
int sa[maxn], temp_sa[maxn];
int c[maxn];

void countingSort(int k){
    int aux, may = max(300,len_cad);
    memset(c,0,sizeof(c));
    for(int i = 0; i < len_cad; ++i)
        c[(i+k<len_cad)? ra[i+k] : 0]++;
    for(int i = 0, sum = 0; i < may; ++i){
        aux = c[i];
        c[i] = sum;
        sum += aux;
    }
    for(int i = 0; i < len_cad; ++i)
        temp_sa[c[(sa[i]+k<len_cad)? ra[sa[i]+k] : 0]++] = sa[i];
    for(int i = 0; i < len_cad; ++i) sa[i] = temp_sa[i];
}

void buid_sa(){//hasta 10^5 caracteres
    strcat(cad,"{");
    len_cad = strlen(cad);

    int r;
    for(int i = 0; i < len_cad; ++i){
        ra[i] = cad[i];
        sa[i] = i;
    }
    for(int k = 1; k < len_cad; k<<=1){
        countingSort(k);
        countingSort(0);
        temp_ra[sa[0]] = r = 0;
        for(int i = 1; i < len_cad; ++i)
            temp_ra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k])?
                r: ++r;
        for(int i = 0; i < len_cad; ++i) ra[i] = temp_ra[i];
        if(ra[sa[len_cad-1]]==len_cad-1) break;
    }
}

int main(){
    cin.tie(NULL);
    int m, x;
    scanf("%d", &m);

    while(m--){
        scanf("%s", &cadaux);
        x = strlen(cadaux);
        strcpy(cad, cadaux);
        strcat(cad, cadaux);
        buid_sa();

        /*forr(i, len_cad){
            printf("%d | sa %d | %s\n", i, sa[i], cad + sa[i]);
        }*/
        printf("%d\n", (sa[0]%x) + 1);
    }

    return 0;
}


