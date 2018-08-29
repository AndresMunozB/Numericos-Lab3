/**
 * \mainpage Integración.
 * \author Andrés Muñoz Bravo
 * \date 29-Agosto-2018
 */

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

/**
 * @brief Valida las entradas para el programa (Se puede mejorar o tambien utilizar getopt).
 * @param argc Cantidad de datos que recibe el progama.
 * @param argv Arreglo de string que recibe al programa.

 */
int validateInputs(int argc, char *argv[]){
    if(argc < 4){
        cout << "Formato: ./main a b e" << endl;
        cout << "   - a : VALOR INFERIOR"  << endl;
        cout << "   - b : VALOR SUPERIOR" << endl;
        cout << "   - e : TOLERANCIA" << endl;
        cout << "Ejemplo: ./main 0.0 10.0 0.0001 " << endl;
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{   
    if(!validateInputs(argc,argv)){
        return 0;
    }
    long double a = stod(argv[1]);
    long double b = stod(argv[2]);
    long double e = stod(argv[3]);
    long double valIT = IT(a,b,e);
    long double valS13 = IS13(a,b,e);
    long double valS38 = IS38(a,b,e);
    cout << "itIT : " << itIT  << ", valor: " << valIT  << endl;
    cout << "itS13: " << itS13 << ", valor: " << valS13 <<  endl;
    cout << "itS38: " << itS38 << ", valor: " << valS38 << endl;
    return 1;

}
