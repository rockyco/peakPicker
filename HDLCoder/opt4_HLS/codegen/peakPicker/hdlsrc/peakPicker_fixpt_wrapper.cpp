// -------------------------------------------------------------
//
// File Name: /home/jielei/Projects/UTS/peakPicker/HDLCoder/optim2/codegen/peakPicker/hdlsrc/peakPicker_fixpt_wrapper.cpp
// Created: 2025-03-31 21:52:07
//
// -- Generated by MATLAB 24.2, MATLAB Coder 24.2 and HDL Coder 24.2
// --
//
// -------------------------------------------------------------
#include "peakPicker_fixptClass.hpp"

peakPicker_fixptClass inst;
void peakPicker_fixpt_wrapper(ap_ufixed<14,-7> xcorr, ap_ufixed<14,-7> threshold,
  ap_uint<13> &locations, boolean_T &valid)
{
#pragma HLS PIPELINE II=1
  inst.peakPicker_fixpt(xcorr, threshold, locations, valid);
}
