#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int min_distance = INT32_MAX;
    int index = -1;
    for (int i = 0; i < points.size(); ++i) {
      const auto& p = points[i];
      if (p[0] == x || p[1] == y) {
        int d = abs(p[0] - x) + abs(p[1] - y);
        if (d < min_distance) {
          index = i;
          min_distance = d;
        }
      }
    }

    return index;
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
