#include<bits/stdc++.h>

using namespace std;

int arr[3], a, b;
bool ocupados[53];

int siguiente(int b){
    for(int j = b + 1; j < 53; j++)
        if(!ocupados[j]) return j;
    return -1;
}

int buscar(){
    int x = -1;
    bool s1 = a > arr[0], s2 = b > arr[1];

    if(s1 || s2){
        if(s1 && s2){
            x = siguiente(0);
        }else{
            x = siguiente(arr[2]);
            if(x == -1) return x;
        }
    }else{
        return -1;
    }

    s1 = a > arr[1];
    s2 = b > arr[2];
    if(s1 || s2){
        if(s1 && s2){
            x = max(x, siguiente(0));
        }else{
            int aux = siguiente(arr[0]);
            if(aux == -1) return aux;
            x = max(x, aux);
        }
    }else{
        return -1;
    }

    s1 = a > arr[2];
    s2 = b > arr[0];
    if(s1 || s2){
        if(s1 && s2){
            x = max(x, siguiente(0));
        }else{
            int aux = siguiente(arr[1]);
            if(aux == -1) return aux;
            x = max(x, aux);
        }
    }else{
        return -1;
    }
    //sssssssssssssssssssssssssssssssssssssss
    s1 = a > arr[1];
    s2 = b > arr[0];

    if(s1 || s2){
        if(s1 && s2){
            x = max(x, siguiente(0));
        }else{
            int aux = siguiente(arr[2]);
            if(aux == -1) return aux;
            x = max(x, aux);
        }
    }else{
        return -1;
    }

    s1 = a > arr[2];
    s2 = b > arr[1];
    if(s1 || s2){
        if(s1 && s2){
            x = max(x, siguiente(0));
        }else{
            int aux = siguiente(arr[0]);
            if(aux == -1) return aux;
            x = max(x, aux);
        }
    }else{
        return -1;
    }

    s1 = a > arr[0];
    s2 = b > arr[2];
    if(s1 || s2){
        if(s1 && s2){
            x = max(x, siguiente(0));
        }else{
            int aux = siguiente(arr[1]);
            if(aux == -1) return aux;
            x = max(x, aux);
        }
    }else{
        return -1;
    }
    return x;
}

int main(){
    //freopen ("myfile.txt","w",stdout);
    while(scanf("%d %d %d %d %d", &arr[0],&arr[1], &arr[2], &a, &b) && arr[0]){
        memset(ocupados, 0, sizeof(ocupados));
        for(int i = 0; i < 3; i++) ocupados[arr[i]] = 1;
        ocupados[a] = ocupados[b] = 1;
        printf("%d\n", buscar());
    }
    return 0;
}
