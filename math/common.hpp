//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include <cstdint>
#include <cmath>

#define J_PI 3.141592653589793238462643383279502884197169399375


namespace math {

typedef float real32;
typedef double real64;
typedef int32_t int32;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef int16_t int16;
typedef uint8_t uint8;
typedef int8_t int8;
typedef uint64_t uint64;
typedef int64_t int64; 

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


inline float ToRadians(float degrees)
{
  return degrees * (static_cast<float>(J_PI) / 180.0f);
}
} // jkl