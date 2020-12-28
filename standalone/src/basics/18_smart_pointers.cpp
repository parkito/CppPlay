// Using smart pointers
#include <cctype>  // For std::toupper()
#include <iostream>
#include <memory>  // For smart pointers
#include <vector>  // For std::vector<> container

class Rectangle {
  int length;
  int breadth;

public:
  Rectangle(int l, int b) {
    length = l;
    breadth = b;
  }

  int area() { return length * breadth; }
};

int main() {
  //  unique_ptr
  // When using the std::unique_ptr smart pointer, you can only assign one owner for the pointer
  // behind the wrapper. The object the std::unique_ptr points to is deleted automatically when the
  // smart pointer leaves the scope.

  //  So we can’t share with another pointer, but we can transfer the control to p2 by removing p1.

  //  The std::unique_ptr smart pointer does not have a copy constructor, so you cannot share or
  //  duplicate it – the system will throw an error, just like in the example below:
  std::unique_ptr<Rectangle> p1(new Rectangle(10, 5));
  std::cout << p1->area() << std::endl;

  //  std::unique_ptr<Rectangle> p2(p3);
  std::unique_ptr<Rectangle> p2;
  p2 = std::move(p1);

  //  shared_ptr
  //  Using the std::shared_ptr smart pointer means you can apply multiple owners to a single raw
  //  pointer. All of the owners must also leave the scope for it to be deleted.

  std::shared_ptr<Rectangle> p3(new Rectangle(10, 5));
  std::cout << p3->area() << std::endl;
  std::shared_ptr<Rectangle> p4;
  p4 = p3;
  std::cout << p4->area() << std::endl;

  std::cout << p3->area() << std::endl;

  // This'll print 2 as Reference Counter is 2
  std::cout << p3.use_count() << std::endl;

  //  weak_ptr
  //  Both std::weak_ptr and std::shared_ptr smart pointers will point to the same data. However,
  //  the std::weak_ptr one will not change the value of the internal counter and hence take part in
  //  reference counting. It is also not considered as an owner.

  //  One more reason to use std::weak_ptr for C++ memory management is that it helps with dangling
  //  pointers (those that point to deleted data). You can check if a particular piece of data is
  //  valid by using lock() or expired():

  std::shared_ptr<char> p_shared = std::make_shared<char>(15);
  std::weak_ptr<char> p_weak1(p_shared);
  std::weak_ptr<char> p_weak2(p_weak1);

  if (auto tmp = p_weak1.lock())
    std::cout << *tmp << '\n';
  else
    std::cout << "Sorry, weak1 is no longer valid!\n";

  if (auto tmp = p_weak2.lock())
    std::cout << *tmp << '\n';
  else
    std::cout << "Sorry, weak2 is is no longer valid!\n";
  return 0;
}


auto null_factory() {
  static std::weak_ptr<FILE> cache;
  auto spt = cache.lock();
  if (spt) {
    std::cout << "hit" << std::endl;
  } else {
    std::cout << "miss" << std::endl;
    spt = std::shared_ptr<FILE>{fopen("/dev/null", "w"), &fclose};
    cache = spt;
  }
  return spt;
}
