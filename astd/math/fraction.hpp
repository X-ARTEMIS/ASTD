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

	fraction& operator-=(fraction& fraction2) {
		if (!(this->denominator == fraction2.denominator)) {
			double lcm = std::lcm(this->denominator, fraction2.denominator);

			this->numerator = (lcm / this->denominator) * this->numerator -
				(lcm / fraction2.denominator) * fraction2.numerator;
			this->denominator = lcm;
		}

		else {
			this->numerator -= fraction2.numerator;
		}

		return *this;
	}

	fraction& operator*=(fraction& fraction2) {
		if (!(this->denominator == fraction2.denominator)) {
			double lcm = std::lcm(this->denominator, fraction2.denominator);

			this->numerator = (lcm / this->denominator) * this->numerator *
				(lcm / fraction2.denominator) * fraction2.numerator;
			this->denominator = lcm;
		}

		else {
			this->numerator *= fraction2.numerator;
		}

		return *this;
	}

	fraction& operator/=(fraction& fraction2) {
		if (!(this->denominator == fraction2.denominator)) {
			double lcm = std::lcm(this->denominator, fraction2.denominator);

			this->numerator = (lcm / this->denominator) * this->numerator /
				(lcm / fraction2.denominator) * fraction2.numerator;
			this->denominator = lcm;
		}

		else {
			this->numerator /= fraction2.numerator;
		}

		return *this;
	}
};

template<typename A, typename B, typename C, typename D, typename E, typename F> // I doubt this is necessary
fraction<A, B>& operator+(fraction<C, D>& frac, fraction<E, F> frac2) {
	return frac += frac2;
}

template <typename G, typename H, typename I, typename J, typename K, typename L>
fraction<G, H>& operator-(fraction<I, J>& frac, fraction<K, L> frac2) {
	return frac -= frac2;
}

template<typename M, typename N, typename O, typename P, typename Q, typename R>
fraction<M, N>& operator*(fraction<O, P> frac, fraction<Q, R> frac2) {
	return frac *= frac2;
}

template<typename S, typename V>
std::ostream& operator<<(std::ostream& out, fraction<S, V> frac) {
	out << frac.numerator << '/' << frac.denominator;
	return out;
}
