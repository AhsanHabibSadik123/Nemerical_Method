#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

class NewtonDividedDifferrence{
private:
    vector<double>x_value;
    vector<vector<double>>y_value;
    double value , n;
public:
    NewtonDividedDifferrence(vector<double>xx , vector<vector<double>>yy , double val , double na){
        n = na;
        x_value = xx;
        y_value = yy;
        value = val;
    }

    void constructDifferenceTable(){
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n - i; j++){
                y_value[j][i] = (y_value[j+1][i-1] - y_value[j][i-1]) / (x_value[j + i] - x_value[j]);
            }
        }
    }

    double xTarm(int n){
        double ans = 1;
        for(int i = 0; i < n; i++){
            ans *= (value - x_value[i]);
        }
        return ans;
    }

    double solution(){
        double sum = y_value[0][0];
        for(int i = 1; i < n; i++){
            sum += xTarm(i) * y_value[0][i];
        }
        return sum;
    }

};

int main(){     
    double n;
    cin >> n;
    vector<double>x_value(n);
    vector<vector<double>>y_value(n , vector<double>(n));
    for(int i = 0; i < n; i++){
        cin >> x_value[i] >> y_value[i][0];
    }
    double value;
    cin >> value;

    NewtonDividedDifferrence interpolator(x_value , y_value , value , n);
    interpolator.constructDifferenceTable();
    cout << "Value at " << value << " is = " << interpolator.solution();
}

/*
input : 

6
4 48
5 100
7 294
10 900
11 1210
13 2028
8

output :
448
*/