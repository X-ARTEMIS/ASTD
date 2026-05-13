auto power(auto base, auto exponent) {
	auto powerResult{ base };

	if (exponent <= 0) {
		return 1;
	}

	for (int i{ 0 }; i < exponent; ++i) {
		powerResult *= base;
	}

	return powerResult;
}

auto square(auto base) {
	return base * base;
}

bool getNumType(auto num) {
	// True for even, false for odd

	if (num % 2 == 0) {
		return true;
	}

	else {
		return false;
	}
}
