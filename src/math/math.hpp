template<typename T, typename U>
	auto power(T base, U exponent) {
		auto powerResult{ base };
		if (exponent <= 0) {
			return 1;
		}

		for (int i{ 0 }; i < exponent; ++i) {
			powerResult *= base;
		}

		return powerResult;
	}

template<typename W>
auto square(W base) {
	return base * base;
}
