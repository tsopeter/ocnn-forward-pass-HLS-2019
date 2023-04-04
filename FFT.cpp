#include "FFT.hpp"

void fft (float real_x[Nx],
		  float imag_x[Nx],
		  float real_y[Nx],
		  float imag_y[Nx],
		  float real_m[Nx][Ny],
		  float imag_m[Nx][Ny]) {
	for (size_t k = 0; k < Nx; ++k) {
		float ra = 0, ia = 0;
		for (size_t n = 0; n < Nx; ++n) {
			ra += (real_m[k][n] * real_x[n] - imag_m[k][n] * imag_x[n]);
			ia += (real_m[k][n] * imag_x[n] + imag_m[k][n] * real_x[n]);
		}
		real_y[k]=ra;
		imag_y[k]=ia;
	}
}

void ifft (float real_x[Nx],
		   float imag_x[Nx],
		   float real_y[Nx],
		   float imag_y[Nx],
		   float real_m[Nx][Ny],
		   float imag_m[Nx][Ny]) {
	for (size_t n = 0; n < Nx; ++n) {
		float ra = 0, ia = 0;
		for (size_t k = 0; k < Nx; ++k) {
			ra += (real_m[k][n] * real_x[k] - imag_m[k][n] * imag_x[k]);
			ia += (real_m[k][n] * imag_x[k] + imag_m[k][n] * real_x[k]);
		}
		real_y[n]=ra;
		imag_y[n]=ia;
	}
}

void fft2 (float real_x[Nx][Ny],
		   float imag_x[Nx][Ny],
		   float real_y[Nx][Ny],
		   float imag_y[Nx][Ny],
		   float real_m[Nx][Ny],
		   float imag_m[Nx][Ny]) {
	float real_t1[Nx][Ny];
	float imag_t1[Nx][Ny];

	transpose2d(real_x, real_t1);
	transpose2d(imag_x, imag_t1);

	for (size_t i = 0; i < Nx; ++i) {
		fft(real_t1[i], imag_t1[i], real_y[i], imag_y[i], real_m, imag_m);
	}

	transpose2d(real_y, real_t1);
	transpose2d(imag_y, imag_t1);

	for (size_t i = 0; i < Nx; ++i) {
		fft(real_t1[i], imag_t1[i], real_y[i], imag_y[i], real_m, imag_m);
	}
}

void ifft2 (float real_x[Nx][Ny],
		    float imag_x[Nx][Ny],
		    float real_y[Nx][Ny],
		    float imag_y[Nx][Ny],
			float real_m[Nx][Ny],
			float imag_m[Nx][Ny]) {
	float real_t1[Nx][Ny];
	float imag_t1[Nx][Ny];

	transpose2d(real_x, real_t1);
	transpose2d(imag_x, imag_t1);

	for (size_t i = 0; i < Nx; ++i) {
		ifft(real_t1[i], imag_t1[i], real_y[i], imag_y[i], real_m, imag_m);
	}

	transpose2d(real_y, real_t1);
	transpose2d(imag_y, imag_t1);

	for (size_t i = 0; i < Nx; ++i) {
		ifft(real_t1[i], imag_t1[i], real_y[i], imag_y[i], real_m, imag_m);
	}
}

void create_fft_mat (float real_fy[Nx][Ny],
		              float imag_fy[Nx][Ny],
					  float real_iy[Nx][Ny],
					  float imag_iy[Nx][Ny]) {


	// compute values to compute fft
	for (size_t k = 0; k < Nx; ++k) {
		for (size_t n = 0; n < Ny; ++n) {
			cmplx a = wk(Nx, n, k, -1.0);
			cmplx b = wk(Nx, n, k,  1.0);
			real_fy[k][n] = a.first;
			imag_fy[k][n] = a.second;
			real_iy[k][n] = b.first;
			imag_iy[k][n] = b.second;
		}
	}
}

void transpose2d (float x[Nx][Ny],
		          float y[Ny][Nx]) {
	for (size_t i = 0; i < Nx; ++i)
		for (size_t j = 0; j < Ny; ++j)
			y[j][i] = x[i][j];
}

void implt_fftshift(float x[Nx][Ny]) {
	for (size_t i = 0; i < Nx; ++i) {
		for (size_t j = 0; j < Nx/2; ++j) {
			float temp = x[i][j];
			x[i][j]=x[i][j+Nx/2];
			x[i][j+Nx/2]=temp;
		}
	}
	for (size_t i = 0; i < Nx; ++i) {
		for (size_t j = 0; j < Nx/2; ++j) {
			float temp = x[j][i];
			x[j][i]=x[j+Nx/2][i];
			x[j+Nx/2][i]=temp;
		}
	}
}

void fftshift (float real_x[Nx][Ny],
		       float imag_x[Nx][Ny]) {
	implt_fftshift(real_x);
	implt_fftshift(imag_x);
}
