#ifndef __forward_pass_hpp__
#define __forward_pass_hpp__

#include <iostream>
#include <cmath>
#include <functional>
#include <numeric>
#include "globals.hpp"
#include "FFT.hpp"

// note, image upscaling should be done in MATLAB to prescale the images
// to the correct size

void forward_pass (float image[Nx][Ny],
		           float kernel[Nx][Ny],
				   float propagation_real[Nx][Ny],
				   float propagation_imag[Nx][Ny],
				   float *loss,
				   int *prediction,
				   float real_m[Nx][Ny],
				   float imag_m[Nx][Ny],
				   float real_mc[Nx][Ny],
				   float imag_mc[Nx][Ny]);

#endif
