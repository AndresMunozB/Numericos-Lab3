#include "edo.h"

#include <armadillo>

using namespace arma;
using namespace std;

mat createMatrizA(int p){
	// p -> cantidad de puntos, p=n+1
	// n -> numero de intervalos, n=p-1
	int n = p-1; 
	mat  a = zeros<mat>(p,p);
	a(0,0) = -1;
	a(0,1) = 1;
	a(n,n-1) = n;
	a(n,n) = -((2*(n))+1);

	for(int i = 1; i<n;i++ ){
		a(i,i-1) = i;
		a(i,i) = -((2*i)+1);
		a(i,i+1) = i+1;
	}
	return a;
}

mat createMatrizB(int p, double c,double te){
	// p -> cantidad de puntos, p=n+1
	// c -> constante de difusion del material.
	// n -> numero de intervalos
	int n = p -1; 
	mat  b = zeros<mat>(p,1);

	b(0,0) = (c/2.0);
	b(n,0) = ((n*c) - ((n+1)*te)); 
	for(int i = 1; i< n;i++){
		b(i,0) = i*c;
	}
	return b;
}
int main(){
	double R = 10;
	int p = 5; //Puntos dentro del intervalo
	int c = -2; //
	int n = p-1;
	double dr = R/n;
	double te = 50.0;
	mat a = createMatrizA(p);
	mat b = createMatrizB(p,c,te);
	mat x = solve(a,b);

	for (int i = 0; i< p; i++){
		cout << x(i,0) << endl;
	}
	for (int i = 0; i< p; i++){
		cout << b(i,0) << endl;
	}
	for (int i = 0; i< p; i++){
		for (int j = 0; j< p; j++){
			cout  << a(i,j) << ", ";
		}
		cout << endl;
	}
}