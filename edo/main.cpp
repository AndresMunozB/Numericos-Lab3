#include "ht.h"
	

int validateInputs(int argc, char *argv[]){
	if(argc < 6){
		cout << "ht 5 -50 50 1 nameFile" << endl;
		return 0;
	}

	return 1;
}
/*
INPUTS:
p -> CANTIDAD DE PUNTOS
c -> CONSTANTE DE DIFUSIÓN
te-> TEMPERATURA EN LA CAPA EXTERNA
R -> RADIO DEL CILINDRO.
*/
int main(int argc, char *argv[]){
	
	// La cantidad de memoria utilizada para ejecutar el programa es aproximandamente:
	// (p^2)*8 bytes -> los 8 bytes corresponden a la memoria requerida par aun dato double
	// Es por esto que se necesita esta cantidad de memoria ya que armadillo, utiliza datos double
	// en sus matrices.
	// Entrada : p,c,te,R
	if(!validateInputs(argc,argv)){
		return 0;
	}
	double p =stod(argv[1]); 		// Cantidad de puntos.
	double n = p-1; 	// Cantidad de intervalos.
	double c = stod(argv[2]); 	// Constante de difusión del material.
	double te = stod(argv[3]); 	// Temperatura en la capa exterior.
	double R = stod(argv[4]); 		// Radio del cilindro.
	double dr = R/n; 	// Diferencial de radio.

	HT ht = HT();
	mat A = ht.newA(p);
	mat B = ht.newB(p,c,te,dr);
	mat X = solve(A,B);
	
	/*ht.showA(A,p);
	ht.showBoX(B,p);
	ht.showBoX(X,p);*/
	ht.save(argv[5],X,dr,n);

	return 1;
	
}	