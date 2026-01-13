class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l =1e9 , h=0;
        double t = 0;
        for (auto &s : squares) {
            l = min(l,(double)s[1]); 
            h = max(h,(double)(s[1] + s[2]));
            t += (double)s[2] * s[2];
        }
        
        while (h - l > 1e-5) {
            double mid = (l + h) / 2;
            double below = computeBelowArea(squares, mid);

            if (below < t / 2.0) {
                l = mid;  
            } else {
                h = mid; 
            }
        }

        return l;
    }

private:
    double computeBelowArea(vector<vector<int>>& squares, double y) {
        double area = 0;
        for (auto &square : squares) {
            double y1 = square[1], y2 = square[1] + square[2];

            if (y > y1) {  
                double intersectHeight = min(y2, y) - y1;
                area += square[2] * intersectHeight;
            }
        }
        return area;
    }
};