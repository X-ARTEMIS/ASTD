#include <iostream>

template<typename T, typename U>
class fraction {
public:
	T numerator{};
	U denominator{};

	fraction(T numerator, U denominator) : numerator{ numerator }, denominator{ denominator } {}

	double fractionToDecimal() {
		return static_cast<double>(this.numerator) / static_cast<double>(this.denominator);
	}
};

template<typename T, typename U>
std::ostream& operator<<(std::ostream& out, fraction<T, U> frac) {
	out << frac.numerator << "/" << frac.denominator;
	return out;
}
