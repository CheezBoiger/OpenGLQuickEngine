//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include <cstdint>
#include <cmath>


namespace math {


typedef float real32;
typedef double real64;
typedef int32_t int32;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef int16_t int16_t;
typedef int8_t int8;
typedef uint8_t uint8;
typedef int8 bool8;



inline double Sqrt(double value)
{
  return std::sqrt(value);
}


template<typename T>
inline bool IsNaN(T value)
{
  return std::isnan(value);
}

// Standard absolute value wrap.
template<typename T>
inline T Abs(T value)
{
  return std::abs(value);
}


inline double Cos(double value)
{
  return std::cos(value);
}


inline double Sin(double value)
{
  return std::sin(value);
}

inline double Tan(double value)
{
  return std::tan(value);
}

inline float Cosf(float value)
{
  return std::cosf(value);
}

inline float Sinf(float value)
{
  return std::sinf(value);
}

inline float Tanf(float value)
{
  return std::tanf(value);
}
} // jkl