auto power(const auto base, const auto exponent) {
	auto powerResult{ 1 };

	if (exponent <= 0) {
		return 1;
	}

	for (int i{ 0 }; i < exponent; ++i) {
		powerResult *= base;
	}

	return powerResult;
}

auto square(const auto base) {
	return base * base;
}

bool getNumType(const auto num) {
	// True for even, false for odd

	if (num % 2 == 0) {
		return true;
	}

	else {
		return false;
	}
}
