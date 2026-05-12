#pragma once

#include <chrono>
namespace astd {
  auto getSystemTime(bool local = false);
  auto getSystemTrimmedTime(bool local = false);
}

// there is a special one for trimmed and non trimmed as trimming changes return types (probably a better way to do it like making it a string but I want it to retain usefulness as the time point datatype.)
