#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Point struct
struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

bool inRange(const Point& p, int minX, int minY, int maxX, int maxY) {
    return p.x >= minX && p.x <= maxX && p.y >= minY && p.y <= maxY;
}

// Non-optimal strategy: Linear search
vector<Point> findPointsInRangeLinear(const vector<Point>& points, int minX, int minY, int maxX, int maxY) {
    vector<Point> result;
    for (const Point& p : points) {
        if (inRange(p, minX, minY, maxX, maxY)) {
            result.push_back(p);
        }
    }
    return result;
}
int main() {
    // Generate random points
    const int numPoints = 10000;
    vector<Point> points;
    for (int i = 0; i < numPoints; i++) {
        points.push_back(Point(rand() % 10000, rand() % 10000));
    }

    // Test range
    int minX = 3000;
    int minY = 4000;
    int maxX = 6000;
    int maxY = 7000;

    vector<Point> inRangePoints = findPointsInRangeLinear(points, minX, minY, maxX, maxY);

    cout << "Number of points in range: " << inRangePoints.size() << endl;

    return 0;
}
