#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Represents a 2D point
struct Point {
    double x;
    double y;
};

// Distance function to calculate the Euclidean distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

vector<Point> findNearestNeighbors(const vector<Point>& points, const Point& query, int k) {
    vector<pair<Point, double>> neighbors;

    // Calculate the distance from the query point to every other point and store in a vector
    for (const Point& point : points) {
        double dist = distance(query, point);
        neighbors.emplace_back(point, dist);
    }

    // Sort the neighbors in ascending order based on distance
    sort(neighbors.begin(), neighbors.end(), [](const pair<Point, double>& a, const pair<Point, double>& b) {
        return a.second < b.second;
        });

    // Return the first 'k' neighbors
    vector<Point> result;
    for (int i = 0; i < min(k, int(neighbors.size())); i++) {
        result.push_back(neighbors[i].first);
    }
    return result;
}

int main() {
    vector<Point> points = {
        {1.0, 1.0}, {3.0, 9.0}, {5.0, 25.0}, {7.0, 49.0}, {9.0, 81.0},
        {2.0, 4.0}, {4.0, 16.0}, {6.0, 36.0}, {8.0, 64.0}, {10.0, 100.0}
    };

    int k = 3;
    Point query = { 6.5, 42.25 };

    vector<Point> nearestNeighbors = findNearestNeighbors(points, query, k);

    cout << "Nearest " << k << " neighbors of (" << query.x << ", " << query.y << "):" << endl;
    for (const Point& neighbor : nearestNeighbors) {
        cout << "(" << neighbor.x << ", " << neighbor.y << ")" << endl;
    }
    return 0;
}
