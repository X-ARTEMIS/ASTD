#pragma once

#include <chrono>

auto getSystemTime();
auto getSystemTrimmedTime();

// there is a special one for trimmed and non trimmed as trimming changes return types (probably a better way to do it like making it a string but I'm too tired for that and want it to retain usefulness as the time point datatype.)
