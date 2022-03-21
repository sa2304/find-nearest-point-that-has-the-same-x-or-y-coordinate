#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
 public:
  struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
      return tie(x, y) == tie(other.x, other.y);
    }
  };

  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    vector<Point> sorted;
    for (const auto& p: points) {
      sorted.push_back({ p[0], p[1] });
    }
    auto comp = [x, y](const Point& lhs, const Point& rhs) {
      const int d1 = abs(lhs.x - x) + abs(lhs.y - y);
      const int d2 = abs(rhs.x - x) + abs(rhs.y - y);
      return d1 < d2;
    };
    sort(sorted.begin(), sorted.end(), comp);
    auto iter = find_if(sorted.begin(), sorted.end(), [x, y](const Point& p) {
      return p.x == x || p.y == y;
    });
    if (sorted.end() != iter) {
      const Point& found = *iter;
      for (int i = 0; i < points.size(); ++i) {
        const auto& p = points[i];
        if (found == Point{p[0], p[1]}) {
          return i;
        }
      }
    }

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
