#include <list>

#include "iostream"

class Point {
public:
  Point(int x, int y) : x{x}, y{y} {}
  int GetX() { return x; }
  int GetY() { return y; }

private:
  int x;
  int y;
};

class Figure {
public:
  virtual Point center() const = 0;
  virtual std::string signs() = 0;
  virtual void add() = 0;
  virtual void draw() {
    std::cout << signs() << "(" << center().GetX() << ";" << center().GetX() << ")" << std::endl;
  }

  virtual ~Figure() = default;
};

class Circle : public Figure {
public:
  Circle() { signSyms = "*"; }
  Point center() const override { return Point{1, 1}; }
  std::string signs() override { return std::string(); }
  void add() override { signSyms += signSyms; }
  ~Circle() override = default;

private:
  std::string signSyms;
};

class Square : public Figure {
public:
  Square() { signSyms = "#"; }
  Point center() const override { return Point{3, 3}; }
  std::string signs() override { return std::string(); }
  void add() override { signSyms += signSyms; }
  ~Square() override = default;

private:
  std::string signSyms;
};

int main() {
  Circle *fig1 = new Circle();
  Square *fig2 = new Square();

  auto list = new std::list<Figure *>;
  list->push_back(fig1);
  list->push_back(fig2);

  for (auto &el : *list) {
    el->draw();
  }

  return 0;
};
