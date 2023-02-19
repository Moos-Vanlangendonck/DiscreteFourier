/*-----------------------------------
 Author: Moos Vanlangendonck
 Project: Visualization of a Discrete Fourier transformation in C++20
 Discrete Fourier: X_(k)=sum_(n=0)^(N-1)x_(n)exp^((-j2pi)/(N)kn)
 Simplyfied: [X_{k} = x_{n} \sum_{n=0}^{N - 1} 1\]
 Sources: https://en.wikipedia.org/wiki/Fourier_series | https://snip.mathpix.com/
---------s--------------------------*/

#include "main.h"

using namespace std;

std::vector<std::complex<double>> DiscreteFourier
(std::vector<std::complex<double>> x)
{
	int n = x.size();
	int k = n;

	std::complex<double> som;
	std::vector<std::complex<double>> out;

	out.reserve(k);

	for (int i = 0; i < k; ++i)
	{
		som = std::complex<double>(0, 0);

		for (int j = 0; j < n; ++j)
		{
			double _cos = cos(((2 * std::numbers::pi) / n) * k * j);
			double _sin = sin(((2 * std::numbers::pi) / n) * k * j);

			std::complex<double> r(_cos, -_sin);

			som += x[j] * r;
		}
		out.push_back(som);
	}
	return out;
}

int main
(int argc, char* argv)
{
	int n = 1000;
	std::vector<std::complex<double>> sn;
	sn.reserve(n);

	double sk = 3.0;
	double fase = std::numbers::pi / 4.0;

	for (int i = 0; i < n; ++i)
	{
		auto c = std::complex<double>
			(cos((2 * std::numbers::pi / static_cast<double>(n)) * sk * static_cast<double>(i) + fase), 0.0);

		sn.push_back(c);
	}

	std::vector<std::complex<double>> fx = DiscreteFourier(sn);

	std::cout << "k\t" << std::setw(12) << "r\t" << std::setw(12) << "i" << std::endl;

	for (int j = 0; j < 6; ++j)
	{
		// Set output to non-scientific mode (fixed) & set precision to 17 places after the comma
		// std::cout << std::fixed << std::setprecision(17);
		std::cout << j << "\t"
			<< std::setw(12) << (fx[j].real() / static_cast<double>(n)) << "\t"
			<< std::setw(12) << (fx[j].imag() / static_cast<double>(n)) << std::endl;
	}

	return (0);
}