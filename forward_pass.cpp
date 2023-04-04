#include "forward_pass.hpp"

void forward_pass (float image[Nx][Ny],
		           float kernel[Nx][Ny],
				   float propagation_real[Nx][Ny],
				   float propagation_imag[Nx][Ny],
				   float *loss,
				   int *prediction,
				   float real_m[Nx][Ny],
				   float imag_m[Nx][Ny],
				   float real_mc[Nx][Ny],
				   float imag_mc[Nx][Ny]) {


	// compute hadamard product with kernel and compute sigmoid function to emulate
	// DLP 1-bit
	float real_fp1[Nx][Ny];
	float imag_fp1[Nx][Ny];

	for (size_t i = 0; i < Nx; ++i)
		for (size_t j = 0; j < Ny; ++j) {
			real_fp1[i][j] = image[i][j] * kernel[i][j];
			real_fp1[i][j] = sigmoid(real_fp1[i][j], mm);
			imag_fp1[i][j] = 0;
		}


	// now compute the propagation via fft2
	float real_fp2[Nx][Ny];
	float imag_fp2[Nx][Ny];
	fft2(real_fp1, imag_fp1, real_fp2, imag_fp2, real_m, imag_m);

	// compute hadamard product between image and propagation
	fftshift(real_fp2, imag_fp2);
	for (size_t i = 0; i < Nx; ++i)
		for (size_t j = 0; j < Ny; ++j) {
			real_fp2[i][j]=real_fp2[i][j] * propagation_real[i][j] - imag_fp2[i][j] * propagation_imag[i][j];
			imag_fp2[i][j]=real_fp2[i][j] * propagation_imag[i][j] + imag_fp2[i][j] * propagation_real[i][j];
		}


}
