/*
 * function.cpp
 *
 *  Created on: 18.07.2014
 *      Author: Андраник
 */
#include <iostream>
#include "function.h"
#include <math.h>
double fun(double* x){
	//return 8 * x[0] * x[0] + 4 * x[0] * x[1] + 5 * x[1] * x[1];
	return  x[1] * x[1] + cos(x[0] + 1.23 * x[1]);
}
double* huk(double* x, double* h, double epsilon, double step_decrease, int n){
	double *x1 = new double[n];
	double *x2 = new double[n];
	double *x3 = new double[n];
	int i = 0, iter = 0;
	double fun1 = 0, fun2 = 0, fun_start = 0, fun_start1 = 0, x_fix = 0, step = 0.5;
	do{
		iter++;
		printf("%5lf %5lf %5lf %5d\n", fun(x), x[0], x[1], iter);
		for(i = 0; i < n; i++){
			fun_start = fun(x);
			x1[i] = x[i];
			x_fix = x[i];
			x[i] += h[i];
			fun1 = fun(x);
			x[i] = x_fix;
			x[i] -= h[i];
			fun2 = fun(x);
			x[i] = x_fix;
			if(fun1 < fun_start)
				x[i] += h[i];
			if(fun2 < fun_start)
				x[i] -= h[i];
			fun1 = fun(x);
			if(fun_start <= fun1)
				h[i] /= step_decrease;
		}
		printf("%5lf %5lf %5lf\n", fun(x), x[0], x[1]);
		for(i = 0; i < n; i++)
			x2[i] = x[i];
		fun_start = fun(x2);
		for( ; ;){
			x3[0] = x1[0] + 2 * (x2[0] - x1[0]);
			x3[1] = x1[1] + 2 * (x2[1] - x1[1]);
			fun_start1 = fun(x3);
			printf("obr : %5lf %5lf %5lf\n", fun(x3), x3[0], x3[1]);
			for(i = 0; i < n; i++){
				x_fix = x3[i];
				x3[i] += step;
				fun1 = fun(x3);
				x3[i] = x_fix;
				x3[i] -= step;
				fun2 = fun(x3);
				x3[i] = x_fix;
				if(fun1 < fun_start1)
					x3[i] += step;
				if(fun2 < fun_start1)
					x3[i] -= step;
				fun2 = fun(x3);
				if(fun2 < fun_start){
					for(i = 0; i < n; i++){
						x1[i] = x2[i];
						x2[i] = x3[i];
					}
					fun_start = fun(x3);
				}
				else{
					for(i = 0; i < n; i++)
						x[i] = x2[i];
				}
			}
			if(fun2 >= fun_start)
				break;
		}
		printf("%5lf %5lf %5lf\n", fun(x3), x3[0], x3[1]);
	}while((h[0] > epsilon) && (h[1] > epsilon));
	delete []x1;
	delete []x2;
	delete []x3;
	return x;
}
