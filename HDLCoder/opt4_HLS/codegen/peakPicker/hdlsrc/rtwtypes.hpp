// -------------------------------------------------------------
//
// File Name: /home/jielei/Projects/UTS/peakPicker/HDLCoder/optim2/codegen/peakPicker/hdlsrc/rtwtypes.hpp
// Created: 2025-03-31 21:52:07
//
// -- Generated by MATLAB 24.2, MATLAB Coder 24.2 and HDL Coder 24.2
// --
//
// -------------------------------------------------------------
#pragma once

#ifndef SC_INCLUDE_FX
#define SC_INCLUDE_FX
#endif

#include <ap_int.h>
#include <ap_fixed.h>

typedef bool logical;
typedef bool boolean_T;
typedef char char_T;
typedef ap_int<8> int8_T;
typedef ap_uint<8> uint8_T;
typedef ap_int<16> int16_T;
typedef ap_uint<16> uint16_T;
typedef ap_int<32> int32_T;
typedef ap_uint<32> uint32_T;
typedef ap_int<64> int64_T;
typedef ap_uint<64> uint64_T;
typedef float real32_T;
typedef double real_T;

#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255))
#define MIN_uint8_T                    ((uint8_T)(0))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535))
#define MIN_uint16_T                   ((uint16_T)(0))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))
#define MIN_uint32_T                   ((uint32_T)(0))
#define MAX_int64_T                    ((int64_T)(9223372036854775807LL))
#define MIN_int64_T                    ((int64_T)(-9223372036854775807LL-1LL))
#define MAX_uint64_T                   ((uint64_T)(0xFFFFFFFFFFFFFFFFULL))
#define MIN_uint64_T                   ((uint64_T)(0))

template<typename T, typename T1>
  inline void slice_get(T in,uint16_T b,uint16_T c,T1 &out)
{
  out = in.range(b,c);
}

template<typename T1, typename T2, typename Tout>
  inline void bit_concat(T1 in1,T2 in2,int in1_wl,int in2_wl,Tout &out)
{
  out.range(in1_wl + in2_wl - 1,in2_wl) = in1.range(in1_wl-1,0);
  out.range(in2_wl-1,0) = in2.range(in2_wl-1,0);
}

template<typename T>
  inline ap_uint<1> and_reduce(T a,uint16_T b,uint16_T c)
{
  auto temp = a.range(b,c);
  return temp.and_reduce();
}

template<typename T>
  inline ap_uint<1> or_reduce(T a,uint16_T b,uint16_T c)
{
  auto temp = a.range(b,c);
  return temp.or_reduce();
}

template<typename T>
  inline ap_uint<1> xor_reduce(T a,uint16_T b,uint16_T c)
{
  auto temp = a.range(b,c);
  return temp.xor_reduce();
}
