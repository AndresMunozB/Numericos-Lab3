#include "ht.h"

/**
 * @brief Crea la matriz A, a partir de la formula: T[i+1]*(n+1) - T[i](2n+1) + T[i-1]n = -(G0 * (dr^2) * n )/k
 * @param p Cantidad de puntos que estarán dentro de la longitud del radio.
 * @return Una nueva matriz cuadrada A, de pxp.
 */
mat HT::newA(double p){
	// p -> Cantidad de puntos. p=n+1
	// n -> Cantidad de intervalos. n=p-1
	double n = p-1; 
	mat  A = zeros<mat>(p,p);
	A(0,0) = -1;
	A(0,1) = 1;
	A(n,n-1) = n;
	A(n,n) = -((2*(n))+1);

	for(int i = 1; i<n;i++ ){
		A(i,i-1) = i;
		A(i,i) = -((2*i)+1);
		A(i,i+1) = i+1;
	}
	return A;
}

/**
 * @brief Crea la matriz B que forma parte del sistema de ecuacion de transferenicia de calor
 * @param p  Cantidad de puntos que estarán dentro de la longitud del radio.
 * @param c  Constante de difusión de calor en el cuerpo
 * @param te Temperatura en la capa exterior.
 * @param dr Diferencial de radio, es decir, cuanta distancia hay entre un punto y otro dentro del radio.
 * @return Una nueva matriz B de px1
 */
mat HT::newB(double p, double c,double te,double dr){
	// p -> Cantidad de puntos. p=n+1
	// n -> Cantidad de intervalos. n=p-1
	// c -> Constante de difusión del material.
	// dr-> Diferencial de radio. 
	double n = p -1; 
	mat  B = zeros<mat>(p,1);
	double A = c*pow(dr,2);
	B(0,0) = (A/2.0);
	B(n,0) = ((n*A) - ((n+1)*te)); 
	for(int i = 1; i< n;i++){
		B(i,0) = i*A;
	}
	return B;
}
/**
 * @brief Muestra por consula los valores de la matriz A
 * @param a  Matriz que se mostrará
 * @param p  Dimensión de la matriz.
 */
void HT::showA(mat a,double p){
	for (int i = 0; i< p; i++){
		for (int j = 0; j< p; j++){
			cout  << a(i,j) << ", ";
		}
		cout << endl;
	}
}

/**
 * @brief Muestra por consula los valores de la matriz B o X
 * @param y  Matriz que se mostrará
 * @param p  Cantidad de filas que tiene la matriz.
 */
void HT::showBoX(mat y, double p){
	for (int i = 0; i< p; i++){
		cout << y(i,0) << endl;
	}
}

/**
 * @brief Guarda los resultados en un archivo llamado "nameFile", formato: punto valorTemperatura
 * @param nameFile  Nombre del archivo
 * @param X Matriz que contiene los resultados de la ecuacion de transferencia de calor.
 * @param dr Distancia entre los puntos.
 * @param n  Cantidad de intervalos. 
 */
void HT::save(string nameFile,mat X, double dr, double n){
	ofstream output;
	output.open(nameFile,ios::out);
	for(int i = 0; i<=n; i++){
		output<<dr*i<<" "<<X(i,0)<<endl;
	}
	output.close();
}


