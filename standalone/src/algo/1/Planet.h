#pragma once

class Planet {
  int index;

public:
  static constexpr int length() { return 8; }
  Planet() : index(0) {}
  constexpr explicit Planet(int index) : index(index) {}
  constexpr operator int() const { return index; }

  double mass() const;
  double radius() const;

  double surfaceGravity() const;
};

constexpr Planet PLANET_MERCURY(0);
constexpr Planet PLANET_VENUS(1);
constexpr Planet PLANET_EARTH(2);