#include "iostream"
#include "vector"

using namespace std;

int compare(const int &a, const int &b) {
  if (a > b) {
    return 1;
  } else if (a < b) {
    return -1;
  } else {
    return 0;
  }
}

// Complete the compareTriplets function below.
vector<int> compareTriplets(vector<int> a, vector<int> b) {
  int aliceRes = 0;a.size()
  int bobRes = 0;
  for (int i = 0; i < 3; i++) {
    int compRes = compare(a[i], b[i]);
    if (compRes > 0) {
      aliceRes++;
    } else if (compRes < 0) {
      bobRes++;
    }
  }
  return  {aliceRes, bobRes};
}
