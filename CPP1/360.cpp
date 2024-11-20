#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate the Euclidean distance between two points
double get_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int N;
    double S, T;
    cin >> N >> S >> T;
    
    vector<pair<pair<double, double>, pair<double, double>>> segments(N);
    
    // Reading the input for the segments
    for (int i = 0; i < N; ++i) {
        double A, B, C, D;
        cin >> A >> B >> C >> D;
        segments[i] = {{A, B}, {C, D}};
    }

    // Track current laser position, starting at (0, 0)
    double current_x = 0, current_y = 0;
    double total_time = 0;

    // Process each segment
    for (int i = 0; i < N; ++i) {
        double A = segments[i].first.first;
        double B = segments[i].first.second;
        double C = segments[i].second.first;
        double D = segments[i].second.second;

        // Calculate the distances
        double move_to_start = get_distance(current_x, current_y, A, B);
        double segment_length = get_distance(A, B, C, D);
        
        // Time to move to the starting point of the segment
        total_time += move_to_start / S;
        
        // Time to print the segment
        total_time += segment_length / T;
        
        // Update the laser position to the end of the segment
        current_x = C;
        current_y = D;
    }

    // Output the total minimum time required
    cout.precision(10);
    cout << total_time << endl;

    return 0;
}
