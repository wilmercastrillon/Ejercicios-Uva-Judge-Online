#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

#define maxn 2010
string t;
int n;//strlen(t) + 1;
int ra[maxn], temp_ra[maxn];
int sa[maxn], temp_sa[maxn];
int c[maxn];

void countingSort(int k){
    int aux, may = max(300,n);
    memset(c,0,sizeof(c));
    for(int i = 0; i < n; ++i)
        c[(i+k<n)? ra[i+k] : 0]++;
    for(int i = 0, sum = 0; i < may; ++i){
        aux = c[i];
        c[i] = sum;
        sum += aux;
    }
    for(int i = 0; i < n; ++i)
        temp_sa[c[(sa[i]+k<n)? ra[sa[i]+k] : 0]++] = sa[i];
    for(int i = 0; i < n; ++i) sa[i] = temp_sa[i];
}

void buid_sa(string str){//hasta 10^5 caracteres
    t = str;
    t.push_back('$');
    n = t.size();
    int r;
    for(int i = 0; i < n; ++i){
        ra[i] = t[i];
        sa[i] = i;
    }
    for(int k = 1; k < n; k<<=1){
        countingSort(k);
        countingSort(0);
        temp_ra[sa[0]] = r = 0;
        for(int i = 1; i < n; ++i)
            temp_ra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k])?
                r: ++r;
        for(int i = 0; i < n; ++i) ra[i] = temp_ra[i];
        if(ra[sa[n-1]]==n-1) break;
    }
}

int phi[maxn], plcp[maxn], lcp[maxn];
void LCP(){//longest common prefix
    phi[sa[0]] = -1;
    for(int i = 1; i < n; ++i) phi[sa[i]] = sa[i-1];
    for(int i = 0, l = 0; i < n; ++i){
        if(phi[i]==-1){
            plcp[i] = 0;
            continue;
        }
        while(t[i+l]==t[phi[i]+l]) l++;
        plcp[i] = l;
        l = max(l-1,0);
    }
    for(int i = 0; i < n; ++i)
        lcp[i] = plcp[sa[i]];
}

int main(){
    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    string s;
    int m;
    cin >> m;

    while(m--){
        cin >> s;
        buid_sa(s);
        LCP();

        int mejor = 0, can = 1, lastidx = -1;
        for(int i = 0; i < n; i++){
            if(lcp[i] > mejor){
                mejor = lcp[i];
                can = 1;
                lastidx = i;
            }
            if(lcp[i]==mejor){
                //printf("empate? %d+1 == %d entonces suma\n", i,lastidx);
                if(i==lastidx+1){
                    can++;
                }else{
                    can = 1;
                }
                lastidx = i;
            }
            printf("%2d lcp %2d | cad %s | mejor %2d | cant %d\n", sa[i], lcp[i],t.substr(sa[i]).c_str(), mejor, can);
        }

        if(lastidx != -1)
            printf("%s %d\n", t.substr(sa[lastidx],mejor).c_str(), can);
        else
            printf("No repetitions found!\n");
    }

    return 0;
}


