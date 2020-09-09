#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<int, int> ii;
typedef pair<string, int> si;

#define maxn 120005
char cad[maxn];
int c[maxn];
int len_cad, len_subcad;//len t, len p
int ra[maxn], temp_ra[maxn], sa[maxn], temp_sa[maxn];

char subcad[maxn];

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
        temp_sa[c[(sa[i]+k<len_cad)?
            ra[sa[i]+k] : 0]++] = sa[i];
    for(int i = 0; i < len_cad; ++i) sa[i] = temp_sa[i];
}

void construir_SA(){//hasta 10^5 caracteres
    //strcat(cad,"$");
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

ii stringMatching() { // string matching in O(m log n)
    len_subcad = strlen(subcad);
    int lo = 0, hi = len_cad-1, mid = lo; // valid matching = [0..n-1]
    while (lo < hi) { // find lower bound
        mid = (lo + hi) / 2; // this is round down
        int res = strncmp(cad + sa[mid], subcad, len_subcad); // try to find P in suffix ’mid’
        if (res >= 0) hi = mid; // prune upper half (notice the >= sign)
        else lo = mid + 1; // prune lower half including mid
    } // observe ‘=’ in "res >= 0" above
    if (strncmp(cad + sa[lo], subcad, len_subcad) != 0) return ii(-1, -1); // if not found
    ii ans; ans.first = lo;
    lo = 0; hi = len_cad - 1; mid = lo;
    while (lo < hi) { // if lower bound is found, find upper bound
        mid = (lo + hi) / 2;
        int res = strncmp(cad + sa[mid], subcad, len_subcad);
        if (res > 0) hi = mid; // prune upper half
        else lo = mid + 1; // prune lower half including mid
    } // (notice the selected branch when res == 0)
    if (strncmp(cad + sa[hi], subcad, len_subcad) != 0) hi--; // special case
    ans.second = hi;
    return ans;
}

vector<si> words;
vector<int> idxInicial(20005);

bool cmp(si &a, si &b){
    if(a.first.size() != b.first.size())
        return a.first.size() < b.first.size();
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second < b.second;
}

bool cmp2(int a, int b){
    return idxInicial[a] < idxInicial[b];
}

int owner[maxn];
void Owners(){
    int x = 0;
    forr(i, len_cad){
        if(cad[i] != '{')
            owner[i] = x;
        else{
            x++;
            owner[i] = -1;
        }
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    cin.tie(NULL);
    int n, q;
    string in;

    while(scanf("%d", &n) != EOF){
        forr(i, n){
            cin >> in;
            words.pb(si(in,i));
        }

        int pos = 0;
        forr(i, n){
            in = words[i].first;
            forr(j, in.size())
                cad[pos++] = in[j];
            cad[pos++] = '{';
        }
        cad[pos] = '\0';
        construir_SA();
        Owners();
        //printf("%s\n", cad);

        map<si, int> idx;
        si par;
        forr(i, n){
            idx[words[i]] = i;
        }
        sort(words.begin(), words.end(), cmp);
        forr(i, n){
            idxInicial[idx[words[i]]] = i;
            //printf("%2d -> %2d| %s\n", idx[words[i]], i, words[i].c_str());
        }

        scanf("%d", &q);
        forr(i, q){
            scanf("%s", &subcad);
            ii pos = stringMatching();
            if (pos.first != -1 && pos.second != -1) {
                unordered_set<int> res;
                for (int i = pos.first; i <= pos.second; i++){
                    //printf("%2d | %.*s\n", owner[sa[i]], 10, cad + sa[i]);
                    res.insert(owner[sa[i]]);
                }
                vector<int> imp(res.begin(), res.end());
                sort(imp.begin(), imp.end(), cmp2);
                int l = imp.size();
                l = min(10, l);
                printf("%d", imp[0]+1);
                forab(i,1,l){
                    /*if(!cmp2(imp[i], imp[i+1])){
                        printf("Eror con %d < %d\n", idxInicial[imp[i]], idxInicial[imp[i+1]]);
                        if(!(idxInicial[imp[i]] < idxInicial[imp[i+1]]))
                            printf("que????????????????????????\n");
                    }*/
                    printf(" %d", imp[i]+1);
                }
                printf("\n");
            }else printf("-1\n");
        }
    }

    return 0;
}


