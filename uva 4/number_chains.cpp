#include <bits/stdc++.h>

using namespace std;
vector<int> n;

bool contains(int num){
    for(int i = 0; i < n.size(); i++)
        if(n[i] == num) return true;

    return false;
}

int main() {
    //freopen ("myfile.txt","w",stdout);
    //freopen ("in.txt", "r", stdin);
    int m1, aux, m2, m3, con, index;
    vector<int> numeros;

    while(1){
        scanf("%d", &aux);
        if(aux == 0) break;
        printf("Original number was %d\n", aux);
        n.clear();
        con = 0;

        while(1){
            con++;
            numeros.clear();
            while(aux != 0){
                numeros.push_back(aux % 10);
                aux /= 10;
            }
            sort(numeros.begin(), numeros.end());

            m2 = 0, m1 = 0, index = numeros.size() - 1;
            for(int i = 0; i < numeros.size(); i++){
                m2 *= 10;
                m2 += numeros[i];
                m1 *= 10;
                m1 += numeros[index--];
            }

            m3 = m1 - m2;
            printf("%d - %d = %d\n", m1, m2, m3);
            if(contains(m3)) break;
            n.push_back(m3);
            aux = m3;
        }
        printf("Chain length %d\n\n", con);
    }

    return 0;
}
