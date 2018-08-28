#include "edo.h"

#include <armadillo>

using namespace arma;
using namespace std;

mat createMatrizA(int p){
mat createMatrizB(int p, double c,double te){
	// p -> Cantidad de puntos. p=n+1
	// n -> Cantidad de intervalos. n=p-1
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
	// p -> Cantidad de puntos. p=n+1
	// n -> Cantidad de intervalos. n=p-1
	// c -> Constante de difusión del material.
	int n = p -1; 
	mat  b = zeros<mat>(p,1);

	b(0,0) = (c/2.0);
	b(n,0) = ((n*c) - ((n+1)*te)); 
	for(int i = 1; i< n;i++){
		b(i,0) = i*c;
	}
	return b;
}
void showMatrizA(mat a,int p){
	for (int i = 0; i< p; i++){
		for (int j = 0; j< p; j++){
			cout  << a(i,j) << ", ";
		}
		cout << endl;
	}
}
void showMatrizBorX(mat y, int p){
	for (int i = 0; i< p; i++){
		cout << y(i,0) << endl;
	}
}
int main(){
	
	int p = 5; 			// Cantidad de puntos.
	int n = p-1; 		// Cantidad de intervalos.
	int c = -2; 		// Constante de difusión del material.
	double te = 50.0; 	// Temperatura en la capa exterior.
	//double R = 10; 	//Radio del cilindro.
	//double dr = R/n; 	// Diferencial de radio.


	mat A = createMatrizA(p);
	mat B = createMatrizB(p,c,te);
	mat X = solve(A,B);

	/*showMatrizA(A,p);
	showMatrizBorX(B,p);
	showMatrizBorX(X,p);*/
	
}