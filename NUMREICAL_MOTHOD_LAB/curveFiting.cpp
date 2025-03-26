#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class CurveFitting {
private:
    vector<double> x;
    vector<double> y;

public:
    CurveFitting(const vector<double>& xVals , const vector<double>& yVals) {
        if (xVals.size() != yVals.size()) {
            throw invalid_argument("Input data must have the same size.");
        }
        x = xVals;
        y = yVals;
    }
    void fitLinear(double& m, double& c) {
        int n = x.size();
        double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
        for (int i = 0; i < n; i++) {
            sumX += x[i];
            sumY += y[i];
            sumXY += x[i] * y[i];
            sumXX += x[i] * x[i];
        }
        m = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
        c = (sumY - m * sumX) / n;
    }
    double predict(double xVal, double m, double c) {
        return m * xVal + c;
    }
};

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 5, 4, 5};
    try {
        CurveFitting curveFitting(x, y);
        double m, c;
        curveFitting.fitLinear(m, c);
        cout << "Fitted line: y = " << m << "x + " << c << endl;
        double xPredict = 6;
        double yPredict = curveFitting.predict(xPredict, m, c);
        cout << "Predicted value at x = " << xPredict << " is y = " << yPredict << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
