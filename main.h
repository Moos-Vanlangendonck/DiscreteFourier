/*-----------------------------------
 Author: Moos Vanlangendonck
 Project: Visualization of a Discrete Fourier transformation in C++20
 Discrete Fourier: X_(k) = sum_(n=0)^(N-1)x_(n)exp^((-j2pi)/(N)kn)
 Simplyfied: [X_{k} = x_{n} \sum_{n=0}^{N - 1} 1\]
 Sources: https://en.wikipedia.org/wiki/Fourier_series | https://snip.mathpix.com/
-----------------------------------*/

#pragma once
#include <iostream>
#include <numbers>
#include <complex>
#include <vector>
#include <iomanip>
