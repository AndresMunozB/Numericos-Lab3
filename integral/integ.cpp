#include "integ.h"

#include <iostream>
#include <math.h>



using namespace std;
//Variables globales
int itIT = 0;
int itS13 = 0;
int itS38 = 0;


long double fx(long double x){
    return pow(2,x)-2*x;
}

long double trapecio(long double a, long double b)
{
	return ((b-a) / 2 ) * ( fx(a) + fx(b) );
}

long double simpson13(long double a, long double b)
{
	return ((b-a) / 6 ) * ( fx(a) + (4 * fx ((a+b)/2)) + fx(b) );
}
long double simpson38(long double a, long double b){
    long double h = (b-a)/3;
    return ((b-a) / 8 ) * ( fx(a) + 3*(fx(a+h)  + fx( a+2*h))   + fx(b) );

}

long double IT(long double a, long double b, long double tol){
    itIT++;
    long double m = (a+b)/2;
    long double t1 = trapecio(a,b);
    long double t2 = trapecio(a,m);
    long double t3 = trapecio(m,b);
    long double e = 10*(t1-t2-t3);
    //cout << e << endl;
    if (e < tol){
        
        return t1;
    }
    else{
        return IT(a,m,tol) + IT(m,b,tol);
    }
}
long double IS13(long double a, long double b, long double tol){
    itS13++;
    long double m = (a+b)/2;
    long double t1 = simpson13(a,b);
    long double t2 = simpson13(a,m);
    long double t3 = simpson13(m,b);
    long double e = 10*(t1-t2-t3);
    if (e < tol){
        
        return t1;
    }
    else{
        return IS13(a,m,tol) + IS13(m,b,tol);
    }
}
long double IS38(long double a, long double b, long double tol){
    itS38++;
    long double m = (a+b)/2;
    long double t1 = simpson38(a,b);
    long double t2 = simpson38(a,m);
    long double t3 = simpson38(m,b);
    long double e = 10*(t1-t2-t3);
    if (e < tol){
        
        return t1;
    }
    else{
        return IS38(a,m,tol) + IS38(m,b,tol);
    }
}
int main(int argc, char *argv[])
{
    long double valIT = IT(0.0,1.0,0.0000001);
    long double valS13 = IS13(0.0,1.0,0.0000001);
    long double valS38 = IS38(0.0,1.0,0.0000001);
    cout << "itIT : " << itIT  << ", valor: " << valIT  << endl;
    cout << "itS13: " << itS13 << ", valor: " << valS13 <<  endl;
    cout << "itS38: " << itS38 << ", valor: " << valS38 << endl;

}
