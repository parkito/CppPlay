#include <iostream>
#include <utility>
struct Expression {

  explicit Expression(std::string data_) : data(data_) {}

  std::string data;
};
struct Number;
struct BinaryOperation;

struct SharedPtr {

  explicit SharedPtr(Expression *ptr = nullptr)
      : ptr_(ptr), refCounter(nullptr) {
    if (ptr_) {
      refCounter = new int(1);
    }
  }

  ~SharedPtr(){ clearThis(); }

  SharedPtr(const SharedPtr &ptr)
      : ptr_(ptr.ptr_),
  refCounter(ptr.refCounter) {
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

template <class T> void assertNull(T *actual) {
  std::cout << "Expected = nullptr"
            << " Actual = ";
  if (actual == nullptr) {
    std::cout << "nullptr" << std::endl;
  } else {
    std::cout << actual << std::endl;
  }

  if (actual != nullptr) {
    throw std::runtime_error("Assertion has not passed");
  }
}

void test1_simple_create() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  auto *ex = new Expression{"daaa"};
  SharedPtr p1{ex};
  assert(1, *p1.refCounter);
  assert(std::string("daaa"), p1.ptr_->data);
}

void test2_simple_create_null() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  SharedPtr p1{nullptr};
  assertNull(p1.refCounter);
  assertNull(p1.ptr_);
}

int main() {
  test1_simple_create();
  test2_simple_create_null();
}