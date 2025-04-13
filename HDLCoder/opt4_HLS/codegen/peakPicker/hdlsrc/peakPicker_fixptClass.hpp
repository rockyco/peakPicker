// -------------------------------------------------------------
//
// File Name: /home/jielei/Projects/UTS/peakPicker/HDLCoder/optim2/codegen/peakPicker/hdlsrc/peakPicker_fixptClass.hpp
// Created: 2025-03-31 21:52:07
//
// -- Generated by MATLAB 24.2, MATLAB Coder 24.2 and HDL Coder 24.2
// --
//
// -------------------------------------------------------------
#pragma once

#include "rtwtypes.hpp"

class peakPicker_fixptClass
{
 public:
  ap_ufixed<14,-7> xcorrBuffer[11];
  ap_ufixed<14,-7> thresholdBuffer[11];
  ap_uint<13> index;
  peakPicker_fixptClass()
  {
    peakPicker_fixpt_initialize();
  }

  void peakPicker_fixpt_initialize()
  {
   L1:
    for (int32_T t_0 = 0; t_0 < 11; t_0 = t_0 + 1) {
      xcorrBuffer[t_0] = 0.0;
    }

   L2:
    for (int32_T t_1 = 0; t_1 < 11; t_1 = t_1 + 1) {
      thresholdBuffer[t_1] = 0.0;
    }

    index = 1;
  }

  void peakPicker_fixpt(ap_ufixed<14,-7> xcorr, ap_ufixed<14,-7> threshold,
                        ap_uint<13> &locations, boolean_T &valid)
  {
    ap_ufixed<14,-7> t_0_0[10];
    ap_ufixed<14,-7> t_1_0[10];

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*                                                                           % */
    /*           Generated by MATLAB 24.2 and Fixed-Point Designer 24.2          % */
    /*                                                                           % */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*  Modified from the original peakPicker.m file */
    /*  to use a hardware-friendly implementation of peak finder */
    /*  This function is used to find the locations of peaks in a cross-correlation */
    /*  signal. It takes the cross-correlation signal, a threshold, and a window */
    /*  length as inputs, and returns the locations of the detected peaks. */
    /*  The function uses a sliding window approach to check for local maxima */
    /*  within the specified window length. The middle sample of the window is */
    /*  compared to the other samples in the window, and if it is greater than */
    /*  the threshold, it is considered a peak. The function also ensures that */
    /*  the detected peaks are within the specified window length. */
    /*  The function is designed to be hardware-friendly, meaning it is optimized */
    /*  for implementation on hardware platforms such as FPGAs or ASICs. It uses */
    /*  a simple and efficient algorithm to find the peaks, avoiding complex */
    /*  operations that may not be suitable for hardware implementation. */
    /*  The function is written in MATLAB and can be used in various applications */
    /*  such as signal processing, communications, and data analysis. */
    /*  */
    /*  The function takes the following inputs: */
    /*  - xcorr: The cross-correlation signal, which is a matrix of size */
    /*    (num_samples, num_sequences). Each column represents a different */
    /*    sequence. */
    /*  - threshold: The threshold value for peak detection, which is a vector */
    /*    of size (num_samples, 1). The threshold is used to determine if a */
    /*    sample is considered a peak. */
    /*  - window_length: The length of the sliding window used for peak */
    /*    detection. It is a scalar value that specifies the number of samples */
    /*    to consider in the window. */
    /*  */
    /*  The function returns the following output: */
    /*  - locations: A vector containing the indices of the detected peaks in */
    /*    the cross-correlation signal. The indices are relative to the input */
    /*    signal and indicate the locations of the detected peaks. */
    /*  */
    /*  Author: Jie Lei */
    /*  Date: 03/31/2025 */
    /*  University of Technology Sydney */
    /*  Copyright 2021-2023 The MathWorks, Inc. */
    /*  Length of the sliding window */
    /*  Persistent buffer for current window */
    /*  Persistent buffer for threshold */
    /*  Persistent index for the loop */
   L3:
    for (int32_T t_2 = 0; t_2 < 10; t_2 = t_2 + 1) {
      t_0_0[t_2] = xcorrBuffer[t_2];
    }

    /*  Shift buffer */
    xcorrBuffer[0] = xcorr;

    /*  Add new sample to buffer */
   L4:
    for (int32_T t_3 = 0; t_3 < 10; t_3 = t_3 + 1) {
      xcorrBuffer[1 + t_3] = t_0_0[t_3];
      t_1_0[t_3] = thresholdBuffer[t_3];
    }

   L5:
    for (int32_T t_4 = 0; t_4 < 10; t_4 = t_4 + 1) {
      thresholdBuffer[1 + t_4] = t_1_0[t_4];
    }

    /*  Shift threshold buffer */
    thresholdBuffer[0] = threshold;

    /*  Add new threshold to buffer */
    if (index >= 11) {
      boolean_T y;
      ap_uint<14> sub_temp;
      sub_temp = index - 5;
      locations = (ap_uint<13>)sub_temp;

      /*  Hardware friendly implementation of peak finder */
      /*  this is a vector */
      /*  if all values in the result are negative and the middle sample is */
      /*  greater than a threshold, it is a local max */
      y = true;
     L6:
      for (int32_T k = 0; k < 11; k = k + 1) {
        y = (y && ((ap_fixed<14,-6>)((ap_fixed<17,-4>)xcorrBuffer[k] - (ap_fixed<
                17,-4>)xcorrBuffer[5]) <= (ap_fixed<22,2>)0.0));
      }

      if (y && (xcorrBuffer[5] > thresholdBuffer[5])) {
        /*  Store the location of the peak */
        valid = true;

        /*  Set valid to true if a peak is found */
      } else {
        locations = 0;

        /*  No peak found */
        valid = false;

        /*  Set valid to false if no peak is found */
      }
    } else {
      locations = 0;

      /*  No peak found */
      valid = false;

      /*  Set valid to false if no peak is found */
    }

    index = (ap_uint<13>)(index + 1);

    /*  Increment index for the next iteration */
  }
};

extern void peakPicker_fixpt_wrapper(ap_ufixed<14,-7> xcorr, ap_ufixed<14,-7>
  threshold, ap_uint<13> &locations, boolean_T &valid);
