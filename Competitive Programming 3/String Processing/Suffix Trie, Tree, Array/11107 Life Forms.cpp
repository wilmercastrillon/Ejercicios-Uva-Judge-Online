#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> ii;

#define maxn 2010
char cad[maxn], subcad[maxn];
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
    strcat(cad,"$");
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

int phi[maxn], plcp[maxn], lcp[maxn];
void LCP(){//longest common prefix
    phi[sa[0]] = -1;
    for(int i = 1; i < len_cad; ++i) phi[sa[i]] = sa[i-1];
    for(int i = 0, l = 0; i < len_cad; ++i){
        if(phi[i]==-1){
            plcp[i] = 0;
            continue;
        }
        while(cad[i+l]==cad[phi[i]+l]) l++;
        plcp[i] = l;
        l = max(l-1,0);
    }
    for(int i = 0; i < len_cad; ++i)
        lcp[i] = plcp[sa[i]];
}

ii stringMatching(){
    int lo, hi = len_cad-1, mid =lo;
    while(lo < hi){
        mid = (lo + hi)/2;
        int res = strncmp(cad+sa[mid],subcad,len_subcad);
        if(res >= 0) hi = mid;
        else lo = mid + 1;
    }

    if(strncmp(cad+sa[lo],subcad,len_subcad) != 0)
        return ii(-1,-1);
    ii ans;  ans.first = lo;
    lo = 0;  hi = len_cad-1;  mid = lo;

    while(lo < hi){
        mid = (lo + hi) / 2;
        int res = strncmp(cad+sa[mid],subcad,len_subcad);
        if(res > 0) hi = mid;
        else lo = mid + 1;
    }

    if(strncmp(cad+sa[hi],subcad,len_subcad)) hi--;
    ans.second = hi;
    return ans;
}

int mejor, owner[110];
char arr[110][1010];

void calcOwner(vector<int> &puntos){
    forr(i,len_cad){
        if(cad[sa[i]] == '#'){
            owner[i] = -1;
            continue;
        }
        owner[i] = lower_bound(puntos.begin(),puntos.end(),sa[i]) - puntos.begin();
    }
}

ii LCS(){//longitud e indice
    int idx = -1, mejorLCP = -1;
    forab(i,1,len_cad){
        if(owner[sa[i]] != owner[sa[i-1]] && lcp[i]>mejorLCP){
            mejorLCP = lcp[i];
            idx = i;
        }
    }
    return ii(mejorLCP,idx);
}

int main(){
    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt", "w", stdout);
    int m, x;
    scanf("%d", &m);

    while(m){
        scanf("%s", &cad);
        vector<int> puntos;
        forab(i,1,m){
            scanf("%s", &arr[i]);
            puntos.push_back(strlen(cad));
            strcat(cad,"#");
            strcat(cad,arr[i]);
        }
        puntos.push_back(strlen(cad));

        buid_sa();
        LCP();
        calcOwner(puntos);

        forr(i,len_cad){
            printf("ow %2d | sa %2d | %s\n", owner[i], sa[i],cad+sa[i]);
        }

        int con[maxn];
        int len_lcs = 0;
        memset(con,0,sizeof(con));

        for(int i=m,j=m,total=0; j<len_cad; ){
            printf("i %d, j %d, total %d\n",i,j,total);
            if(total <= m/2){
                if(!con[owner[j++]]++){
                    ++total;
                }
                printf("con= [");
                forr(k,len_cad){
                    printf("%2d,",con[k]);
                }
                printf("]\n");
                printf("ow = [");
                forr(k,len_cad){
                    printf("%2d,",owner[k]);
                }
                printf("]\n");
            }

            if(total > m/2){
                len_lcs = max(len_lcs,lcp[min_element(lcp+i+1,lcp+j) - lcp]);

                if(!--con[owner[i++]]){
                    --total;
                }
            }
        }

        if(!len_lcs){
            printf("?\n");
            continue;
        }

        int psa = -1;
        memset(con,0,sizeof(con));

        for(int i=m,j=m,total=0; j<len_cad; ){
            if(total <= m/2){
                if(!con[owner[j++]]++)
                    ++total;
            }
            if(total > m/2){
                int k = min_element(lcp+i+1,lcp+j) - lcp;
                if(lcp[k] == len_lcs && (psa==1||strncmp(cad+psa,cad+sa[k],len_lcs))){
                    psa = sa[k];
                    char c = cad[psa + len_lcs];
                    cad[psa + len_lcs] = '\0';
                    printf("%s\n",cad + psa);
                }
                if(!--con[owner[i++]]){
                    --total;
                }
            }
        }

        scanf("%d", &m);
        if(m==0) break;
        //printf("\n");
    }

    return 0;
}


