#include "TutorialConfig.h"
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    return EXIT_FAILURE;
  }

  // c++11 func
  const double inputValue = std::stod(argv[1]);

  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return EXIT_SUCCESS;
}
