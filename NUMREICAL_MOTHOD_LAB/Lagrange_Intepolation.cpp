#include<bits/stdc++.h>
using namespace std;

vector<double> x_value , y_value;

double lagrangeInterpolation(int value , int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        double temp = y_value[i];
        for(int j = 0; j < n; j++){
            if(i != j){
                temp *= (value - x_value[j]) / (x_value[i] - x_value[j]);
            }
        }
        sum += temp;
    }
    return sum;
}

int main(){

    int n;
    cin >> n;

    x_value = vector<double>(n);
    y_value = vector<double>(n);

    for(int i = 0; i < n; i++){
        cin >> x_value[i];
    }

    for(int i = 0; i < n; i++){
        cin >> y_value[i];
    }

    int value;
    cin >> value;

    cout << "Value at " << value << " is " << lagrangeInterpolation(value , n) << endl;
    
}
