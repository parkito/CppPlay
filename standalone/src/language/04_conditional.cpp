#include <iostream>
#include <vector>

using namespace std;

void action() {
  cout << "enter action:\n";
  string act;
  cin >> act;
  int delta = 0;

  if (int a = 0; a > 0) {
    cout << "Greater than 0";
  } else {
    cout << "Less than 0";
  }

  for (char ch : act) {
    switch (ch) {
    case 'u': // up case 'n': // nor th
      ++delta;
      break;
    case 'r': // right case 'e': // east
      --delta;
      break;
      // ... more actions ...
    default:
      cout << "I freeze!\n";
    }
  }
}

void do_something(vector<int> &v) {
  if (auto n = v.size()) {
    // ... we get here if n!=0 ...
  }
}