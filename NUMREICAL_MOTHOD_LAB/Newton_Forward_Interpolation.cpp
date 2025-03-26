#include<bits/stdc++.h>
using namespace std;

class NewtonForwardInterpolation{
private:
    int n;
    vector<double>x_value;
    vector<vector<double>>y_value;
public:
    NewtonForwardInterpolation(vector<double>x , vector<vector<double>>y , int sz){
        n = sz;
        x_value = x;
        y_value = y;
    }

    void constructDifferenceTable(){
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n - i; j++){
                y_value[j][i] = y_value[j+1][i-1] - y_value[j][i-1];
            }
        } 
    }

    double factorial(int n){
        double fact = 1;
        for(int i = 2; i <= n; i++){
            fact *= i;
        }
        return fact;
    }

    double pValue(double p , int n){
        double res = 1;
        for(int i = 0; i < n; i++){
            res *= (p - i);
        }
        return res;
    }

    double solve(double value){
        double p = (value - x_value[0]) / (x_value[1] - x_value[0]);
        double ans = y_value[0][0];
        for(int i = 1; i < n; i++){
            ans += (pValue(p , i) * y_value[0][i]) / factorial(i);
        }
        return ans;
    }

};

int main(){     
    
    int n;
    cin >> n;

    vector<double>x_value(n);
    vector<vector<double>>y_value(n , vector<double>(n));

    for(int i = 0; i < n; i++){
        cin >> x_value[i];
    }

    for(int i = 0; i < n; i++){
        cin >> y_value[i][0];
    }
    int value;
    cin >> value;

    NewtonForwardInterpolation interpolator(x_value , y_value , n);
    interpolator.constructDifferenceTable();
    cout << "Value at " << value << " = " << interpolator.solve(value);
}
