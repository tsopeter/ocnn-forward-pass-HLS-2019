#ifndef __FFT_hpp__
#define __FFT_hpp__

#include <iostream>
#include <cmath>
#include <functional>
#include "globals.hpp"

void fft (float real_x[Nx],
		  float imag_x[Nx],
		  float real_y[Nx],
		  float imag_y[Nx],
		  float real_m[Nx][Ny],
		  float imag_m[Nx][Ny]);

void ifft (float real_x[Nx],
		   float imag_x[Nx],
		   float real_y[Nx],
		   float imag_y[Nx],
		   float real_m[Nx][Ny],
		   float imag_m[Nx][Ny]);

void fft2 (float real_x[Nx][Ny],
		   float imag_x[Nx][Ny],
		   float real_y[Nx][Ny],
		   float imag_y[Nx][Ny],
		   float real_m[Nx][Ny],
		   float imag_m[Nx][Ny]);

void ifft2 (float real_x[Nx][Ny],
		    float imag_x[Nx][Ny],
		    float real_y[Nx][Ny],
		    float imag_y[Nx][Ny],
			float real_m[Nx][Ny],
			float imag_m[Nx][Ny]);

void fftshift (float real_x[Nx][Ny],
		       float imag_x[Nx][Ny]);

void implt_fftshift(float x[Nx][Ny],
		            float y[Nx][Ny]);

void transpose2d (float x[Nx][Ny]);

void create_fft_mat (float real_fy[Nx][Ny],
		              float imag_fy[Nx][Ny],
					  float real_iy[Nx][Ny],
					  float imag_iy[Nx][Ny]);

cmplx wk (int N, float n, float k, float c) {
	float arg = 2.0 * PI * n * k / static_cast<float>(N);
	float real = cos(arg);
	float imag = sin(arg);
	return {real, imag};
}

#endif
