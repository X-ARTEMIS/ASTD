#include <iostream>
#include <numeric>

template<typename T, typename U>
class fraction {
public:
	T numerator{};
	U denominator{};

	fraction(T numerator, U denominator) : numerator{ numerator }, denominator{ denominator } { if (denominator == 0) { throw std::exception("Undefined fraction"); } }

	double fractionToDecimal() {
		return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
	}

	fraction& operator+=(fraction& fraction2) {
		if (!(this->denominator == fraction2.denominator)) { 
			double lcm = std::lcm(this->denominator, fraction2.denominator);

			this->numerator = (lcm / this->denominator) * this->numerator +
				(lcm / fraction2.denominator) * fraction2.numerator;
			this->denominator = lcm;
		}

		else {
			this->numerator += fraction2.numerator;
		}

		return *this;
	}
};

template<typename T, typename U>
fraction<T, U>& operator+(fraction<T, U>& frac, fraction<T, U> frac2) {
	return frac += frac2;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& out, fraction<T, U> frac) {
	out << frac.numerator << '/' << frac.denominator;
	return out;
}
