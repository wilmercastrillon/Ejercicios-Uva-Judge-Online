#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<int,int> ii;

#define maxn 101000
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
        while(cad[i+l]==cad[phi[i]+l] && cad[i+l]!='$') l++;
        plcp[i] = l;
        l = max(l-1,0);
    }
    for(int i = 0; i < len_cad; ++i)
        lcp[i] = plcp[sa[i]];
}

int owner[maxn], auxowner[maxn];
char arr[110][1010];

void calcOwner(){
    auxowner[0] = 0;
    int x = 0;
    //printf("el cad[%d] = %c en cadena %d\n", 0, cad[0], owner[0]);
    forab(i,1,len_cad){
        if(cad[i] != '$')
            auxowner[i] = x;
        else{
            x++;
            auxowner[i] = -1;
        }
        //printf("el cad[%d] = %c en cadena %d\n", i, cad[i], owner[i]);
    }

    forr(i,len_cad)
        owner[i] = auxowner[sa[i]];
}

int vis[250];
char cadaux[1010];

int main(){
    cin.tie(NULL);
    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt", "w", stdout);
    int m, x;
    scanf("%d", &m);

    while(m){
        scanf("%s", &cad);
        if(m == 1){
            printf("%s\n", cad);
            scanf("%d", &m);
            if(m==0) break;
            printf("\n");
            continue;
        }

        forab(i,1,m){
            scanf("%s", &arr[i]);
            strcat(cad,"$");
            strcat(cad,arr[i]);
        }

        buid_sa();
        LCP();
        calcOwner();

        int mejor = 0, length = (m/2), cont = 0, low = m, up = m, best = -1, menoridx, total = 1;
        memset(vis, 0, sizeof(vis));

        /*forr(i, len_cad){
            printf("i %2d |ow %2d | sa %2d | lcp %2d | %s\n", i, owner[i], sa[i], lcp[i], cad+sa[i]);
        }*/

        string str;
        set<string> res;
        vis[owner[up]]++;
        while(up < len_cad){
            //printf("rango %d %d\n", low, up);
            if(total <= length){
                //printf("Se expande por arriba\n");
                up++;
                if(up >= len_cad) break;
                if(vis[owner[up]] == 0) total++;
                vis[owner[up]]++;
            }else{
                menoridx = min_element(lcp + low + 1, lcp + up + 1) - lcp;
                if(lcp[menoridx] > best){
                    best = max(best, lcp[menoridx]);
                    //printf("mejor elemento en pos %d, corresponde %.*s\n", menoridx, best, cad + sa[menoridx]);
                    res.clear();
                    memcpy(cadaux,&cad[sa[menoridx]],best);
                    cadaux[best] = '\0';
                    res.insert((string) cadaux);
                }else if(lcp[menoridx] == best){
                    //printf("repite mejor %.*s\n", best, cad + sa[menoridx]);
                    memcpy(cadaux,&cad[sa[menoridx]],best);
                    cadaux[best] = '\0';
                    res.insert((string) cadaux);
                }
                vis[owner[low]]--;
                if(vis[owner[low]] == 0) total--;
                low++;
            }

        }

        //printf("mejor longitud = %d\n", best);
        int idx;
        if(best > 0){
            for(auto it=res.begin(); it!=res.end(); ++it){
                str = *it;
                cout << str << '\n';
                //printf("%.*s\n", best, cad + sa[idx]);
                //printf("%s\n", cad + sa[idx]);
            }
        }else printf("?\n");

        scanf("%d", &m);
        if(m==0) break;
        printf("\n");
    }

    return 0;
}


