#include "math.hpp"
#include <iostream>

namespace astd {
	double power(double num1, double num2) {
		double powerResult{ num1 };

		for (int i{ 0 }; i < num2; i += 2) {
			powerResult = num1 * powerResult;
		}

		return powerResult;
	}

	int power(int num1, int num2) {
		int powerResult{ num1 };

		for (int i{ 0 }; i < num2; i += 2) {
			powerResult = num1 * powerResult;
		}

		return powerResult;
	}

	int square(int num) {
		return num * num;
	}

	double square(double num) {
		return num * num;
	}
}
