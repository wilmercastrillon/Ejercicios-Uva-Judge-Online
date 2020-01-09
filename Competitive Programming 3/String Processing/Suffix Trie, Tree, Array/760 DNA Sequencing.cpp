#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

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

vector<string> LCS(){
    int l = strlen(cad), best = -1;
    strcat(cad,"."); strcat(cad,subcad); strcat(cad,"$");
    buid_sa();  LCP();
    string aux;  set<string> ss;  vector<string> res;

    forr(i,len_cad){
        if(lcp[i] < best) continue;
        if((sa[i]>l && sa[i-1]>l) || (sa[i]<l&&sa[i-1]<l) || lcp[i]<1)
            continue;

        aux = "";
        forr(j,lcp[i]) aux.push_back(cad[sa[i]+j]);
        if(lcp[i]>best){
            best = lcp[i];
            ss.clear();
            ss.insert(aux);
        }else if(lcp[i]==best) ss.insert(aux);
    }
    res.assign(ss.begin(),ss.end());
    return res;
}

int main(){
    freopen("salida.txt","w",stdout);
    scanf("%s", &cad);

    while(true){
        scanf("%s", &subcad);

        vector<string> vs = LCS();
        if(vs.size()){
            string s;
            forr(i,vs.size()){
                s = vs[i];
                cout << s << endl;
            }
        }else{
            printf("No common sequence.\n");
        }

        if(scanf("%s", &cad) == EOF) break;
        printf("\n");
    }

    return 0;
}


