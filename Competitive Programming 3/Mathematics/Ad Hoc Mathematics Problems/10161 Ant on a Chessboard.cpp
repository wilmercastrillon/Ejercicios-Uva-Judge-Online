#include <bits/stdc++.h>
//#define forr(i,n) for(int

using namespace std;
typedef long long int lli;

vector<lli> col, fil;

void llenar(){
    lli n = 3, x = 0;
    col.push_back(-1);
    col.push_back(1);
    col.push_back(4);
    while(col.back() < 2000000001LL){
        if(n&1LL) col.push_back(col.back()+1LL);
        else col.push_back(4LL*n-5+col.back());
        n++;
    }

    n = 3;
    fil.push_back(-1);
    fil.push_back(1);
    fil.push_back(2);
    while(fil.back() < 2000000001LL){
        if(n%2 == 0) fil.push_back(fil.back()+1LL);
        else fil.push_back(4LL*n-5+fil.back());
        n++;
    }
    //return col.size();
}

int main(){
    int t, caso = 0, f, c, pos, posf;
    lli n;
    llenar();

    while(scanf("%lld", &n), n){
        pos = lower_bound(col.begin(), col.end(),n) - col.begin();
        posf = lower_bound(fil.begin(), fil.end(),n) - fil.begin();

        pos = min(pos, posf);
        int f, c;

        if(pos&1){
            if(n-col[pos] >= pos){
                f = pos;
                c = (pos-1)-((n-col[pos])-pos);
                //cout << "\t caso 1\n";
            } else{
                f = (n-col[pos])+1;
                c = pos;
                //cout << "\t caso 2\n";
            }
        }else{
            if(n-fil[pos] >= pos){
                f = (pos-1)-((n-fil[pos])-pos);
                c = pos;
                //cout << "\t caso 3\n";
            } else{
                f = pos;
                c = abs(n-fil[pos])+1;
                //cout << "\t caso 4\n";
            }
        }

        printf("%d %d\n", c, f);
    }
    return 0;
}


