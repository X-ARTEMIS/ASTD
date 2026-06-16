#include <ostream> 
#include <numeric>

template<typename T, typename U>
class fraction {
private:
	T m_numerator{};
	U m_denominator{ 1 };

public:
	fraction(T numerator, U denominator) : m_numerator{ numerator }, m_denominator{ denominator } { if (denominator == 0) { throw std::exception("Undefined fraction"); } }

	double fractionToDecimal() {
		return static_cast<double>(this->m_numerator) / static_cast<double>(this->m_denominator);
	}

	T getNumerator() const {
		return m_numerator;
	}

	U getDenominator() const {
		return m_denominator;
	}

	T setNumerator(auto value) {
		m_numerator = value;
		return m_numerator;
	}

	U setDenominator(auto value) {
		if (value == 0) {
			throw std::exception("Undefined fraction");
		}

		else {
			m_denominator = value;
		}
		return m_denominator;
	}

	fraction& operator+=(fraction& fraction2) {
		if (!(this->m_denominator == fraction2.m_denominator)) {
			double lcm = std::lcm(this->m_denominator, fraction2.m_denominator);

			this->m_numerator = (lcm / this->m_denominator) * this->m_numerator +
				(lcm / fraction2.m_denominator) * fraction2.m_numerator;
			this->m_denominator = lcm;
		}

		else {
			this->m_numerator += fraction2.m_numerator;
		}

		return *this;
	}

	fraction& operator-=(fraction& fraction2) {
		if (!(this->m_denominator == fraction2.m_denominator)) {
			double lcm = std::lcm(this->m_denominator, fraction2.m_denominator);

			this->m_numerator = (lcm / this->m_denominator) * this->m_numerator -
				(lcm / fraction2.m_denominator) * fraction2.m_numerator;
			this->denominator = lcm;
		}

		else {
			this->m_numerator -= fraction2.m_numerator;
		}

		return *this;
	}

	fraction& operator*=(fraction& fraction2) {
		if (!(this->m_denominator == fraction2.m_denominator)) {
			double lcm = std::lcm(this->denominator, fraction2.denominator);

			this->m_numerator = (lcm / this->m_denominator) * this->m_numerator *
				(lcm / fraction2.denominator) * fraction2.m_numerator;
			this->m_denominator = lcm;
		}

		else {
			this->m_numerator *= fraction2.m_numerator;
		}

		return *this;
	}

	fraction& operator/=(fraction& fraction2) {
		if (!(this->m_denominator == fraction2.m_denominator)) {
			double lcm = std::lcm(this->m_denominator, fraction2.m_denominator);

			this->m_numerator = (lcm / this->m_denominator) * this->m_numerator /
				(lcm / fraction2.m_denominator) * fraction2.m_numerator;
			this->m_denominator = lcm;
		}

		else {
			this->m_numerator /= fraction2.m_numerator;
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
	out << frac.m_numerator << '/' << frac.m_denominator;
	return out;
}