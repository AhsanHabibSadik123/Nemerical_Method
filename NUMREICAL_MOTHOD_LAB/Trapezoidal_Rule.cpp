#include<bits/stdc++.h>
using namespace std;

double functionValue(double x){
    return 1 / (1 + x);
}

double trapezoidalRule(double a , double b , int n){

    double sum = functionValue(a) + functionValue(b);
    double h = (b - a) / n;
    for(int i = 1; i < n; i++){
        sum += 2 * functionValue(a + i * h);
    }
    return (h / 2) * sum;
}

int main(){     
    double a , b;
    int n;
    cout << "Lower limit " << endl;
    cin >> a;
    cout << "Upper limit " << endl;
    cin >> b;
    cout << "Number of step " << endl;
    cin >> n;


    cout << "Approximate value = " << trapezoidalRule(a , b , n);
}
