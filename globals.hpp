#ifndef __globals_hpp__
#define __globals_hpp__

#include <iostream>
#include <cmath>
#include <unistd.h>

#define Nx 512
#define Ny 512
#define nx 21.16e-3
#define ny 21.16e-3
#define d1 20e-2
#define d2 20e-2
#define wv 400e-9
#define r1 nx/6
#define r2 nx/30
#define rate 1
#define lvalue 1e-6
#define sx 2
#define sy 1
#define sc 0.45
#define sz 1/6;
#define P 1
#define mm 2*10e3
#define PI 3.1415926536

float sigmoid (float x, float m) {
	return 1 / (1+expf(-x * m));
}

struct cmplx {
	float first;
	float second;
};


#endif
