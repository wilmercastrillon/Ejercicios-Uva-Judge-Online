#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    int casos, n, g, b, x;
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d %d %d", &n, &g, &b);
        priority_queue<int> colag, colab;

        for(int j = 0; j < g; j++){
            scanf("%d", &x);
            colag.push(x);
        }
        for(int j = 0; j < b; j++){
            scanf("%d", &x);
            colab.push(x);
        }

        vector<int> auxg, auxb;
        while(colag.size() && colab.size()){
            auxg.clear();
            auxb.clear();
            int a, b;
            for(int k = 0; k < n && colag.size() && colab.size(); k++){
                a = colag.top();
                colag.pop();
                b = colab.top();
                colab.pop();
                if(a > b) auxg.push_back(a - b);
                else if(b > a) auxb.push_back(b - a);
            }

            for(int j = 0; j < auxg.size(); j++) colag.push(auxg[j]);
            for(int j = 0; j < auxb.size(); j++) colab.push(auxb[j]);
        }

        if(!colag.size() && !colab.size()) printf("green and blue died\n");
        else if(!colag.size()){
            printf("blue wins\n");
            while(colab.size()){
                printf("%d\n", colab.top());
                colab.pop();
            }
        }else{
            printf("green wins\n");
            while(colag.size()){
                printf("%d\n", colag.top());
                colag.pop();
            }
        }

        if(i != casos - 1) printf("\n");
    }

    return 0;
}


