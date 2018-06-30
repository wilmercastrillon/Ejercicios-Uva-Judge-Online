#include <stdio.h>
#include <iostream>
#include <bitset>

using namespace std;
typedef unsigned int ui;

int main(){
    ui n, men, may, nn, aux;

    while(scanf("%u %u %u", &n, &men, &may) != EOF){
        nn = ~n;
        aux = 0;
        for(int i = 31; i >= 0; i--){
            aux = aux | (1 << i);
            if((aux&nn) > (may&aux)){
                nn = nn ^ (1<<i);
                //printf("mayor apaguese\n");
            }
            if((aux&nn) < (men&aux)){
                nn = nn | (1<<i);
                //printf("menor enciendase\n");
            }
            if(nn >= men && nn <= may) break;
            //bitset<32> bs(nn);
            //string mystring = bs.to_string<char,std::string::traits_type,std::string::allocator_type>();
            //cout << "nn " << mystring << endl;
            //printf("nn: %u\n", nn);
        }
        printf("%u\n", nn);
    }

    return 0;
}


