#include "TutorialConfig.h"
#include <cmath>
#include <iostream>

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    return EXIT_FAILURE;
  }

  // c++11 func
  const double inputValue = std::stod(argv[1]);

#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return EXIT_SUCCESS;
}
