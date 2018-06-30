#include <stdio.h>
#include <math.h>

int max(int q, int w){ return (q > w)? q: w;}

int gcd(int a, int b){
	if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int lon(int a){
	int con = 0;
	
	do{
		a /= 10;
		con++;
	}while(a);
	return con;
}

void imprimir(int num, int den){
	int lon_a = lon(num), lon_b = lon(den);
	int may = max(lon_a, lon_b), j;
	
	for(j = may - lon_a; j > 0; j--) printf(" ");
	if(num < 0 || den < 0) printf("  ");
	printf("%d\n", abs(num));
	
	if(num < 0 || den < 0) printf("- ");
	for(j = may; j > 0; j--) printf("-");
	printf("\n");
	
	for(j = may - lon_b; j > 0; j--) printf(" ");
	if(num < 0 || den < 0) printf("  ");
	printf("%d\n", abs(den));
}

void imprimir_mixta(int n, int num, int den){
	int lon_a = lon(num), lon_b = lon(den), lon_c = lon(n);
	int may = max(lon_a, lon_b), j;
	
	for(j = may - lon_a + lon_c; j > 0; j--) printf(" ");
	if(n < 0) printf("  ");
	printf("%d\n", abs(num));
	
	if(n  < 0)
		printf("- %d", abs(n));
	else
		printf("%d", n);
	for(j = may; j > 0; j--) printf("-");
	printf("\n");
	
	for(j = may - lon_b + lon_c; j > 0; j--) printf(" ");
	if(n < 0) printf("  ");
	printf("%d\n", abs(den));
}

int main(){
	
	int m, i, acum, x, caso = 1;
	while(scanf("%d", &m), m){
		
		acum = 0;
		for(i = 0; i < m; i++){
			scanf("%d", &x);
			acum += x;
		}
		
		printf("Case %d:\n", caso++);
		int aux = gcd(acum, m);
		acum /= aux;
		m /= aux;
		
		if(acum % m){
			if(acum / m){
				imprimir_mixta(acum / m, acum % m, m);
				//printf("fraccion mixta %d  %d / %d", acum / m, acum % m, m);
			}else{
				imprimir(acum, m);
			}
		}else
			if(acum < 0)
				printf("- %d\n", abs(acum) / m);
			else
				printf("%d\n", acum / m);
	}
	
	return 0;
}
