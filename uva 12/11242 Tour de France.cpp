#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int f, r, x;

    while(scanf("%d", &f), f){
        vector<double> v1, v2;

        scanf("%d", &r);
        for(int i = 0; i < f; i++){
            scanf("%d", &x);
            v1.push_back(x);
        }

        for(int i = 0; i < r; i++){
            scanf("%d", &x);
            for(int j = 0; j < v1.size(); j++)
                v2.push_back((double) x / v1[j]);
        }

        double res = 0;
        sort(v2.begin(), v2.end());
        for(int i = 1; i < v2.size(); i++){
            res = max(res, v2[i] / v2[i - 1]);
        }

        printf("%.2f\n", res);
    }

    return 0;
}

