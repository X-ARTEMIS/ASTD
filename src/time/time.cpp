#include <chrono>

namespace astd {
	auto getSystemTime(bool local) {
		if (local) {
			return std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		}

		else {
			return std::chrono::system_clock::now();
		}
	}

	auto getSystemTrimmedTime(bool local) {
		if (local) {
			return std::chrono::current_zone()->to_local(std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now()));
		}

		else {
			return std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
		}
	}
}
