#include <iostream>
#include <utility>
struct Expression {

  explicit Expression(std::string data_) : data(data_) {}

  ~Expression() { std::cout << "Destructor"; }

  std::string data;
};
struct Number;
struct BinaryOperation;

struct SharedPtr {

  explicit SharedPtr(Expression *ptr = nullptr) : ptr_(ptr) {
    if (ptr_) {
      refCounter = new int(1);
    }
  }

  ~SharedPtr() {
    if (refCounter && --*refCounter == 0) {
      delete ptr_;
      delete refCounter;
    }
  }

  SharedPtr(const SharedPtr &ptr) : ptr_(ptr.ptr_), refCounter(ptr.refCounter) {
    if (refCounter) {
      *refCounter++;
    }
  }

  SharedPtr &operator=(const SharedPtr &ptr) {
    if (this != &ptr) {
      clearThis();
      ptr_ = ptr.ptr_;
      refCounter = ptr.refCounter;
      *refCounter++;
    }
    return *this;
  }

  Expression *get() const { return ptr_; }

  void reset(Expression *ptr = nullptr) {
    clearThis();
    if (ptr) {
      ptr_ = ptr;
      refCounter = new int(1);
    }
  }
  Expression &operator*() const { return *ptr_; }

  Expression *operator->() const { return ptr_; }

  Expression *ptr_;
  int *refCounter;

private:
  void clearThis() const {
    if (refCounter && --*refCounter == 0) {
      delete ptr_;
      delete refCounter;
    }
  }
};

template <class T> void assert(T expected, T actual) {
  std::cout << "Expected = " << expected << " Actual = " << actual << std::endl;
  if (expected != actual) {
    throw std::runtime_error("Assertion has not passed");
  }
}

void test1_simple_create() {
  Expression ex{"daaa"};
  SharedPtr p1{&ex};

  //  assert(1, *p1.refCounter);
}

int main() { test1_simple_create(); }