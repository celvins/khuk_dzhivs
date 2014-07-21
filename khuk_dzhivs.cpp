//============================================================================
// Name        : khuk_dzhivs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "function.h"
using namespace std;
int main() {
	/*
	 * Входные данные из файла:
	 * n - количество неизвестных, epsilon - точность, step_decrease - уменьшение шага
	 * x[i] h[i] - начальные значения точки и соответствующего шага
	 *
	 */
	FILE *file;
	file = fopen("config.txt", "r");
	int n = 0, i = 0;
	double epsilon = 0, step_decrease = 0;
	fscanf(file, "%d %lf %lf", &n, &epsilon, &step_decrease);
	double *x = new double[n];
	double *h = new double[n];
	for(i = 0; i < n; i++)
		fscanf(file, "%lf %lf", &x[i], &h[i]);
	x = huk(x, h, epsilon, step_decrease, n);
	printf("\n%5lf", fun(x));
	fclose(file);
	delete []h;
	delete []x;
	return EXIT_SUCCESS;
}
