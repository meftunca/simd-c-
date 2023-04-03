#pragma once
#include <eve/module/core.hpp>
#include <eve/module/math.hpp>
#include <eve/wide.hpp>

#include <cmath>

inline eve::wide<float>
eve_rho(eve::wide<float> x, eve::wide<float> y)
{
  return eve::sqrt(x * x + y * y);
}

inline eve::wide<float>
eve_theta(eve::wide<float> x, eve::wide<float> y)
{
  return eve::atan2(y, x);
}
inline float
rho(float x, float y)
{
  return std::sqrt(x * x + y * y);
}

inline float
theta(float x, float y)
{
  return std::atan2(y, x);
}