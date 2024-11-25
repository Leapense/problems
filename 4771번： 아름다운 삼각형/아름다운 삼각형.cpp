#include <bits/stdc++.h>
using namespace std;

const double EPS_AREA = 1e-6;
const double EPS_SIDE = 1e-3;

// Function to compare two doubles with a given epsilon
bool isEqual(double a, double b, double eps) {
    return fabs(a - b) < eps;
}

// Function to compute distance between two points
double distanceBetween(double x1, double y1, double x2, double y2){
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double x1, y1, x2, y2, x3, y3;
    
    while(cin >> x1){
        if(isEqual(x1, -1.0, EPS_AREA)){
            break;
        }
        // Read the remaining five tokens
        if(!(cin >> y1 >> x2 >> y2 >> x3 >> y3)){
            // Incomplete input, exit
            break;
        }
        
        // Compute side lengths
        double a = distanceBetween(x2, y2, x3, y3);
        double b = distanceBetween(x1, y1, x3, y3);
        double c = distanceBetween(x1, y1, x2, y2);
        
        // Compute area using cross product
        double area = fabs( (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1) ) / 2.0;
        
        if(area <= EPS_AREA){
            cout << "Not a Triangle\n";
            continue;
        }
        
        // Classify by sides
        string sideClass;
        bool ab = isEqual(a, b, EPS_SIDE);
        bool bc = isEqual(b, c, EPS_SIDE);
        bool ac = isEqual(a, c, EPS_SIDE);
        
        if(ab && bc){
            sideClass = "Equilateral";
        }
        else if(ab || bc || ac){
            sideClass = "Isosceles";
        }
        else{
            sideClass = "Scalene";
        }
        
        // Classify by angles
        string angleClass;
        if(sideClass == "Equilateral"){
            angleClass = "Acute";
        }
        else{
            // Sort sides in ascending order
            vector<double> sides = {a, b, c};
            sort(sides.begin(), sides.end());
            double s1 = sides[0];
            double s2 = sides[1];
            double s3 = sides[2];
            
            // Compute squares
            double s1_sq = s1 * s1;
            double s2_sq = s2 * s2;
            double s3_sq = s3 * s3;
            
            // Compare using epsilon
            if(isEqual(s1_sq + s2_sq, s3_sq, 1e-3)){
                angleClass = "Right";
            }
            else if((s1_sq + s2_sq) > s3_sq + 1e-3){
                angleClass = "Acute";
            }
            else{
                angleClass = "Obtuse";
            }
        }
        
        // Output the classification
        cout << sideClass << " " << angleClass << "\n";
    }
}