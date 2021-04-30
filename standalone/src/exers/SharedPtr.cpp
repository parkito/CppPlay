#include <iostream>
#include <utility>
struct Expression {

  explicit Expression(std::string data_) : data(std::move(data_)) {}

  std::string data;
};
struct Number;
struct BinaryOperation;

struct SharePtrContext {
  explicit SharePtrContext(Expression *ptr) : ptr_(ptr), refCounter(1) {}

  ~SharePtrContext() { delete ptr_; }

  Expression *ptr_;
  int refCounter;
};

struct SharedPtr {

  explicit SharedPtr(Expression *ptr = nullptr) {
    if (ptr != nullptr) {
      context = new SharePtrContext(ptr);
    }
  }

  ~SharedPtr() {
    if (--context->refCounter == 0) {
      delete context;
    }
  }

  SharedPtr(const SharedPtr &ptr) {
    if (ptr.context->refCounter > 0) {
      context = ptr.context;
      context->refCounter++;
    }
  }

  SharedPtr &operator=(const SharedPtr &ptr) {
    if (this != &ptr) {
      if (--context->refCounter == 0) {
        delete context;
      }
      context = ptr.context;
      context->refCounter++;
    }
    return *this;
  }

  Expression *get() const { return context->ptr_; }

  void reset(Expression *ptr = nullptr) {
    if (context->refCounter == 0) {
      delete context;
      context = new SharePtrContext(ptr);
    }
  }
  Expression &operator*() const { return *context->ptr_; }

  Expression *operator->() const { return context->ptr_; }

private:
  SharePtrContext *context = nullptr;
};

int main() {
  Expression ex{"daaa"};
  SharedPtr p2;

  {
    SharedPtr p1{&ex};
    SharedPtr p3{p1};
    p2 = p3;
    std::cout << p3.refCounter << std::endl;
  }
  std::cout << p2->data << std::endl;
  std::cout << p2.refCounter << std::endl;
}