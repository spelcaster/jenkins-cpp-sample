#include "SquareRoot.hpp"

#include <cmath>

SquareRoot::SquareRoot () {
  number = 0.0;
}

SquareRoot::~SquareRoot () {
}

void SquareRoot::setNumber (const double value) {
  number = value;
}

double SquareRoot::getNumber () {
  return number;
}

double SquareRoot::calculate () {
  if (number < 0.0) {
      return -1;
  }

  return std::sqrt(number);
}
