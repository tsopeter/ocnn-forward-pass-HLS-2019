############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project cnn_4_forward_pass
set_top forward_pass
add_files cnn_4_forward_pass/FFT.cpp
add_files cnn_4_forward_pass/FFT.hpp
add_files cnn_4_forward_pass/forward_pass.cpp
add_files cnn_4_forward_pass/forward_pass.hpp
add_files cnn_4_forward_pass/globals.hpp
open_solution "solution1"
set_part {xczu28dr-ffvg1517-2-e} -tool vivado
create_clock -period 10 -name default
#source "./cnn_4_forward_pass/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
