#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    // FIXME
    return -1;
  }
};

void TestNearestValidPoint() {
  Solution s;
  {
    vector<vector<int>> points{{1,2},{3,1},{2,4},{2,3},{4,4}};
    assert(2 == s.nearestValidPoint(3, 4, points));
  }
  {
    vector<vector<int>> points{{3,4}};
    assert(0 == s.nearestValidPoint(3, 4, points));
  }
  {
    vector<vector<int>> points{{2,3}};
    assert(-1 == s.nearestValidPoint(3, 4, points));
  }
}

int main() {
  TestNearestValidPoint();
  std::cout << "Ok!" << std::endl;
  return 0;
}
