/*
 * function.cpp
 *
 *  Created on: 18.07.2014
 *      Author: Àíäðàíèê
 */
#include <iostream>
#include "function.h"
#include <math.h>
double fun(double* x){
	//return 8 * x[0] * x[0] + 4 * x[0] * x[1] + 5 * x[1] * x[1];
	return  x[1] * x[1] + cos(x[0] + 1.23 * x[1]);
}
double* huk(double* x, double* h, double epsilon, double step_decrease, int n){
	int i = 0;
	double fun1 = 0, fun2 = 0, fun_start = 0, x1 = 0;
	do{
		for(i = 0; i < n; i++){
			printf("%5lf %5lf %5lf\n", fun(x), x[0], x[1]);
			fun_start = fun(x);
			x1 = x[i];
			x[i] += h[i];
			fun1 = fun(x);
			x[i] = x1;
			x[i] -= h[i];
			fun2 = fun(x);
			x[i] = x1;
			if(fun1 < fun2)
				x[i] += h[i];
			else
				x[i] -= h[i];
			fun1 = fun(x);
			if(fun_start < fun1)
				h[i] /= step_decrease;
		}
	}while((h[0] > epsilon) && (h[1] > epsilon));
	return x;
}
