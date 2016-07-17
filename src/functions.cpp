#include "functions.hpp"

#include <iostream>
#include <cmath>

double square_root (double number) {
  if (number < 0.0) {
      return -1;
  }

  return std::sqrt(number);
}
