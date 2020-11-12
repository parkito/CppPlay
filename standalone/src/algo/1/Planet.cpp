#include "Planet.h"

static double G = 6.67300E-11;

double Planet::mass() const {
  switch (index) {
    case PLANET_MERCURY:
      return 3.303e+23;
    case PLANET_VENUS:
      return 4.869e+24;
    case PLANET_EARTH:
      return 5.976e+24;
      // Etc.
  }
  return 0.0;
}

double Planet::radius() const {
  // Similar to mass.
  return 0.0;
}

