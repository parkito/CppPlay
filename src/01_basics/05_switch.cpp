#include <iostream>
#include <MacTypes.h>
#include <vector>

using namespace std;

void action() {
    while (true) {
        cout << "enter action:\n";
        string act;
        cin >> act;
        Point delta{0, 0};

        for (char ch : act) {
            switch (ch) {
                case 'u': // up case 'n': // nor th
                    ++delta.h;
                    break;
                case 'r': // right case 'e': // east
                    ++delta.v;
                    break;
// ... more actions ...
                default:
                    cout << "I freeze!\n";
            }
        }
    }
}

void do_something(vector<int> &v) {
    if (auto n = v.size()) {
// ... we get here if n!=0 ...
    }
}