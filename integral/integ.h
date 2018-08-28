#ifndef INTEGRAL_H
#define INTEGRAL_H





class Integral
{
	public:
		Integral();
		long double fx(long double x);
		long double trapecio(long double a, long double b);
		long double simpson13(long double a, long double b);
        long double simpson38(long double a, long double b);
		long double IT(long double a, long double b, long double tol);
		long double IS13(long double a, long double b, long double tol);
		long double IS38(long double a, long double b, long double tol);

};

#endif