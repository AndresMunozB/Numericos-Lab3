#ifndef HT_H
#define HT_H

#include <armadillo>
using namespace arma;
using namespace std;

//Heat Transfer
class HT
{
	public:
		
		mat newA(double p);
		mat newB(double p, double c,double te,double dr);
		void showA(mat a,double p);
		void showBoX(mat y, double p);
		void save(string nameFile,mat X, double dr, double n);


};

#endif