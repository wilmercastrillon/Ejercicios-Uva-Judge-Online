#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

int fuerza(int n){
    deque<int> dq;
    forr(i,n)
        dq.push_back(i+1);

    while(dq.size() > 1){
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return dq.front();
}

int solve(int n){
    int k = 0, pot = 1;
    while(pot<<1 < n) pot <<= 1, k++;

    //printf("pot = %d\n", pot);
    if(pot == n) return n;
    else return 2*(n-pot);
}

int main(){
    int n;

    while(scanf("%d", &n), n){
        printf("%d\n", solve(n));
    }
    return 0;
}


