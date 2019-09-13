#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

typedef long long int lli;
lli cx, cy;

lli gcd_ex(lli a, lli b, lli &x, lli &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	lli x1, y1;
	lli d = gcd_ex(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;//Maximo comun divisor
}

void solve(lli a, lli b, lli c){
    double q, w;
    lli x, y, d, xx, yy, men, may;
    d = gcd_ex(a,b,x,y);
    //printf("(%lld * %lld) / (%lld / %lld)\n",x,c,b,d);
    //printf("(%lld * %lld) / (%lld / %lld)\n",y,c,a,d);
    q = (double) x*c/b;
    w = (double) y*c/a;
    men = (lli) ceil(-1.0*q);
    may = (lli) floor(w);

    //printf("%lld <= n <= %lld\n",men, may);
    if(c%d || may < men){
        printf("failed\n");
        return;
    }
    //printf("ecuacion (%lld * %lld) + (%lld * %lld) = %d\n",a,x,b,y,d);

    xx = x*(c/d)+((b/d)*men);
    yy = y*(c/d)-((a/d)*men);
    lli bestx = xx, besty = yy, mejor = xx*cx + yy*cy;
    //printf("sol (%lld * %lld) + (%lld * %lld) = %d\n",a,xx,b,yy,c);
    xx = x*(c/d)+((b/d)*may);
    yy = y*(c/d)-((a/d)*may);
    if(mejor > xx*cx + yy*cy){
        bestx = xx;  besty = yy;
    }
    //printf("sol (%lld * %lld) + (%lld * %lld) = %lld\n",a,xx,b,yy,c);

    printf("%lld %lld\n", bestx, besty);
}

int main(){
    //freopen("salida.txt", "w", stdout);
    long long int a,b,c,x,y,d, aux,c1,c2;

    while(scanf("%lld", &c), c){
        scanf("%lld %lld", &cx, &a);
        scanf("%lld %lld", &cy, &b);

        solve(a,b,c);
        //printf("%d <= n <= %d\n",men, may);
    }
}


